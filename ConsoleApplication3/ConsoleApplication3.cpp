#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

void question();

struct ZNAK
{
	std::string name = "-----"; //фамилия, имя
	std::string zod = "-----"; //знак зодиака
	unsigned short date[3] = { 30000, 30000, 30000 }; //число, месяц, год

	std::string getString()
	{
		if (date[0] != 30000 && date[1] != 30000 && date[2] != 30000)
			return  name + "\n" + std::to_string(date[2]) + "." + std::to_string(date[1]) + "." + std::to_string(date[0]) + "\n" + zod + "\n\n";
		else
			return  name + "\n-----\n" + zod + "\n\n";
	}

	void setName(std::string str) { name = str; }
};

const int mSize = 10;
ZNAK mass[mSize];

std::string signs[] = { "oven", "rak", "scorp", "lev" };

void insertData()
{
	int i = 0;
	std::string input;
	while (i > 10 || i < 1)
	{
		std::cout << "Select a position in the list to edit (1-10)\n";
		std::cin >> input;
		if (atoi(input.c_str())) i = std::stoi(input);
	}
	std::cout << "Enter new person NAME and SECONDNAME\n";
	std::getline(std::cin >> std::ws, mass[i - 1].name);
	std::cout << "Enter birthday date (year >> mounth >> day)\n";
	for (int j = 0; j < 3; j++) std::cin >> mass[i - 1].date[j];
	std::cout << "Enter Zodiac sign\n";
	std::cin >> mass[i - 1].zod;
	std::cout << "Person data saved\n";

	std::cout << mass[i - 1].getString();

	question();
}

void sortByDate()
{
	ZNAK temp;
	for (int i = 0; i < mSize; i++)
	{
		for (int j = 0; j < mSize - i; j++)
		{
			if (mass[j].date[0] > mass[j + 1].date[0])
			{
				temp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = temp;
			}
			else if (mass[j].date[0] == mass[j + 1].date[0] && mass[j].date[1] > mass[j + 1].date[1])
			{
				temp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = temp;
			}
			else if (mass[j].date[0] == mass[j + 1].date[0] && mass[j].date[1] == mass[j + 1].date[1] && mass[j].date[2] > mass[j + 1].date[2])
			{
				temp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = temp;
			}
		}
	}
}

void find(std::string zod)
{
	std::cout << "\nSearching results:\n";
	int matches = 0;
	for (int i = 0; i < mSize; i++)
	{
		if (mass[i].zod == zod)
		{
			std::cout << mass[i].getString();
			matches++;
		}
	}
	if (matches == 0) std::cout << "No matches found\n\n";
}

void generate()
{
	srand(time(0));

	for (int i = 0; i < mSize; i++)
	{
		mass[i].name = "p" + std::to_string(i + 1);
		mass[i].date[0] = 1995 + rand() % 6;
		mass[i].date[1] = rand() % 12 + 1;
		mass[i].date[2] = rand() % 30 + 1;
		mass[i].zod = signs[rand() % 4];
	}
}

void question()
{
	std::cout << "Chose option: 'edit' - rewrite chosen position in the list, 'print' - print data list,\n 'find' - find persons with certain zodiak sign, 'gen' - generate random list\n";
	std::string chosing;
	std::cin >> chosing;

	if (chosing == "edit")
	{
		insertData();
	}
	else if (chosing == "print")
	{
		sortByDate();
		std::cout << "Person data list:\n\n";
		for (int i = 0; i < mSize; i++) std::cout << mass[i].getString();
		question();
	}
	else if (chosing == "find")
	{
		std::cout << "Enter zodiak sign to find:\n";
		std::string target;
		std::cin >> target;
		find(target);
		question();
	}
	else if (chosing == "gen")
	{
		generate();
		question();
	}
	else
	{
		std::cout << "No such command\n";
		question();
	}
}

int main()
{
	question();
}
