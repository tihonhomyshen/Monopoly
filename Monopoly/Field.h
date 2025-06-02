#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class Field
{
public:
	int id;
	sf::Vector2f position;
	sf::Vector2f size;
	virtual ~Field() = default;
	virtual void render(sf::RenderWindow& window) = 0;
	//virtual std::string getType() const = 0;
};

