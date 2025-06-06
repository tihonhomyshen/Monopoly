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
	int skipTurns = 0;
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
	void generate_chance(Player&);
	void prison_handle(Player&);

	EventField(std::string event_type, std::string spritePath) : event_type(event_type), spritePath(spritePath) {
		texture.loadFromFile(spritePath);
		sprite.setTexture(texture);
	}
	void applyEffect(Player& player) {
		if (event_type == "Start") return;

		if (player.getMoney() < 0) {
			player.declareOver();
		}
	}

};

