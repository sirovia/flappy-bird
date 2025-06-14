//
// Created by alimu on 6/14/2025.
//

#ifndef GAME_H
#define GAME_H
#include "Pipe.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "UI.h"

inline constexpr unsigned int WINDOW_WIDTH = 800;
inline constexpr unsigned int WINDOW_HEIGHT = 600;


class Game {
public:
    Game();
    void run();

private:
    void handleEvents();
    void update(float& dt);
    void render();

    sf::RenderWindow window;
    sf::Clock clock;
    Player player;
    std::vector<Pipe> pipes;
    float pipeSpawnTimer = 2.f;
    bool active = false;
    UI ui;
};



#endif //GAME_H
