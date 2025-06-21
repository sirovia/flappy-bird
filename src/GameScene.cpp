//
// Created by alimu on 6/17/2025.
//

#include "GameScene.h"

#include "Game.h"

GameScene::GameScene(const sf::RenderWindow &window, const std::function<void()> &onstart)
    : font("../../assets/fonts/PS2P/PS2P.ttf"),
      scoreText(font),
      callBack(onstart)
{

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setOutlineColor(sf::Color::Black);
    scoreText.setOutlineThickness(2);
    scoreText.setPosition({20.f, 20.f});

    pipes.reserve(4);
    pipes.emplace_back();
}

void GameScene::handleEvent(const std::optional<sf::Event>& event) {
    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
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

void GameScene::update(const float& dt) {
    if (!active) return;
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

void GameScene::render(sf::RenderWindow &window) {
    player.draw(window);
    for (Pipe& pipe : pipes) {
        pipe.draw(window);
    }
    scoreText.setString("Score: " + std::to_string(player.points));
    window.draw(scoreText);
}


