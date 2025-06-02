#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Field.h"
class CompanyField: public Field
{
private:
	std::map<int, sf::Color>mp = {
		{1, sf::Color(236, 135, 193)},
		{2, sf::Color(218, 69, 83)},
		{3, sf::Color(224, 180, 57)},
		{4,sf::Color(55, 188, 157)},
		{5,sf::Color(127, 31, 15)},
		{6,sf::Color(75, 137, 120)},
		{7,sf::Color(140, 193, 82)},
		{8,sf::Color(79, 193, 233)},
		{9,sf::Color(150, 123, 220)},
		{10,sf::Color(101, 109, 120)}
	};
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Color getGroupColor(int group) {
		//auto it = mp.find(group);
		//if (it != mp.end()) {
		//	return it->second;
		//}
		return sf::Color::White; 
	}

public:	
	CompanyField(int group_id, std::string name, std::string category, std::string description, int price,
		int upgrade_price, int buyout, std::string spritePath)
		: group_id(group_id), name(name), category(category), description(description), price(price),
		upgrade_price(upgrade_price), buyout(buyout) {
		texture.loadFromFile(spritePath);
		sprite.setTexture(texture);
		sprite.rotate(90);
		
	};
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
		window.draw(sprite);
	}

	int group_id;
	std::string name;
	std::string category;
	std::string description;
	int price;
	int upgrade_price;
	int buyout;
	int owner_id = 0;
	int current_level = 0;
	bool can_upgrade = 0;
	std::string spritePath;

	bool isOwned() const {
		return owner_id != 0;
	}

	int getPrice() const {
		return price;
	}

	std::string getName() const {
		return name;
	}

	void setOwnerId(int id) { owner_id = id; }

	bool checkUpgrade();

};

