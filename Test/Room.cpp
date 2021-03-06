#include "Room.h"
#include <iostream>
#include <ctime>
#include <string>

Room::Room()
{
	number = 0;
	left = 0;
	right = 0;
	up = 0;
	down = 0;
	x = 0;
	y = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == 0 || i == N - 1 || j == 0 || j == N - 1)
				view[i][j] = 0;
			else
				view[i][j] = -1;
		}
	}
}

void Room::view_room()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{

			switch (view[i][j])
			{
			case 0:std::cout << '#' << ' '; break;//wall
			case -1:std::cout << ' ' << ' '; break;//void
			case -2:std::cout << '$' << ' '; break;//chest
			case -3:std::cout << '%' << ' '; break;//key
			default: {
				if (up > 0 && view[i][j] == up)
					std::cout << 'U' << ' ';
				if (down > 0 && view[i][j] == down)
					std::cout << 'D' << ' ';
				if (left > 0 && view[i][j] == left)
					std::cout << 'L' << ' ';
				if (right > 0 && view[i][j] == right)
					std::cout << 'R' << ' ';
			}
				 break;
			}
		}
		std::cout << std::endl;
	}
}

void Room::set_doors(int up, int down, int left, int right)
{
	this->up = up;
	this->down = down;
	this->left = left;
	this->right = right;

	view[0][2] = this->up;
	view[4][2] = this->down;
	view[2][0] = this->left;
	view[2][4] = this->right;
}

int Room::get_door(char c)
{
	if (c == 'u' || c == 'U')
		if (up > 0)
			return up;
	if (c == 'd' || c == 'D')
		if (down > 0)
			return down;	
	if (c == 'l' || c == 'L')
		if (left > 0)
			return left;
	if (c == 'r' || c == 'R')
		if (right > 0)
			return right;	
	std::cout << "Doesn't exist! try again!" << number << std::endl;
	return number;
}

int Room::Input(char *c, Items items[])
{
	std::string str[5];
	int cchar[10] = { 0 };
	int q = 1;
	int t = 0;
	int it = 0;//iterator for items
	t = strlen(c);

	if (t > 3)
	{
		for (int i = 0; i < t; i++)
		{
			if (c[i] == ' ')
			{
				cchar[q] = i;
				q++;
			}
		}
		cchar[q] = t;
		for (int i = 1; i < 10; i++)
			if (cchar[i] > 0)
				for (int j = cchar[i - 1]; j < cchar[i]; j++)
					if (c[j] != ' ')
						str[i - 1] += c[j];

		
	}

	if (str[0] == "get")
	{
		for (int i = 0; i < 4; i++)
		{
			if (pos[i] != -1)
			{
				if ((pos[i] == -2) && (str[1] == "chest"))
				{
					std::cout << "you can't get the chest" << std::endl;
					return 0;
				}
				else
				{
					while (items[it].get_ID() < 0)
					{
						if (str[1] == items[it].get_name() && pos[i] == items[it].get_ID())
						{
							this->pos[i] = -1;
							update_view();
							return items[it].get_ID();
						}
						it++;
					}
				}

			}
		}
	}
	return 0;
}

void Room::set_number(int number)
{
	this->number = number;
}

int Room::get_number()
{
	std::cout << number << std::endl;
	return number;
}

int Room::getUp()
{
	return up;
}

int Room::getDown()
{
	return down;
}

int Room::getLeft()
{
	return left;
}

int Room::getRight()
{
	return right;
}

void Room::set_item(int ID)
{
	bool inpos = false;
	while (!inpos)
	{
		int p = rand() % 4;
		if (pos[p] == -1)
		{
			pos[p] = ID;
			inpos = true;
		}
	}

	view[1][1] = pos[0];
	view[1][3] = pos[1];
	view[3][1] = pos[2];
	view[3][3] = pos[3];
}

void Room::update_view()
{
	view[1][1] = pos[0];
	view[1][3] = pos[1];
	view[3][1] = pos[2];
	view[3][3] = pos[3];
}

int Room::get_item()
{
	return 0;
}

Room::~Room()
{
}
