#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class Field
{
public:
	int id;
    sf::Vector2f position;
    sf::Vector2f size;
    std::string spritePath;
    sf::Texture texture;
    sf::Sprite sprite;

	virtual ~Field() = default;
	virtual void render(sf::RenderWindow& window) = 0;
};

