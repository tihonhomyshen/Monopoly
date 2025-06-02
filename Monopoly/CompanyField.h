#pragma once
#include <string>
#include "Field.h"
class CompanyField: public Field
{
private:
	sf::Color getGroupColor(int group) {
		return sf::Color(50 + group * 20, 100, 150);
	}
public:	
	CompanyField(int group_id, std::string name, std::string category, std::string description, int price, 
		int upgrade_price, int buyout)
		: group_id(group_id), name(name), category(category), description(description), price(price),
		  upgrade_price(upgrade_price), buyout(buyout) {};


	float outlineThickness = 2.f;
	sf::Color outlineColor = sf::Color::Black;

	sf::Vector2f getRenderPosition() const {
		return { position.x + outlineThickness, position.y + outlineThickness };
	}

	sf::Vector2f getRenderSize() const {
		return { size.x - 2 * outlineThickness, size.y - 2 * outlineThickness };
	}

	void render(sf::RenderWindow& window) override {
		sf::RectangleShape shape(getRenderSize());
		shape.setPosition(getRenderPosition());
		shape.setOutlineThickness(outlineThickness);
		shape.setOutlineColor(outlineColor);
		shape.setFillColor(getGroupColor(group_id));
		window.draw(shape);
	}

	int group_id;
	std::string name;
	std::string category;
	std::string description;
	int owner_id = 0;
	int price;
	int upgrade_price;
	int buyout;
	int current_level = 0;
	bool can_upgrade = 0;

	bool checkUpgrade();

};

