//
// Created by alimu on 6/14/2025.
//

#include "Game.h"

Game::Game()
    : window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Flappy Bird"){
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    pipes.reserve(4);
    pipes.emplace_back();
}

void Game::run() {
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
                window.close();
            }
            if (keyPressed->scancode == sf::Keyboard::Scancode::Space) {
                if (!active) {
                    active = true;
                    player.reset();
                    pipes[0].reset();
                }
                player.flap();
            }
        }
    }
}

void Game::update(float& dt) {
    if (!active)
        dt = 0.f;
    player.update(dt);
    for (Pipe& pipe : pipes) {
        pipe.update(dt);
        if (pipe.intersects(player.getBounds())) {
            active = false;
        }

        if (pipe.passed(player.getBounds())) {
            player.points ++;
        }
    }
    if (player.getPos() >= WINDOW_HEIGHT - 20.f) {
        active = false;
    }

    if (player.getPos() <= 20.f) {
        active = false;
    }
}

void Game::render() {
    window.clear(sf::Color::Cyan);

    player.draw(window);
    for (Pipe& pipe : pipes) {
        pipe.draw(window);
    }
    ui.showScore(window, player.points);
    if (!active)
        ui.showMessage(window, "Press SPACE to start");
    window.display();
}

