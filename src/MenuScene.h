//
// Created by alimu on 6/15/2025.
//

#ifndef MENUSCENE_H
#define MENUSCENE_H
#include <functional>

#include "Scene.h"
#include <SFML/Graphics.hpp>



class MenuScene final : public Scene {
    sf::Font font;
    sf::Text title;
    sf::Text startText;
    sf::RectangleShape startButton;

    std::function<void()> onStartCallBack;

public:
    MenuScene(const sf::RenderWindow& window, const std::function<void()> &onstart);

    void handleEvent(const std::optional<sf::Event>& event) override;
    void update(const float& dt) override;
    void render(sf::RenderWindow& window) override;


};


#endif //MENUSCENE_H
