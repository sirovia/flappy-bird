//
// Created by alimu on 6/14/2025.
//

#ifndef UI_H
#define UI_H
#include "SFML/Graphics.hpp"


class UI {
public:
    UI();
    void showScore(sf::RenderWindow &window, const unsigned int &score);

    void showMessage(sf::RenderWindow & window, const char* message);

private:
    sf::Font font;
    sf::Text scoreText;
    sf::Text messageText;
};



#endif //UI_H
