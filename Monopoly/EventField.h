#pragma once
#include <map>
#include <string>
#include "Field.h"
#include "Player.h"
class EventField : public Field
{
public:
	std::string event_type;

	std::map<std::string, int>events = {
		{"Start", 1}, {"Chance", 2},
		{"Prison", 3}, {"Jackpot", 4},
		{"Pay1", 5}, {"Pay2", 6}, {"Guard", 7}
	};

	void event_handler(Player&, std::string);
	void generate_chance(Player&);
	void prison_handle(Player&);

	EventField(std::string event_type) : event_type(event_type) {};
};

