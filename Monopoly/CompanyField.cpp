#include "CompanyField.h"

CompanyField::CompanyField(int id1, int id2, std::string n, std::string d, int p, int up, int b, int cl, bool cu)
{
	id = id1;
	group_id = id2;
	name = n;
	description = d;
	price = p;
	upgrade_price = up;
	buyout = b;
	current_level = cl;
	can_upgrade = cu;
}

bool CompanyField::checkUpgrade()
{
	return false;
}
