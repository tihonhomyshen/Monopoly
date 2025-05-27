#pragma once
#include <iostream>
#include <map>
#include "CompanyField.h"
class Player
{
public:
	Player(int id, std::string name): id(id), name(name) {};

	Player() = default;

	int id;
	int pos = 0;
	std::string name;
	std::string color;
	int money = 15'000;
	int total_cost = 15'000;
	bool first_turn = 1;
	bool is_over = 0;
	bool isLock = 0;
	int prison_cnt = 0;

	void set_color();
	void turn(int);
	bool check_condition();
		
};

