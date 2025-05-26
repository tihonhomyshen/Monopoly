#include "Monopoly.h"


Board Board::create()
{
	Board tmp;
	tmp.cells.resize(40);
	tmp.cells[0] = std::make_unique<EventField>(1, "Start");
	tmp.cells[1] = std::make_unique<CompanyField>(2, 1, "", "", 600, 0, 0, 0, 0);
	tmp.cells[2] = std::make_unique<EventField>(3, "Chance");
	tmp.cells[3] = std::make_unique<EventField>(4, "Pay2");
	
	//std::cout << typeid(dynamic_cast<EventField*>(tmp.cells[0].get())).name();
	//if (dynamic_cast<EventField*>(tmp.cells[0].get())) {
	//	std::cout << "YES" << '\n';
	//}
	//EventField* e = dynamic_cast<EventField*>(tmp.cells[0].get());
	*this = tmp;
	return *this;
}

void Board::render()
{

}

bool Board::is_end()
{
	return false;
}
