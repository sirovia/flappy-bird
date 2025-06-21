//
// Created by alimu on 6/15/2025.
//

#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics.hpp>

class Scene {
public:
    virtual ~Scene() = default;
    virtual void handleEvent(const std::optional<sf::Event>& event) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};

#endif //SCENE_H
