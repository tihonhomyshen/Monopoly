#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "Monopoly.h"
#include <SFML/Graphics.hpp>

using namespace std;


int main() {
	sf::RenderWindow window(sf::VideoMode({ 1200, 910 }), "SFML window");
	window.setFramerateLimit(60);
	std::string name1 = "Player1";
	std::string name2 = "Player2";
	sf::Color c1 = sf::Color::Red;
	sf::Color c2 = sf::Color::Green;
	Player p1 = Player(0, name1, c1);
	Player p2 = Player(0, name2, c2);
	vector<Player>players = { p1, p2 };
	Board board;
	board.create();
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color(38, 44, 47));
		board.render(window, players);
		window.display();
	}

	/*setlocale(LC_CTYPE, "Russian");
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
		
	}*/

	//board.get_info();
}