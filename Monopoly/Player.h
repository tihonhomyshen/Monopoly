#pragma once
#include <iostream>
class Player
{
public:
	Player() = default;

	int id;
	int pos;
	std::string name;
	int money;
	int total_cost;
	bool first_turn;

	bool check_condition();
	
	
};

