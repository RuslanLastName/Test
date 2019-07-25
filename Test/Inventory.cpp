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

void Inventory::del_key(char item)
{
	auto elfound = find(items.begin(), items.end(), item);

	if (elfound != items.end())
	{
		int dist = distance(items.begin(), elfound);
		items.erase(items.begin() + dist);
	}
	
}

Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}
