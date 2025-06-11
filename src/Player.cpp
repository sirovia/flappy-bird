//
// Created by alimu on 6/10/2025.
//

#include "../include/Player.h"

Player::Player() : m_shape(20.f), y(0.f), verticalSpeed(0.f) {
    m_shape.setFillColor(sf::Color::Yellow);
    m_shape.setOrigin({20.f ,20.f});
    m_shape.setPosition(sf::Vector2f(300, 300));
    m_shape.setOutlineColor(sf::Color::Black);
    m_shape.setOutlineThickness(1);
}

void Player::flap() {
    verticalSpeed = flapS;
}

void Player::update(const float dt) {
    verticalSpeed += gravity * dt;
    m_shape.move({0.f, verticalSpeed * dt});
}

void Player::draw(sf::RenderWindow &window) const{
    window.draw(m_shape);
}

float Player::getPos() const {
    return m_shape.getPosition().y;
}




