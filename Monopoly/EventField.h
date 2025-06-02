#pragma once
#include <map>
#include <string>
#include "Field.h"
#include "Player.h"
class EventField : public Field
{
public:
	std::string event_type;
	sf::Texture texture;
	sf::Sprite sprite;
	std::string spritePath;
	std::map<std::string, int>events = {
		{"Start", 1}, {"Chance", 2},
		{"Prison", 3}, {"Jackpot", 4},
		{"Pay1", 5}, {"Pay2", 6}, {"Guard", 7}
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
		shape.setFillColor(sf::Color(200, 200, 200));
		shape.setOutlineThickness(outlineThickness);
		shape.setOutlineColor(outlineColor);
		window.draw(shape);
	}

	void event_handler(Player&, std::string);
	void generate_chance(Player&);
	void prison_handle(Player&);

	EventField(std::string event_type, std::string spritePath) : event_type(event_type), spritePath(spritePath){
		texture.loadFromFile(spritePath);
		sprite.setTexture(texture);
	};
};

