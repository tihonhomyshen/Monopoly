#pragma once
#include <vector>
#include "Field.h"
class Board
{
private:
	std::vector<std::vector<Field>>cells;
public:
	void create(int);
	void render();
};

