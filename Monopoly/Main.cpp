#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "Monopoly.h"

using namespace std;

void welcome_window() {

}


int main() {
	setlocale(LC_CTYPE, "Russian");
	std::cout << "Привет, начнем игру?\n";
	std::cout << "Сколько игроков будет участвовать? (от 1 до 4)\n";
	int players_num;
	cin >> players_num;
	vector<Player>v(players_num);
	std::string name;
	for (int i = 0; i < players_num; ++i) {
		std::cout << "Введите имя игрока: \n";
		std::cin >> name;
		v[i].name = name;
	}
	Board board;
	board.create();
	int curr = 0;
	Dice dice;
	while (!board.is_end(v)) {
		int value1 = dice.roll();
		int value2 = dice.roll();
		Player p = v[curr];
		p.turn(value1 + value2);
		
	}

	//board.get_info();
}