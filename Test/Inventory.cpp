#include "Inventory.h"



void Inventory::show_items()
{
	auto iter = items.cbegin();
	std::cout << "[";
	for (auto item : items)
	{
		std::cout << item;
		iter++;
		if (iter != items.cend())
		{
			std::cout << ",";
		}
		
	}
	std::cout << "]";
}

void Inventory::add_item(int item)
{
	items.push_back(item);

}

void Inventory::add_itemc(char item)
{
	items.push_back(item);
}

Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}
