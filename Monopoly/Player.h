#pragma once
#include <iostream>
#include <map>
#include "Dice.h"
#include "Board.h"
#include "PurchaseDialog.h"
#include <SFML/Graphics.hpp>
#include "CompanyField.h"
class Player
{
private:
	sf::CircleShape shape;
	sf::Text nameText;
	sf::Vector2f offset;
	CompanyField* toBuy = nullptr;
	bool wantsToBuy = false;
	int skipTurns = 1;
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

	std::string getName() {
		return name;
	}
	void draw(sf::RenderWindow& window, const sf::Font& font) {
		if (is_over) return;
		window.draw(shape);

	}
	void setPosition(sf::Vector2f cellPosition) {
		shape.setPosition(cellPosition + offset);
	}

	void addMoney(int amount) {
		money += amount;
		if (money < 0 && !is_over) {
			money = 0;
			is_over = true;
		}
	}

	int getMoney() const { return money; }
	void pay(int amount) { money -= amount; }
	void receiveMoney(int amount) { money += amount; }

	void buyProperty(CompanyField& field) {
		if (money >= field.getPrice()) {
			money -= field.getPrice();
			field.setOwner(id, color);
			std::cout << name << "is BANKRUPT!" << std::endl;
		}
	}

	int turn(Board& board) {
		Dice dice;
		int v1 = dice.roll();
		int v2 = dice.roll();
		pos += (v1 + v2);
		if (pos >= 40) {
			money += 2000;
			pos %= 40;
		}

		Field* currentField = board.getCell(pos);
		if (currentField) {
			if (auto company = dynamic_cast<CompanyField*>(currentField)) {
				if (company->owner_id != id && company->owner_id != 0) {
					money -= company->price * 0.5;
				}
			}
		}

		return v1 + v2;;
	}
	bool isOver() const { return is_over; }
	void declareOver() { is_over = true; money = 0; }

	const sf::Color& getColor() const { return color; }
};

