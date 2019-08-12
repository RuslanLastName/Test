#pragma once
#include "Items.h"
class Room
{
private:
	static const int N = 5;
	int number;
	int left;
	int right;
	int up;
	int down;
	int x;
	int y;
	int view[N][N];
	int pos[4] = { -1,-1,-1,-1 };
	
	static int px;
	static int py;
	int pleft;
	int pright;
	int pup;
	int pdown;
public:
	Room();
	void view_room();
	void set_number(int number);
	int get_number();
	void set_doors(int up, int down, int left, int right);
	int get_door(char c);
	int Input(char *c, Items items[], bool itemb);
	void update_view();
	int getUp();
	int getDown();
	int getLeft();
	int getRight();
	void set_item(int ID);
	int get_item();
	void setPerson();
	char movePerson(char c);


	~Room();
};


