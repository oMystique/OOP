// CarSimulator.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CarSimulator.h"

using namespace std;

CCar::CCar() :
	m_gear(Gear::neutral),
	m_speed(0),
	m_engineIsTurnOn(false)
{
}

void CCar::GetInfoAboutCar()const
{

}

bool CCar::SetGear(int gear)
{

}

bool CCar::SetSpeed(int speed)
{

}

string CCar::GetDirection()const
{
	if (m_speed == 0)
	{
		return "Stand on the spot.";
	}
	else if (m_speed > 0)
	{
		return "Moving forward.";
	}
	else if (m_speed < 0)
	{
		return "Moving back.";
	}
	return "";
}

int CCar::GetSelectedGear()const
{
	return static_cast<int>(m_gear);
}

int CCar::GetCurrentSpeed()const
{
	return m_speed;
}

bool CCar::EngineIsTurnOn()const
{
	return m_engineIsTurnOn;
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
	if (m_engineIsTurnOn)
	{
		m_engineIsTurnOn = false;
		return true;
	}
	return false;
}