//
// Created by alimu on 6/12/2025.
//

#include "Pipe.h"

Pipe::Pipe()
    : upperPipe(sf::Vector2f(80.f, 500.f)),
      lowerPipe(sf::Vector2f(80.f, 500.f)),
      m_shape({5.f, 600.f}),
      position(0.f),
      speed(300.f) {
    upperPipe.setFillColor(sf::Color::Green);
    lowerPipe.setFillColor(sf::Color::Green);
    upperPipe.setOutlineColor(sf::Color::Black);
    lowerPipe.setOutlineColor(sf::Color::Black);
    upperPipe.setOutlineThickness(1);
    lowerPipe.setOutlineThickness(1);
    m_shape.setFillColor(sf::Color(0, 0, 0, 0));
    reset();
}

void Pipe::update(const float &dt) {
    upperPipe.move({-speed * dt, 0.f});
    lowerPipe.move({-speed * dt, 0.f});
    m_shape.move({-speed * dt, 0.f});
    if (upperPipe.getPosition().x < -80.f) reset();
}

void Pipe::draw(sf::RenderWindow &window) const {
    window.draw(upperPipe);
    window.draw(lowerPipe);
}

void Pipe::reset() {
    position = randY(600.f, 100.f);
    upperPipe.setPosition({800.f, position - 600.f});
    lowerPipe.setPosition({800.f, position + 100.f});
    m_shape.setPosition({860.f, 0.f});
}

bool Pipe::intersects(const sf::FloatRect& rect) const {
    return (upperPipe.getGlobalBounds().findIntersection(rect) != std::nullopt ||
        lowerPipe.getGlobalBounds().findIntersection(rect) != std::nullopt);
}

bool Pipe::passed(const sf::FloatRect& rect) {
    if (m_shape.getGlobalBounds().findIntersection(rect) != std::nullopt) {
        m_shape.move({0.f, 600.f});
        return true;
    }
    return false;
}

float Pipe::randY(const float windowHeight, const float gapHeight, const float minMargin) {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<float> dist(minMargin, windowHeight - gapHeight - minMargin);
    return dist(rng);
}


