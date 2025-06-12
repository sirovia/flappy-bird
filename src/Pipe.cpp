//
// Created by alimu on 6/12/2025.
//

#include "../include/Pipe.h"

#include "../include/Constants.h"

Pipe::Pipe()
    : upperPipe(sf::Vector2f(80.f, 500.f)),
      lowerPipe(sf::Vector2f(80.f, 500.f)),
      position(0.f),
      speed(400.f) {
    upperPipe.setFillColor(sf::Color::Green);
    lowerPipe.setFillColor(sf::Color::Green);
    upperPipe.setOutlineColor(sf::Color::Black);
    lowerPipe.setOutlineColor(sf::Color::Black);
    upperPipe.setOutlineThickness(1);
    lowerPipe.setOutlineThickness(1);
    reset();
}

void Pipe::update(const float &dt) {
    upperPipe.move({-speed * dt, 0.f});
    lowerPipe.move({-speed * dt, 0.f});
    if (upperPipe.getPosition().x < -80.f) reset();
}

void Pipe::draw(sf::RenderWindow &window) const {
    window.draw(upperPipe);
    window.draw(lowerPipe);
}

void Pipe::reset() {
    position = randY(WINDOW_HEIGHT, 100.f);
    upperPipe.setPosition({800.f, position - 600.f});
    lowerPipe.setPosition({800.f, position + 100.f});
}

bool Pipe::intersects(const sf::FloatRect rect) const {
    return (upperPipe.getGlobalBounds().findIntersection(rect) != std::nullopt ||
        lowerPipe.getGlobalBounds().findIntersection(rect) != std::nullopt);
}

float Pipe::randY(const float windowHeight, const float gapHeight, const float minMargin) {
    static std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<float> dist(minMargin, windowHeight - gapHeight - minMargin);
    return dist(rng);
}


