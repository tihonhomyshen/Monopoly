#include "Monopoly.h"
#include <vector>
#include <locale.h>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>


Board Board::create()
{
	Board tmp;
	tmp.cells.resize(40);

	tmp.cells[0] = std::make_unique<EventField>("Start", "../images/chance.png");
	tmp.cells[1] = std::make_unique<CompanyField>(1, "Chanel", "", "", 600, 0, 0, "../images/chanel.png");
	tmp.cells[2] = std::make_unique<EventField>("Chance", "../images/chance.png");
	tmp.cells[3] = std::make_unique<CompanyField>(1, "Hugo Boss", "", "", 600, 0, 0, "../images/hugo_boss.png");
	tmp.cells[4] = std::make_unique<EventField>("Pay2", "../images/chance.png");
	tmp.cells[5] = std::make_unique<CompanyField>(2, "Mercedes", "", "", 2000, 0, 0, "../images/mercedes.png");
	tmp.cells[6] = std::make_unique<CompanyField>(3, "Adidas", "", "", 1000, 0, 0, "../images/adidas.png");
	tmp.cells[8] = std::make_unique<EventField>("Chance", "../images/chance.png");
	tmp.cells[7] = std::make_unique<CompanyField>(3, "Puma", "", "", 1000, 0, 0, "../images/puma.png");
	tmp.cells[9] = std::make_unique<CompanyField>(3, "Lacoste", "", "", 1200, 0, 0, "../images/lacoste.png");
	tmp.cells[10] = std::make_unique<EventField>("Prison", "../images/chance.png");
	tmp.cells[11] = std::make_unique<CompanyField>(4, "Circle+", "", "", 1400, 0, 0, "../images/circle-plus.png");
	tmp.cells[12] = std::make_unique<CompanyField>(5, "Rockstar Games", "", "", 1500, 0, 0, "../images/adidas.png");
	tmp.cells[13] = std::make_unique<CompanyField>(4, "Chirp", "", "", 1400, 0, 0, "../images/chirp.png");
	tmp.cells[14] = std::make_unique<CompanyField>(4, "Friender", "", "", 1600, 0, 0, "../images/friender.png");
	tmp.cells[15] = std::make_unique<CompanyField>(2, "Audi", "", "", 2000, 0, 0, "../images/audi.png");
	tmp.cells[16] = std::make_unique<CompanyField>(6, "Coca-Cola", "", "", 1800, 0, 0, "../images/coca_cola.png");
	tmp.cells[17] = std::make_unique<EventField>("Chance", "../images/chance.png");
	tmp.cells[18] = std::make_unique<CompanyField>(6, "Pepsi", "", "", 1800, 0, 0, "../images/pepsi.png");
	tmp.cells[19] = std::make_unique<CompanyField>(6, "Fanta", "", "", 1800, 0, 0, "../images/fanta.png");
	tmp.cells[20] = std::make_unique<EventField>("Jackpot", "../images/chance.png");
	tmp.cells[21] = std::make_unique<CompanyField>(7, "American Airlines", "", "", 2200, 0, 0, "../images/american_airlines.png");
	tmp.cells[22] = std::make_unique<EventField>("Chance", "../images/chance.png");
	tmp.cells[23] = std::make_unique<CompanyField>(7, "Qatar Airlines", "", "", 2200, 0, 0, "../images/lufthansa.png");
	tmp.cells[24] = std::make_unique<CompanyField>(7, "British Airways", "", "", 2400, 0, 0, "../images/british_airways.png");
	tmp.cells[25] = std::make_unique<CompanyField>(2, "Ford", "", "", 2000, 0, 0, "../images/ford.png");
	tmp.cells[26] = std::make_unique<CompanyField>(8, "Max Burgers", "", "", 2600, 0, 0, "../images/max_burgers.png");
	tmp.cells[27] = std::make_unique<CompanyField>(8, "Burger King", "", "", 2600, 0, 0, "../images/burger_king.png");
	tmp.cells[28] = std::make_unique<CompanyField>(5, "Rovio", "", "", 1500, 0, 0, "../images/rovio.png");
	tmp.cells[29] = std::make_unique<CompanyField>(8, "KFC", "", "", 2800, 0, 0, "../images/kfc.png");
	tmp.cells[30] = std::make_unique<EventField>("Guard", "../images/chance.png");
	tmp.cells[31] = std::make_unique<CompanyField>(9, "Holiday Inn", "", "", 3000, 0, 0, "../images/holiday_inn.png");
	tmp.cells[32] = std::make_unique<EventField>("Chance", "../images/chance.png");
	tmp.cells[33] = std::make_unique<CompanyField>(9, "Radison Blu", "", "", 3000, 0, 0, "../images/radisson_blu.png");
	tmp.cells[34] = std::make_unique<CompanyField>(9, "Novotel", "", "", 3200, 0, 0, "../images/novotel.png");
	tmp.cells[35] = std::make_unique<CompanyField>(2, "Land Rover", "", "", 2000, 0, 0, "../images/land_rover.png");
	tmp.cells[36] = std::make_unique<EventField>("Pay1", "../images/chance.png");
	tmp.cells[37] = std::make_unique<CompanyField>(10, "Apple", "", "", 3500, 0, 0, "../images/apple.png");
	tmp.cells[38] = std::make_unique<EventField>("Chance", "../images/chance.png");
	tmp.cells[39] = std::make_unique<CompanyField>(10, "Nokia", "", "", 4000, 0, 0, "../images/nokia.png");

	const sf::Vector2f cornerSize(120.f, 120.f);
	const sf::Vector2f horizontalSize(120.f, 65.f);
	const sf::Vector2f verticalSize(65.f, 120.f);

	sf::Vector2f position(300.f, 50.f);


	tmp.cells[0]->position = position;
	tmp.cells[0]->size = cornerSize;

	position.x += cornerSize.x;

	for (int i = 1; i < 10; ++i) {
		tmp.cells[i]->position = position;
		tmp.cells[i]->size = verticalSize;
		position.x += verticalSize.x;
	}
	tmp.cells[10]->position = position;
	tmp.cells[10]->size = cornerSize;
	position.y += cornerSize.y;

	for (int i = 11; i < 20; ++i) {
		tmp.cells[i]->position = position;
		tmp.cells[i]->size = horizontalSize;
		position.y += horizontalSize.y;
	}

	tmp.cells[20]->position = position;
	tmp.cells[20]->size = cornerSize;
	position.x -= verticalSize.x;
	for (int i = 21; i < 30; ++i) {
		tmp.cells[i]->position = position;
		tmp.cells[i]->size = verticalSize;
		if (i == 29) {
			position.x -= cornerSize.x;
		}
		else position.x -= verticalSize.x;
	}
	tmp.cells[30]->position = position;
	tmp.cells[30]->size = cornerSize;
	position.y -= horizontalSize.y;
	for (int i = 31; i < 40; ++i) {
		tmp.cells[i]->position = position;
		tmp.cells[i]->size = horizontalSize;
		if (i == 29) {
			position.y -= cornerSize.y;
		}
		else position.y -= horizontalSize.y;
	}

	for (int i = 0; i < 40; ++i) {
		tmp.cells[i]->id = i + 1;
	}
	for (int i = 1; i < 40; ++i) {
		tmp.cells[i]->sprite.setPosition(tmp.cells[i - 1]->position);
	}

	*this = tmp;
	return *this;
}

