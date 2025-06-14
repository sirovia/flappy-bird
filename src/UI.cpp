//
// Created by alimu on 6/14/2025.
//

#include "UI.h"

UI::UI()
    : font("../../assets/fonts/PS2P/PS2P.ttf"),
      scoreText(font),
      messageText(font){

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setOutlineColor(sf::Color::Black);
    scoreText.setOutlineThickness(2);
    scoreText.setPosition({20.f, 20.f});

    messageText.setFont(font);
    messageText.setCharacterSize(20);
    messageText.setFillColor(sf::Color(255, 255, 255));
    messageText.setOutlineColor(sf::Color::Black);
    messageText.setOutlineThickness(2);
    messageText.setPosition({200.f, 400.f});
}

void UI::showScore(sf::RenderWindow &window, const unsigned int &score) {
    scoreText.setString("Score: " + std::to_string(score));
    window.draw(scoreText);
}

void UI::showMessage(sf::RenderWindow &window, const char* message) {
    messageText.setString(message);
    window.draw(messageText);
}

