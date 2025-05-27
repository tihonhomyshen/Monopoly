#pragma once
#include <string>
#include "Field.h"
class CompanyField: public Field
{
public:
	
	CompanyField(int group_id, std::string name, std::string category, std::string description, int price, 
		int upgrade_price, int buyout)
		: group_id(group_id), name(name), category(category), description(description), price(price),
		  upgrade_price(upgrade_price), buyout(buyout) {};

	int group_id;
	std::string name;
	std::string category;
	std::string description;
	int owner_id = 0;
	int price;
	int upgrade_price;
	int buyout;
	int current_level = 0;
	bool can_upgrade = 0;

	bool checkUpgrade();

};

