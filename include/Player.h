//
// Created by alimu on 6/10/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>



class Player {
    sf::CircleShape m_shape;
    float y;
    float verticalSpeed;

    static constexpr float speed = 50.f;
    static constexpr float gravity = 2000.f;
    static constexpr float flapS = -600.f;

public:
    Player();

    void flap();
    void draw(sf::RenderWindow &window) const;
    void update(const float &dt);
    float getPos() const;
};



#endif //PLAYER_H
