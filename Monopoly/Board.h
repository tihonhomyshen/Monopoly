#pragma once
#include <vector>
#include <memory>
#include "Field.h"
#include "CompanyField.h"
#include <SFML/Graphics.hpp>

class Board
{
public:

	Board() = default;
	std::vector<std::shared_ptr<Field>>cells;
	Board create();
	void render(sf::RenderWindow& window);

	sf::Vector2f getCellPosition(int cellId) const;
	std::vector<sf::Vector2f>getMovementPath(int fromPos, int toPos);

	bool canBuy(int pos) const {
		if (pos < 0 || pos >= this->cells.size()) return false;
		if (dynamic_cast<CompanyField*>(this->cells[pos].get())) {
			CompanyField* companyField = dynamic_cast<CompanyField*>(this->cells[pos].get());
			return (companyField->isOwned() == 0);
		}
		return false;
	}
	Field* getCell(int index) {
		if (index >= 0 && index < cells.size())
			return this->cells[index].get();
		return nullptr;
	}

	void get_info();
	//bool is_end(std::vector<Player>& v);
	//void check_field(Player &p, int);

};

