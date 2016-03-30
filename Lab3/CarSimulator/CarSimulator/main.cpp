#include "stdafx.h"
#include "CarSimulator.h"
#include <iostream>
#include <sstream>

using namespace std;

void GetInformationAboutCarSpeed(CCar const &car)
{
	cout << "Speed: " << car.GetSpeed() << endl;
}

void GetInformationAboutCarGear(CCar const &car)
{
	cout << "Gear: " << car.GetGear() << endl;
}

void GetInformationAboutEngineStatus(CCar const &car)
{
	if (car.EngineIsOn())
	{
		cout << "Engine is on." << endl;
	}
	else
	{
		cout << "Engine is off." << endl;
	}
}

void GetInformationAboutDirection(CCar const &car)
{
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
}

void GetInformationAboutCar(CCar const &car)
{
	cout << "===" << endl;
	GetInformationAboutEngineStatus(car);
	GetInformationAboutCarGear(car);
	GetInformationAboutDirection(car);
	GetInformationAboutCarSpeed(car);
	cout << "===" << endl;
}

void SetParamether(CCar &car, string const &command, int value)
{
	if (command == "SetGear")
	{
		car.SetGear(value);
		GetInformationAboutCarGear(car);
	}
	else if (command == "SetSpeed")
	{
		car.SetSpeed(value);
		GetInformationAboutCarSpeed(car);
	}
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
			GetInformationAboutCar(car);
		}
		else if (inputString == "EngineOn")
		{
			car.TurnOnEngine();
			GetInformationAboutEngineStatus(car);
		}
		else if (inputString == "EngineOff")
		{
			car.TurnOffEngine();
			GetInformationAboutEngineStatus(car);
		}
		else
		{
			istringstream strStream(inputString);
			string command;
			string value;
			strStream >> command;
			strStream >> value;

			SetParamether(car, command, atoi(value.c_str()));
		}
	} while (!inputString.empty());
}

int main()
{
	InteractWithUser();
	return 0;
}
