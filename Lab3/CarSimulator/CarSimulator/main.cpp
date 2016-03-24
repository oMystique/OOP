#include "stdafx.h"
#include "CarSimulator.h"
#include <iostream>
#include <sstream>

using namespace std;



void InteractWithUser()
{
	CCar car;
	string inputString;
	do
	{
		cout << "Input command: ";
		getline(cin, inputString);
		if (inputString == "Info")
		{
			car.GetInfoAboutCar();
		}
		else if (inputString == "EngineOn")
		{
			car.TurnOnEngine();
		}
		else if (inputString == "EngineOff")
		{
			car.TurnOffEngine();
		}
		else
		{
			istringstream strStream(inputString);
			string command;
			string value;
			strStream >> command;
			strStream >> value;
			if (command == "SetGear")
			{
				car.SetGear(atoi(value.c_str()));
			}
			else if (command == "SetSpeed")
			{
				car.SetSpeed(atoi(value.c_str()));
			}
		}
	} while (!inputString.empty());
}

int main()
{
	InteractWithUser();
	return 0;
}
