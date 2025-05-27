#include "Dice.h"
#include <random>

int Dice::roll()
{	
	std::uniform_int_distribution<int>range(1, 6);
	return range(random_gen);
}
