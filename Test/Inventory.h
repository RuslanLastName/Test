#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

class Inventory
{
private:
	std::vector<char> items;
public:
	void show_items();
	void add_item(int item);
	void add_itemc(char item);
	void del_key(char item);
	Inventory();
	~Inventory();
};

