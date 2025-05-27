#include "Player.h"
#include "CompanyField.h"
bool Player::check_condition()
{
    return 0;
}

void Player::turn(int step) {
    pos += step;
    if (pos > 39) {
        pos %= 39;
        money += 2'000;
    }
    
}

;
