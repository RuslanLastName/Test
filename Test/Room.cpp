#include "Room.h"
#include <iostream>
#include <ctime>
#include <string>

int Room::px = 2;
int Room::py = 2;

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


	//setPerson();

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
			case -9:std::cout << '@' << ' '; break;
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
	view[py][px] = -1;
	if (c == 'u' || c == 'U')
		if (up > 0)
		{
			py = 3;
			return up;
		}
		else
			std::cout << "Doesn't exist! try again!" << number << std::endl;

	if (c == 'd' || c == 'D')
		if (down > 0)
		{
			py = 1;
			return down;
		}
		else
			std::cout << "Doesn't exist! try again!" << number << std::endl;

	if (c == 'l' || c == 'L')
		if (left > 0)
		{
			px = 3;
			return left;
		}
		else
			std::cout << "Doesn't exist! try again!" << number << std::endl;

	if (c == 'r' || c == 'R')
		if (right > 0)
		{
			px = 1;
			return right;
		}
		else
			std::cout << "Doesn't exist! try again!" << number << std::endl;
	
	setPerson();
	//view_room();
	return number;
}

int Room::Input(char *c, Items items[], bool itemb)
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
				for (int amon = 0; amon < items->get_amount(); amon++)
				{
					if (str[1] == items[amon].get_name() && pos[i] == items[amon].get_ID())
					{
						this->pos[i] = -1;
						update_view();
						return items[amon].get_ID();
					}
				}
			}
		}
		std::cout << "you can't do it " << std::endl;
	}
	else if (str[0] == "open" && itemb)
	{

		for (int i = 0; i < 4; i++)
		{
			if (pos[i] != -1)
			{
				if ((pos[i] == -2) && (str[1] == "chest"))
				{
					std::cout << "you find the golden kraaly" << std::endl;

					int res = pos[i];
					this->pos[i] = -1;
					update_view();
					return res;
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
	update_view();

	/*view[1][1] = pos[0];
	view[1][3] = pos[1];
	view[3][1] = pos[2];
	view[3][3] = pos[3];*/
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

void Room::setPerson()
{
	view[py][px] = -9;
	
	pup = view[py - 1][px];
	pdown = view[py + 1][px];
	pleft = view[py][px - 1];
	pright = view[py][px + 1];
}

char Room::movePerson(char c)
{
	view[py][px] = -1;
	std::cout << px << "  " << py << std::endl;
	if (c == 'u' || c == 'U')
		if (pup == -1)
			py -= 1;
		else if (pup > 0)
			return c;
		else
			std::cout << "Doesn't exist! try again!" << number << std::endl;

	if (c == 'd' || c == 'D')
		if (pdown == -1)
			py += 1;
		else if (pdown > 0)
			return c;
		else
			std::cout << "Doesn't exist! try again!" << number << std::endl;

	if (c == 'l' || c == 'L')
		if (pleft == -1)
			px -= 1;
		else if (pleft > 0)
			return c;
		else
			std::cout << "Doesn't exist! try again!" << number << std::endl;

	if (c == 'r' || c == 'R')
		if (pright == -1)
			px += 1;
		else if (pright > 0)
			return c;
		else
			std::cout << "Doesn't exist! try again!" << number << std::endl;

	setPerson();
	//view_room();
	return number;
}

Room::~Room()
{
}
