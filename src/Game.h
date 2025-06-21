//
// Created by alimu on 6/14/2025.
//

#ifndef GAME_H
#define GAME_H
#include "Pipe.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

#include "Scene.h"

inline constexpr unsigned int WINDOW_WIDTH = 800;
inline constexpr unsigned int WINDOW_HEIGHT = 600;


class Game {
public:
    Game();
    void run();

private:
    void handleEvents();
    void update(float& dt) const;
    void render();

    sf::RenderWindow window;

    bool active = false;

    std::unique_ptr<Scene> currentScene;
    void switchToMenu();
    void switchToGame();
};



#endif //GAME_H
