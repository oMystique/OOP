#pragma once
#include <string>

enum class Gear
{
	reverse = -1,
	neutral = 0,
	firstGear = 1,
	secondGear = 2,
	thirdGear = 3,
	fourthGear = 4,
	fifthGear = 5
};

class CCar
{
public:
	CCar();
	std::string GetDirection()const;
	void GetInfoAboutCar()const;
	int GetCurrentSpeed()const;
	int GetSelectedGear()const;
	bool EngineIsTurnOn()const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
private:
	Gear m_gear;
	int m_speed;
	bool m_engineIsTurnOn;
};