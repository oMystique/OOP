// CarSimulator.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CarSimulator.h"
#include <climits>
#include <iostream>

using namespace std;

CCar::CCar() :
	m_gear(Gear::neutral),
	m_speed(0),
	m_engineIsTurnOn(false)
{
}

RangesVector CCar::GetRangeOfSpeeds(Gear gear)const
{
	switch (gear)
	{
	case (Gear::reverse) :
		return{ 0, 20 };

	case (Gear::neutral) :
		return{ 0, INT_MAX };

	case (Gear::firstGear) :
		return{ 0, 30 };

	case (Gear::secondGear) :
		return{ 20, 50 };

	case (Gear::thirdGear) :
		return{ 30, 60 };

	case (Gear::fourthGear) :
		return{ 40, 90 };

	case (Gear::fifthGear) :
		return{ 50, 150 };
	}

	return{ INT_MAX, INT_MAX };
}


bool CCar::SpeedInGearRange(Gear gear, int speed)const
{
	return ((GetRangeOfSpeeds(gear).min <= speed) && (speed <= GetRangeOfSpeeds(gear).max));
}

bool CCar::SwitchToReverseGearIsPossible()const
{
	return (((((m_gear == Gear::neutral) || (m_gear == Gear::firstGear)) && (m_speed == 0)) ||
			(m_gear == Gear::reverse)));
}

bool CCar::SetGear(int gear)
{
	auto gearType = static_cast<Gear>(gear);
	if (m_engineIsTurnOn)
	{
		if ((gearType == Gear::reverse) 
			&& SwitchToReverseGearIsPossible())
		{
			m_gear = Gear::reverse;
			return true;
		}
		else if (m_gear == Gear::reverse)
		{
			if ((gearType == Gear::firstGear)
				&& (m_speed == 0))
			{
				m_gear = Gear::firstGear;
				return true;
			}
			else if (gearType == Gear::neutral)
			{
				m_gear = Gear::neutral;
				return true;
			}
		}
		else if (SpeedInGearRange(gearType, m_speed) 
			&& (gearType != Gear::reverse))
		{
			m_gear = gearType;
			return true;
		}
	}
	else if (gearType == Gear::neutral)
	{
		return true;
	}
	return false;
}

bool CCar::SetSpeed(int speed)
{
	if (m_engineIsTurnOn)
	{
		if (((m_gear == Gear::neutral) && (abs(speed) <= abs(m_speed)))
			|| (SpeedInGearRange(m_gear, abs(speed)) && (m_gear != Gear::neutral)))
		{
			auto direction = DirectionMovement::movingForward;
			if ((m_speed < 0) || (m_gear == Gear::reverse))
			{
				direction = DirectionMovement::movingBackward;
			}
			m_speed = speed * static_cast<int>(direction);
			return true;
		}
	}
	return false;
}

int CCar::GetSpeed()const
{
	return abs(m_speed);
}

int CCar::GetGear()const
{
	return static_cast<int>(m_gear);
}

bool CCar::EngineIsOn()const
{
	return m_engineIsTurnOn;
}

DirectionMovement CCar::GetDirection()const
{
	if (m_speed > 0)
	{
		return DirectionMovement::movingForward;
	}
	else if (m_speed < 0)
	{
		return DirectionMovement::movingBackward;
	}
	return DirectionMovement::standOnTheSpot;
}

bool CCar::TurnOnEngine()
{
	if (!m_engineIsTurnOn)
	{
		m_engineIsTurnOn = true;
		return true;
	}
	return false;
}

bool CCar::TurnOffEngine()
{
	if (m_engineIsTurnOn &&
		(m_gear == Gear::neutral) && 
		(m_speed == 0))
	{
		m_engineIsTurnOn = false;
		return true;
	}
	return false;
}