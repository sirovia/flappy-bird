//
// Created by alimu on 6/14/2025.
//

#include "Game.h"

#include "GameScene.h"
#include "MenuScene.h"

Game::Game()
    : window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Flappy Bird"){
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    switchToMenu();
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        handleEvents();

        float dt = clock.restart().asSeconds();

        update(dt);

        render();
    }
}

void Game::handleEvents() {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                switchToMenu();
            }
        }
        currentScene->handleEvent(event);
    }
}

void Game::update(float& dt) const {
    currentScene->update(dt);
}

void Game::render() {
    window.clear(sf::Color::Cyan);

    currentScene->render(window);

    window.display();
}

void Game::switchToGame() {
    currentScene = std::make_unique<GameScene>(window, [&]() {
        switchToMenu();
    });
}

void Game::switchToMenu() {
    currentScene = std::make_unique<MenuScene>(window, [&]() {
        switchToGame();
    });
}

