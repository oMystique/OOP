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

struct RangesVector
{
	int min;
	int max;
};

class CCar
{
public:
	CCar();
	void GetInfoAboutCar()const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
private:
	RangesVector GetRangeOfSpeeds(int gear)const;
	bool SpeedInGearRange(int gear, int speed)const;
	bool SwitchToReverseGearIsPossible(int gear)const;
	std::string GetDirection()const;
private:
	Gear m_gear;
	int m_speed;
	bool m_engineIsTurnOn;
	bool m_switchFromReverseToNeutral;
};