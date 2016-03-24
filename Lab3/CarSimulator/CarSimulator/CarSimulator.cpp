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
	m_engineIsTurnOn(false),
	m_switchFromReverseToNeutral(false)
{
}

RangesVector CCar::GetRangeOfSpeeds(int gear)const
{
	switch (gear)
	{
	case (static_cast<int>(Gear::reverse)) :
		return{ 0, 20 };
	case (static_cast<int>(Gear::neutral)) :
		return{ 0, INT_MAX };
	case (static_cast<int>(Gear::firstGear)) :
		return{ 0, 30 };
	case (static_cast<int>(Gear::secondGear)) :
		return{ 20, 50 };
	case (static_cast<int>(Gear::thirdGear)) :
		return{ 30, 60 };
	case (static_cast<int>(Gear::fourthGear)) :
		return{ 40, 90 };
	case (static_cast<int>(Gear::fifthGear)) :
		return{ 50, 150 };
	}
	return{ 0, 0 };
}


bool CCar::SpeedInGearRange(int gear, int speed)const
{
	return ((GetRangeOfSpeeds(gear).min <= speed) && (speed <= GetRangeOfSpeeds(gear).max));
}

void CCar::GetInfoAboutCar()const
{
	if (m_engineIsTurnOn)
	{
		cout << "Engine is turn on." << endl;
	}
	else
	{
		cout << "Engine is turn off." << endl;
	}
	cout << GetDirection() << endl;
	cout << "Speed: " << m_speed << endl;
	cout << "Gear: " << static_cast<int>(m_gear) << endl;
}

bool CCar::SwitchToReverseGearIsPossible(int gear)const
{
	return ((gear == static_cast<int>(Gear::reverse)) &&
		((((m_gear == Gear::neutral) || (m_gear == Gear::firstGear)) && (m_speed == 0)) ||
			(m_gear == Gear::reverse)));
}

bool CCar::SetGear(int gear)
{
	auto gearType = static_cast<Gear>(gear);
	if (m_engineIsTurnOn)
	{
		if (SwitchToReverseGearIsPossible(gear))
		{
			m_gear = Gear::reverse;
			return true;
		}
		else if (m_gear == Gear::reverse)
		{
			if (gearType == (Gear::firstGear) && (m_speed == 0))
			{
				m_gear = Gear::firstGear;
				return true;
			}
			else if (gearType == Gear::neutral)
			{
				if (m_speed > 0)
				{
					m_switchFromReverseToNeutral = true;
				}
				m_gear = Gear::neutral;
				return true;
			}
		}
		else if (SpeedInGearRange(gear, m_speed) && (!m_switchFromReverseToNeutral))
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
		if ((m_switchFromReverseToNeutral) && (speed == 0))
		{
			m_switchFromReverseToNeutral = false;
		}
		if (((m_gear == Gear::neutral) && (speed < m_speed)) ||
			(SpeedInGearRange(static_cast<int>(m_gear), speed) && (m_gear != Gear::neutral)))
		{
			m_speed = speed;
			return true;
		}
	}
	return false;
}

string CCar::GetDirection()const
{
	if (m_speed == 0)
	{
		return "Stand on the spot.";
	}
	else if (m_gear != Gear::reverse)
	{
		return "Moving forward.";
	}
	else 
	{
		return "Moving back.";
	}
	return "";
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