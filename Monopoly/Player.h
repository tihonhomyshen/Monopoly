#pragma once
#include <iostream>
#include <map>
#include "Dice.h"
#include "CompanyField.h"
#include <SFML/Graphics.hpp>
class Player
{
private:
	sf::CircleShape shape;
	sf::Text nameText;
	sf::Vector2f offset;
public:
	Player(int id, std::string name, sf::Color color, sf::Vector2f offset = {0, 0}) : id(id), name(name), color(color), offset(offset) {
		shape.setRadius(20.f);
		shape.setOutlineThickness(2.f);
		shape.setOutlineColor(sf::Color::Black);

		nameText.setString(name);
		nameText.setCharacterSize(12);
		nameText.setFillColor(sf::Color::White);
	};

	Player() = default;

	int id;
	int pos = 0;
	std::string name;
	sf::Color color;
	int money = 15'000;
	int total_cost = 15'000;
	bool first_turn = 1;
	bool is_over = 0;
	bool isLock = 0;
	int prison_cnt = 0;

	void set_color() {
		shape.setFillColor(color);
	};

	void draw(sf::RenderWindow& window, const sf::Font& font) {
		if (is_over) return;  // Не рисуем, если игрок выбыл

		nameText.setFont(font);  // Устанавливаем шрифт перед отрисовкой
		window.draw(shape);
		window.draw(nameText);
	}
	void setPosition(sf::Vector2f cellPosition) {
		// Устанавливаем позицию игрока относительно центра клетки
		shape.setPosition(cellPosition + offset);
	}

	void turn() {
		Dice dice;
		int v1 = dice.roll();
		int v2 = dice.roll();
		pos = (v1 + v2) % 40;
		if (v1 == v2) {
			turn();
		}
	};
	bool check_condition() {
		is_over = (total_cost <= 0);
		return is_over;
	};
};

