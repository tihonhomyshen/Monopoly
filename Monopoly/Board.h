#pragma once
#include <vector>
#include "Field.h"
class Board
{
public:
	std::vector<Field>cells;
	Board create();
	void render();

	bool is_end();

};

