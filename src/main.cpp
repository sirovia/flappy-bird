#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/Player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Flappy Bird");

    window.setKeyRepeatEnabled(false);

    Player player;

    sf::Clock clock;

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    window.close();
                }
                if (keyPressed->scancode == sf::Keyboard::Scancode::Space) {
                    player.flap();
                }
            }
        }

        sf::Time elapsed = clock.restart();

        player.update(elapsed.asSeconds());

        //render
        window.clear(sf::Color::Cyan);

        player.draw(window);

        window.display();
    }

}