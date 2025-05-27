#pragma once
#include <vector>
#include <memory>
#include "Field.h"
#include "Player.h"
class Board
{
public:

	Board() = default;
	std::vector<std::shared_ptr<Field>>cells;
	Board create();
	void render();

	//Field* operator[](int ind);

	void get_info();
	bool is_end(std::vector<Player>& v);
	void check_field(Player &p, int);
};

