#include <iostream>
#include <conio.h>
#include <string>
#include "Init_map.h"//map generator
#include "Room.h"//create rooms
#include "Items.h"


using namespace std;

int main(int args, char** argv)
{
	//generation the map
	Init_map map;
	Room room[10];
	
	//add items
	string chest = "chest";
	string key = "key";

	Items items[2];
	items[0] = { -2, chest, 3 };
	items[1] = { -3, key, 5 };

	//variables for work
	int n;
	int begin = 0;
	int next;
	char c[20];
	int steps;
	
	//generate 
	cout << "Enter the amount of the rooms: ";
	cin >> n;
	map.setN(n);
	map.gen_map();
	map.view_map();
	steps = (n / 2) * 3;
	//initialize
	for (int i = 0; i < 10; i++)
	{
		room[i].set_number(i + 1);
		int t = room[i].get_number();
		room[i].set_doors(map.getUp(t), map.getDown(t), map.getLeft(t), map.getRight(t));
		room[i].view_room();
	}
	//add items in the rooms
	for (int i = 0; i < 2; i++)
	{
		int t = items[i].get_number();
		int id = items[i].get_ID();
		room[t].set_item(id);
		room[t].view_room();
		//cout << items[i]->get_name() << endl;
	}
	
	//begin the game
	cout << "Enter the any key to continue!" << endl;
	_getch();
	//system("cls");
	cout << "you in the room [" << begin + 1 << ']' << endl;
	room[begin].view_room();

	while (steps > 0)
	{
		do
		{
			cin.getline(c, 20);
		} while (c[0] == '\0');
		next = room[begin].get_door(c[0]);
		room[begin].Input(c, items);
		next -= 1;
		room[next].view_room();
		begin = next;//if all good to do it
		steps--;
	}

/*
	do
	{
		cin.getline(c, 20);
	} while (c[0] == '\0');
	next = room[begin].get_door(c[0]);
	room[begin].Input(c, *items);
	next -= 1;
	room[next].view_room();
	begin = next;//if all good to do it

	do
	{
		cin.getline(c, 20);
	} while (c[0] == '\0');
	next = room[begin].get_door(c[0]);
	room[begin].Input(c, *items);
	next -= 1;
 	room[next].view_room();
	begin = next;//if all good to do it

	do
	{
		cin.getline(c, 20);
	} while (c[0] == '\0');
	next = room[begin].get_door(c[0]);
	room[begin].Input(c, *items);
	next -= 1;
	room[next].view_room();
	begin = next;//if all good to do it

	do
	{
		cin.getline(c, 20);
	} while (c[0] == '\0');
	next = room[begin].get_door(c[0]);
	room[begin].Input(c, *items);
	next -= 1;
	room[next].view_room();
	begin = next;//if all good to do it
*/
	_getch();

	//for (int i = 0; i < 2; i++)
		//delete items[i];

	return 0;

}