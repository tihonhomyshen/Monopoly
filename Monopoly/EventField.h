#pragma once
#include <map>
#include <string>
#include "Field.h"
class EventField : Field
{
public:
	int event_type;

	std::map<std::string, int>events = {
		{"Start", 1}, {"Chance", 2},
		{"Prison", 3}, {"Jackpot", 4},
		{"Pay1", 5}, {"Pay2", 6},
	};

	EventField(int, int);
};

