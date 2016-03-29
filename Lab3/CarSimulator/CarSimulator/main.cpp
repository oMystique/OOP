#include "stdafx.h"
#include "CarSimulator.h"
#include <iostream>
#include <sstream>

using namespace std;

void GetInfoAboutCar(CCar const &car)
{
	cout << "===" << endl;

	if (car.EngineIsOn())
	{
		cout << "Engine is on." << endl;
	}
	else
	{
		cout << "Engine is off." << endl;
	}

	cout << "Gear: " << car.GetGear() << endl;

	switch (car.GetDirection())
	{
	case DirectionMovement::movingBackward:
		cout << "Car moving backward." << endl;
		break;

	case DirectionMovement::standOnTheSpot:
		cout << "Car is stand on the spot." << endl;
		break;

	case DirectionMovement::movingForward:
		cout << "Car moving forward." << endl;
		break;
	}

	cout << "Speed: " << car.GetSpeed() << endl;

	cout << "===" << endl;
}

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
			GetInfoAboutCar(car);
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
