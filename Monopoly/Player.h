#pragma once
#include <iostream>
#include <map>
#include "Dice.h"
#include "Board.h"
#include "CompanyField.h"
#include "PurchaseDialog.h"
#include <SFML/Graphics.hpp>
class Player
{
private:
	sf::CircleShape shape;
	sf::Text nameText;
	sf::Vector2f offset;
	CompanyField* toBuy = nullptr;
	bool wantsToBuy = false;
public:
	Player(int id, std::string name, sf::Color color, sf::Vector2f offset = { 0, 0 }) : id(id), name(name), color(color), offset(offset) {
		shape.setRadius(15.f);
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
		if (is_over) return;

		window.draw(shape);
		nameText.setFont(font);
		nameText.setFillColor(sf::Color::Black);
		nameText.setCharacterSize(13);
		nameText.setPosition(shape.getPosition().x, shape.getPosition().y - 25);
		window.draw(nameText);

		sf::Text moneyText;
		moneyText.setFont(font);
		moneyText.setFillColor(sf::Color::Black);
		moneyText.setString("$" + std::to_string(money));
		moneyText.setCharacterSize(13);
		moneyText.setPosition(shape.getPosition().x, shape.getPosition().y + 25);
		window.draw(moneyText);
	}
	void setPosition(sf::Vector2f cellPosition) {
		shape.setPosition(cellPosition + offset);
	}


	int getMoney() const { return money; }

	void buyProperty(CompanyField& field) {
		if (money >= field.price) {
			money -= field.price;
			field.setOwnerId(this->id);
		}
	}

	bool turn(Board& board) {
		Dice dice;
		int v1 = dice.roll();
		int v2 = dice.roll();
		pos += (v1 + v2);
		if (pos >= 40) money += 2'000;
		pos %= 40;
		auto company = dynamic_cast<CompanyField*>(board.cells[pos].get());
		if (company != nullptr) {
			CompanyField* company = dynamic_cast<CompanyField*>(board.cells[pos].get());
			if (company->owner_id != id && company->owner_id != 0) {
				money -= company->price * 0.5;
			}
		}

		
		return v1 == v2;
	};
	bool check_condition() {
		is_over = (total_cost <= 0);
		return is_over;
	};
};

