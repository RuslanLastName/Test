#pragma once

class Init_map
{
private:
	int **map;
	int room;
	int n;
public:
	Init_map();
	void setN(int n);
	void gen_map();
	void view_map();

	int getUp(int number);
	int getDown(int number);
	int getLeft(int number);
	int getRight(int number);


	~Init_map();
};

