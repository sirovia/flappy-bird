//
// Created by alimu on 6/12/2025.
//

#ifndef PIPE_H
#define PIPE_H

#include <SFML/Graphics.hpp>
#include <random>


class Pipe {
    sf::RectangleShape upperPipe;
    sf::RectangleShape lowerPipe;
    mutable sf::RectangleShape m_shape;
    float position;
    float speed;
public:
    Pipe();

    void update(const float &dt);

    void draw(sf::RenderWindow &window) const;

    void reset();

    bool intersects(const sf::FloatRect& rect) const;

    bool passed(const sf::FloatRect& rect);

    static float randY(float windowHeight, float gapHeight, float minMargin = 100.f);

};



#endif //PIPE_H
