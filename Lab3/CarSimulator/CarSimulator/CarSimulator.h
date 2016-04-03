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

enum class DirectionMovement
{
	movingBackward = -1,
	standOnTheSpot = 0,
	movingForward = 1
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
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

	int GetSpeed()const;
	int GetGear()const;

	bool EngineIsOn()const;
	DirectionMovement GetDirection()const;
private:
	RangesVector GetRangeOfSpeeds(Gear gear)const;
	bool SpeedInGearRange(Gear gear, int speed)const;
	bool SwitchToReverseGearIsPossible()const;
private:
	Gear m_gear;
	int m_speed;
	bool m_engineIsTurnOn;
};