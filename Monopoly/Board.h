#pragma once
#include <vector>
#include <memory>
#include "Field.h"
class Board
{
public:
	std::vector<std::shared_ptr<Field>>cells;
	Board create();
	void render();

	bool is_end();

};

