#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/Constants.h"
#include "../include/Player.h"
#include "../include/Pipe.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Flappy Bird");

    window.setKeyRepeatEnabled(false);

    Player player;

    Pipe pipe;

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
        pipe.update(elapsed.asSeconds());

        //render
        window.clear(sf::Color::Cyan);

        player.draw(window);
        pipe.draw(window);

        window.display();
    }

}