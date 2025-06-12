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

    bool active = false;

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
                    if (!active) {
                        active = true;
                        player.reset();
                        pipe.reset();
                    }
                    player.flap();
                }
            }
        }

        sf::Time elapsed = clock.restart();

        if (!active) elapsed = sf::Time::Zero;

        player.update(elapsed.asSeconds());
        pipe.update(elapsed.asSeconds());

        if (pipe.intersects(player.getBounds())) {
            active = false;
        }

        if (player.getPos() >= WINDOW_HEIGHT - 20.f) {
            active = false;
        }

        if (player.getPos() <= 20.f) {
            active = false;
        }

        //render
        window.clear(sf::Color::Cyan);

        player.draw(window);
        pipe.draw(window);

        window.display();
    }

}