void Board::render(sf::RenderWindow& window)
{
	for (auto& cell : cells) {
		std::cout << cell->sprite.getPosition().x << " " << cell->sprite.getPosition().y << "\n";
		cell->render(window);
	}
}

sf::Vector2f Board::getCellPosition(int cellId) const {
	if (cellId >= 0 && cellId < cells.size()) {
		return cells[cellId]->position;
	}
	return { 0, 0 };
}

std::vector<sf::Vector2f> Board::getMovementPath(int fromPos, int toPos)
{
	std::vector<sf::Vector2f> path;

	if (fromPos == toPos) {
		path.push_back(getCellPosition(fromPos));
		return path;
	}

	int current = fromPos;
	do {
		path.push_back(getCellPosition(current));
		current = (current + 1) % cells.size();
	} while (current != (toPos + 1) % cells.size());

	return path;
}

void Board::get_info()
{
	Board curr = *this;
	for (int i = 0; i < 40; ++i) {
		if (dynamic_cast<EventField*>(this->cells[i].get())) {
			EventField* e = dynamic_cast<EventField*>(this->cells[i].get());
			std::cout << "Board id: " << e->id << " " << "Event type: " << e->event_type << '\n';
		}
		else {
			CompanyField* obj = dynamic_cast<CompanyField*>(this->cells[i].get());
			std::cout << "Board id: " << obj->id << " " << "Group id: " << obj->group_id << '\n';
			std::cout << "Name: " << obj->name << " " << "Owner: " << obj->owner_id << '\n';
		}
	}
}

