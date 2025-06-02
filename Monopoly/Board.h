#pragma once
#include <vector>
#include <memory>
#include "Field.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class Board
{
public:

	Board() = default;
	std::vector<std::shared_ptr<Field>>cells;
	Board create();
	void render(sf::RenderWindow& window, std::vector<Player>& players);

	//Field* operator[](int ind);
	sf::Vector2f getCellPosition(int cellId) const;
	void get_info();
	bool is_end(std::vector<Player>& v);
	void check_field(Player &p, int);

};

