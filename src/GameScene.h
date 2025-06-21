//
// Created by alimu on 6/17/2025.
//

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <functional>

#include "Scene.h"
#include "Player.h"
#include "Pipe.h"



class GameScene final : public Scene{
    sf::Font font;
    sf::Text scoreText;

    std::function<void()> callBack;
public:
    GameScene(const sf::RenderWindow& window, const std::function<void()> &onstart);

    void handleEvent(const std::optional<sf::Event>& event) override;
    void update(const float& dt) override;
    void render(sf::RenderWindow& window) override;

private:
    Player player;
    std::vector<Pipe> pipes;
    float pipeSpawnTimer = 2.f;
    bool active = false;

    //NAME IT BOR


};



#endif //GAMESCENE_H
