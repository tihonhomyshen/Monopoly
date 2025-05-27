#pragma once
#include <random>
class Dice
{
public:
	Dice() {
		std::random_device device;
		random_gen.seed(device());
	}
	int roll();

private:
	std::mt19937 random_gen;
};

