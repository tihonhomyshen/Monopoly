#pragma once
#include "Monopoly.h"
#include "Button.h"
#include "SFML/Graphics.hpp"
class PurchaseDialog {
public:
    sf::RectangleShape background;
    sf::Text message;
    sf::Text priceText;
    Button buyButton;
    Button declineButton;
    bool visible = false;
    CompanyField* currentField = nullptr;
    PurchaseDialog(const sf::Font& font) :
        buyButton(sf::Vector2f(125, 75), sf::Vector2f(500, 250), "Purchase?", font),
        declineButton(sf::Vector2f(125, 75), sf::Vector2f(750, 250), "Decline", font)
    {
        background.setSize(sf::Vector2f(275, 125));
        background.setFillColor(sf::Color(70, 70, 70));
        background.setOutlineThickness(2);
        background.setOutlineColor(sf::Color::White);
        background.setPosition(575, 350);

        message.setFont(font);
        message.setCharacterSize(20);
        message.setFillColor(sf::Color::White);
        message.setPosition(650, 350);

        priceText.setFont(font);
        priceText.setCharacterSize(24);
        priceText.setFillColor(sf::Color::Red);
        priceText.setPosition(650, 415);
    }

    void show(CompanyField* field) {
        currentField = field;
        visible = true;
        message.setString("Want to Buy\n" + field->name + "?");
        priceText.setString("Price: " + std::to_string(field->price) + "$");
    }

    void hide() {
        visible = false;
    }

    bool isVisible() const { return visible; }


    void update(const sf::RenderWindow& window) {
        if (!visible) return;
        buyButton.update(window);
        declineButton.update(window);
    }

    void draw(sf::RenderWindow& window) {
        if (!visible) return;
        window.draw(background);
        window.draw(message);
        window.draw(priceText);
        buyButton.draw(window);
        declineButton.draw(window);
    }
};