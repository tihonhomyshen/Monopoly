#include "Monopoly.h"


Board Board::create()
{
	Board tmp;
	tmp.cells.resize(40);
	tmp.cells[0] = std::make_unique<EventField>("Start");
	tmp.cells[1] = std::make_unique<CompanyField>(1, "Chanel", "", "", 600, 0, 0);
	tmp.cells[2] = std::make_unique<EventField>("Chance");
	tmp.cells[3] = std::make_unique<CompanyField>(1, "Hugo Boss", "", "", 600, 0, 0);
	tmp.cells[4] = std::make_unique<EventField>("Pay2");
	tmp.cells[5] = std::make_unique<CompanyField>(2, "Mercedes", "", "", 2000, 0, 0);
	tmp.cells[6] = std::make_unique<CompanyField>(3, "Adidas", "", "", 1000, 0, 0);
	tmp.cells[7] = std::make_unique<CompanyField>(3, "Puma", "", "", 1000, 0, 0);
	tmp.cells[8] = std::make_unique<EventField>("Chance");
	tmp.cells[9] = std::make_unique<CompanyField>(3, "Lacoste", "", "", 1200, 0, 0);
	tmp.cells[10] = std::make_unique<EventField>("Prison");
	tmp.cells[11] = std::make_unique<CompanyField>(4, "Instagram", "", "", 1400, 0, 0);
	tmp.cells[12] = std::make_unique<CompanyField>(5, "Rockstar Games", "", "", 1500, 0, 0);
	tmp.cells[13] = std::make_unique<CompanyField>(4, "Telegram", "", "", 1400, 0, 0);
	tmp.cells[14] = std::make_unique<CompanyField>(4, "VK", "", "", 1600, 0, 0);
	tmp.cells[15] = std::make_unique<CompanyField>(2, "Audi", "", "", 2000, 0, 0);
	tmp.cells[16] = std::make_unique<CompanyField>(6, "Coca-Cola", "", "", 1800, 0, 0);
	tmp.cells[17] = std::make_unique<EventField>("Chance");
	tmp.cells[18] = std::make_unique<CompanyField>(6, "Pepsi", "", "", 1800, 0, 0);
	tmp.cells[19] = std::make_unique<CompanyField>(6, "Fanta", "", "", 2000, 0, 0);
	tmp.cells[20] = std::make_unique<EventField>("Jackpot");
	tmp.cells[21] = std::make_unique<CompanyField>(7, "American Airlines", "", "", 2200, 0, 0);
	tmp.cells[22] = std::make_unique<EventField>("Chance");
	tmp.cells[23] = std::make_unique<CompanyField>(7, "Qatar Airlines", "", "", 2200, 0, 0);
	tmp.cells[24] = std::make_unique<CompanyField>(7, "British Airways", "", "", 2400, 0, 0);
	tmp.cells[25] = std::make_unique<CompanyField>(2, "Ford", "", "", 2000, 0, 0);
	tmp.cells[26] = std::make_unique<CompanyField>(8, "McDonald's", "", "", 2600, 0, 0);
	tmp.cells[27] = std::make_unique<CompanyField>(5, "Rovio", "", "", 1500, 0, 0);
	tmp.cells[28] = std::make_unique<CompanyField>(8, "Burger King", "", "", 2600, 0, 0);
	tmp.cells[29] = std::make_unique<CompanyField>(8, "KFC", "", "", 2800, 0, 0);
	tmp.cells[30] = std::make_unique<EventField>("Guard");
	tmp.cells[31] = std::make_unique<CompanyField>(9, "Holiday Inn", "", "", 3000, 0, 0);
	tmp.cells[32] = std::make_unique<EventField>("Chance");
	tmp.cells[33] = std::make_unique<CompanyField>(9, "Radison Blu", "", "", 3000, 0, 0);
	tmp.cells[34] = std::make_unique<CompanyField>(9, "Novotel", "", "", 3200, 0, 0);
	tmp.cells[35] = std::make_unique<CompanyField>(2, "Land Rover", "", "", 2000, 0, 0);
	tmp.cells[36] = std::make_unique<EventField>("Pay1");
	tmp.cells[37] = std::make_unique<CompanyField>(10, "Apple", "", "", 3500, 0, 0);
	tmp.cells[38] = std::make_unique<EventField>("Chance");
	tmp.cells[39] = std::make_unique<CompanyField>(10, "Nokia", "", "", 4000, 0, 0);

	for (int i = 0; i < 40; ++i) {
		tmp.cells[i]->id = i + 1;
	}
	*this = tmp;
	return *this;
}

void Board::render()
{

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
			std::cout << "Name: " << obj->name << " " << "Price: " << obj->price << '\n';
		}
	}
}

bool Board::is_end()
{
	return false;
}
