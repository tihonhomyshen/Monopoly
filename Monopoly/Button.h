#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;
    bool isHovered = false;
    bool isPressed = false;
    bool wasClicked = false;  // Новое поле для отслеживания клика
    std::function<void()> onClick;

public:
    Button(const sf::Vector2f& size, const sf::Vector2f& position,
        const std::string& buttonText, const sf::Font& font) {
        shape.setSize(size);
        shape.setPosition(position);
        shape.setFillColor(sf::Color(70, 70, 70));
        shape.setOutlineThickness(2);
        shape.setOutlineColor(sf::Color::White);

        text.setFont(font);
        text.setString(buttonText);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);

        // Центрируем текст в кнопке
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f,
            textRect.top + textRect.height / 2.0f);
        text.setPosition(position.x + size.x / 2.0f,
            position.y + size.y / 2.0f);
    }

    // Новый метод для проверки клика
    bool isClicked() const {
        return wasClicked;
    }

    void setOnClick(std::function<void()> callback) {
        onClick = callback;
    }

    void update(const sf::RenderWindow& window) {
        wasClicked = false;  // Сбрасываем флаг клика перед обновлением

        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        isHovered = shape.getGlobalBounds().contains(mousePos);

        if (isHovered) {
            shape.setFillColor(sf::Color(100, 100, 100));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                isPressed = true;
            }
            else if (isPressed) {
                isPressed = false;
                wasClicked = true;  // Устанавливаем флаг клика
                if (onClick) {
                    onClick();
                }
            }
        }
        else {
            shape.setFillColor(sf::Color(70, 70, 70));
            isPressed = false;
        }
    }

    void handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
        if (event.type == sf::Event::MouseButtonReleased &&
            event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(
                event.mouseButton.x,
                event.mouseButton.y
            ));
            if (shape.getGlobalBounds().contains(mousePos)) {
                wasClicked = true;
                if (onClick) {
                    onClick();
                }
            }
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }
};