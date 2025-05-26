#pragma once
#include <string>
#include "Field.h"
class CompanyField: public Field
{
public:
	
	CompanyField(int, int, std::string, std::string, int, int, int, int, bool);

	int group_id;
	std::string name;
	std::string description;
	int price;
	int upgrade_price;
	int buyout;
	int current_level;
	bool can_upgrade;

	bool checkUpgrade();
};

