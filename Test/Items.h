#pragma once
#include <string>
class Items
{
private:
	int ID;			//���
	std::string name = "";		//��������
	int number;		//����� �������
	
					//int position;	//����� ���� � �������
	//bool boolean;
public:
	Items();
	Items(int id, std::string Name, int number);
	Items(int id, std::string Name);
	int get_ID();
	std::string get_name();
	int get_number();
	//int get_position();
	void set_number(int Number);
	//void set_position(int Position);
	~Items();
};

