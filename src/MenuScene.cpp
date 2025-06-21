//
// Created by alimu on 6/15/2025.
//

#include "MenuScene.h"

#include <iostream>

MenuScene::MenuScene(const sf::RenderWindow &window, const std::function<void()> &onstart)
    : font("../../assets/fonts/PS2P/PS2P.ttf"),
      title(font),
      startText(font),
      onStartCallBack(onstart)
{
    title.setFont(font);
    title.setString("Flappy Bird");
    title.setCharacterSize(40);
    title.setFillColor(sf::Color::Yellow);
    title.setOutlineColor(sf::Color::Black);
    title.setOutlineThickness(2.f);
    title.setPosition({window.getSize().x / 2.f - title.getLocalBounds().size.x / 2.f, 100.f});

    startText.setFont(font);
    startText.setString("Start");
    startText.setCharacterSize(20);
    startText.setFillColor(sf::Color::Black);

    startButton.setSize({200.f, 60.f});
    startButton.setFillColor(sf::Color::White);
    startButton.setPosition({window.getSize().x / 2.f - 100.f, 300.f});

    startText.setPosition({
        startButton.getPosition().x + startButton.getSize().x / 2.f - startText.getLocalBounds().size.x / 2.f,
        startButton.getPosition().y + startButton.getSize().y / 2.f - startText.getLocalBounds().size.y / 2.f
    });

}

void MenuScene::handleEvent(const std::optional<sf::Event>& event) {
    if (const auto* mouse = event->getIf<sf::Event::MouseButtonPressed>()) {
        if (mouse->button == sf::Mouse::Button::Left &&
          startButton.getGlobalBounds().contains(sf::Vector2<float>(mouse->position))) {
            onStartCallBack();
        }
    }
    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Space) {
            onStartCallBack();
        }
    }
}

void MenuScene::update(const float& dt) {

}

void MenuScene::render(sf::RenderWindow& window) {
    window.draw(startButton);
    window.draw(startText);
    window.draw(title);
}


