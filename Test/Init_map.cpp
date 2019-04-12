#include "Init_map.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

Init_map::Init_map()
{
	this->map = nullptr;
}

void Init_map::setN(int n)
{
	this->n = n / 2;
	this->room = n;
}

void Init_map::gen_map()
{
	srand(time(0));
	int x = 0;
	int y = 0;
	int s = 1;
	this->map = new int *[n];
	
	for (int i = 0; i < n; i++)
		this->map[i] = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			this->map[i][j] = 0;
		}
	}

	x = rand() % n;
	y = rand() % n;

	this->map[y][x] = s;
	s++;

	while (s < room + 1)
	{
		x = rand() % n;
		y = rand() % n;
		if (this->map[y][x] != 0)
		{
			x = rand() % n;
			y = rand() % n;
		}
		if (this->map[y][x] == 0)
		{
			if (y > 0)
				if (this->map[y - 1][x] > 0)
				{
					this->map[y][x] = s;
					s++;
					continue;
				}
			if (y < n - 1)
				if (this->map[y + 1][x] > 0)
				{
					this->map[y][x] = s;
					s++;
					continue;
				}

			if (x > 0)
				if (this->map[y][x - 1] > 0)
				{
					this->map[y][x] = s;
					s++;
					continue;
				}
			if (x < n - 1)
				if (this->map[y][x + 1] > 0)
				{
					this->map[y][x] = s;
					s++;
					continue;
				}
		}
	}

}

void Init_map::view_map()
{
	int **map = this->map;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout<<map[i][j]<<' ';
		}
		std::cout << std::endl;
	}
}

int Init_map::getUp(int number)
{
	int **map = this->map;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == number)
			{
				if (i > 0)
					return map[i - 1][j];
				else
					return 0;
			}
		}
	}
}

int Init_map::getDown(int number)
{
	int **map = this->map;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == number)
			{
				if (i < n - 1)
					return map[i + 1][j];
				else
					return 0;
			}
		}
	}
}

int Init_map::getLeft(int number)
{
	int **map = this->map;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == number)
			{
				if (j > 0)
					return map[i][j - 1];
				else
					return 0;
			}
		}
	}
}

int Init_map::getRight(int number)
{
	int **map = this->map;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == number)
			{
				if (j < n - 1)
					return map[i][j + 1];
				else
					return 0;
			}
		}
	}
}

Init_map::~Init_map()
{
	if (this->map != nullptr)
	{
		for (int i = 0; i < n; i++)
		{
			delete[] this->map[i];
		}
	}
	delete[] this->map;
}