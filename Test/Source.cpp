#include <iostream>
#include <conio.h>
#include <string>
#include "Init_map.h"//map generator
#include "Room.h"//create rooms
#include "Items.h"
#include "Inventory.h"

using namespace std;



int main(int args, char** argv)
{
	const int N = 10;
	//generation the map
	Init_map map;
	Room room[N];
	Inventory person;
	//add items
	string chest = "chest";
	string key = "key";

	Items items[5];
	items[0] = { -2, chest, 3 };
	items[1] = { -3, key, 5 };
	items[2] = { -3, key, 4 };
	items[3] = { -3, key, 7 };
	items[4] = { -3, key, 9 };
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
	for (int i = 0; i < N; i++)
	{
		room[i].set_number(i + 1);
		int t = room[i].get_number();
		room[i].set_doors(map.getUp(t), map.getDown(t), map.getLeft(t), map.getRight(t));
		room[i].view_room();
	}
	//add items in the rooms
	for (int i = 0; i < 5; i++)
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
	/*cin.getline(c, 20);
	cout << items[0].get_name() << endl;
	cout << items[1].get_name() << endl;
	room[begin].Input(c, items);
	cout << items[0].get_name() << endl;
	cout << items[1].get_name() << endl;
	*/
	int getvalue = 0;
	while (steps > 0)
	{
		do
		{
			cin.getline(c, 20);
		} while (c[0] == '\0');
		next = room[begin].get_door(c[0]);
		getvalue = room[begin].Input(c, items);

		if (getvalue != 0)
		{
			switch (getvalue)
			{
			case -2: {
				person.add_itemc('$');
				person.del_key('%');
			}break;//chest
			case -3:person.add_itemc('%'); break;//key
			}
		}
			
		next -= 1;
		room[next].view_room();
		begin = next;//if all good to do it
		steps--;
		cout << getvalue << endl;
		person.show_items();
		//cout << items[0].get_name() << endl;
		//cout << items[1].get_name() << endl;
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