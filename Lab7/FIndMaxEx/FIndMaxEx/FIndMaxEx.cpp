/*
Champions list for fast start:

Filipp Azisovich Kirkorov 216.5 50.3
Nikolay Batkovich Baskov 100.5 21.5
Albert Shamilevich Djigarhanyan 167 214
*/

#include "stdafx.h"
#include <iostream>
#include "FindMaxEx.h"
#include <fstream>

using namespace std;

void PrintInfoAboutSportsman(SportsMan const &sportsman)
{
	cout << "First name: " << sportsman.firstName << endl;
	cout << "Middle name: " << sportsman.middleName << endl;
	cout << "Last name: " << sportsman.lastName << endl;
	cout << "Weight: " << sportsman.weight << endl;
	cout << "Height: " << sportsman.height << endl;
}

int main()
{
	string inputStr;
	vector<SportsMan> sportsmans;

	while (cin)
	{
		SportsMan sportsman;
		cin >> sportsman;
		sportsmans.push_back(sportsman);
	}

	cout << "===Sportsman with max height===" << endl;
	SportsMan sportsmanWIthMaxHeight;
	if (FindMax(sportsmans, sportsmanWIthMaxHeight, [](auto sportsman1, auto sportsman2) {
		return sportsman1.height < sportsman2.height;
	}))
	{
		PrintInfoAboutSportsman(sportsmanWIthMaxHeight);
	}
	cout << endl;

	cout << "===Sportsman with max weight===" << endl;
	SportsMan sportsmanWIthMaxWeight;
	if (FindMax(sportsmans, sportsmanWIthMaxWeight, [](auto sportsman1, auto sportsman2) {
		return sportsman1.weight < sportsman2.weight;
	}))
	{
		PrintInfoAboutSportsman(sportsmanWIthMaxWeight);
	}

    return 0;
}

