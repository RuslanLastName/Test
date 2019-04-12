#include "Items.h"
#include <cstring>


Items::Items()
{
	ID = 0;
	name = "";
	number = 0;
	//position = 0;
}

Items::Items(int id, std::string Name, int Number)
{
	ID = id;
	name = "";
	name = Name;
	number = Number;
	//position = Position;
}

Items::Items(int id, std::string Name)
{
	ID = id;
	name = "";
	name = Name;
}

int Items::get_ID()
{
	return ID;
}

std::string Items::get_name()
{
	return name;
}

int Items::get_number()
{
	return number;
}

void Items::set_number(int Number)
{
	number = Number;
}

/*int Items::get_position()
{
	return position;
}

void Items::set_position(int Position)
{
	position = Position;
}
*/

Items::~Items()
{

}


