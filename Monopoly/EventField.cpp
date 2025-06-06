#include "EventField.h"
#include "Player.h"
#include "Dice.h"


void EventField::generate_chance(Player& p)
{

}

void EventField::prison_handle(Player &p)
{
	Dice dice;
	if (p.prison_cnt < 3) {
		int val1 = dice.roll();
		int val2 = dice.roll();
		if (val1 == val2) {
			p.prison_cnt = 0;
			p.isLock = 0;
		}
	}
	else {
		// доделать обработку на продажу полей
		if (p.total_cost < 500) {
			p.is_over = 1;
		}
		
	}
}
