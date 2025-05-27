#include <iostream>
#include <vector>
#include "Monopoly.h"

using namespace std;

int main() {
	setlocale(LC_CTYPE, "Russian");
	Board board;
	board.create();
	board.get_info();
}