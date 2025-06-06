#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class PlayerInfoPanel {
private:
    sf::RectangleShape background;
    sf::Text nameText;
    sf::Text moneyText;
    Player* player;

public:
    PlayerInfoPanel(const sf::Vector2f& position, const sf::Vector2f& size, Player* player)
        : player(player) {
        background.setSize(size);
        background.setPosition(position);
        background.setFillColor(sf::Color(240, 240, 240));
        background.setOutlineThickness(2);
        background.setOutlineColor(sf::Color::Black);

        nameText.setFillColor(sf::Color::Black);
        nameText.setCharacterSize(20);
        moneyText.setCharacterSize(18);
        moneyText.setFillColor(sf::Color::Black);

    }

    void update() {
        if (player) {
            nameText.setString(player->getName());
            moneyText.setString("$" + std::to_string(player->getMoney()));
        }
    }

    void draw(sf::RenderWindow& window, const sf::Font& font) {
        nameText.setFont(font);
        moneyText.setFont(font);

        sf::FloatRect bounds = background.getGlobalBounds();
        nameText.setPosition(bounds.left + 10, bounds.top + 10);
        moneyText.setPosition(bounds.left + 10, bounds.top + 40);

        window.draw(background);
        window.draw(nameText);
        window.draw(moneyText);
    }
};