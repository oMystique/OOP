// CarSimulatorTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../CarSimulator/CarSimulator.h"

BOOST_AUTO_TEST_SUITE(testSuiteCarSim)

struct Fixture
{
	Fixture()
	{
		
	}
	~Fixture()
	{
	}
	CCar m_car;
};

BOOST_FIXTURE_TEST_CASE(testTurnOnEngine, Fixture)
{
	BOOST_CHECK_EQUAL(m_car.TurnOnEngine(), true);
	BOOST_CHECK_EQUAL(m_car.TurnOnEngine(), false);
}


BOOST_FIXTURE_TEST_CASE(testTurnOffEngine, Fixture)
{
	BOOST_REQUIRE(m_car.TurnOnEngine());
	BOOST_CHECK_EQUAL(m_car.TurnOffEngine(), true);
	BOOST_CHECK_EQUAL(m_car.TurnOffEngine(), false);
}

BOOST_FIXTURE_TEST_CASE(testSetGear, Fixture)
{
	BOOST_REQUIRE(m_car.TurnOnEngine());
	BOOST_CHECK_EQUAL(m_car.SetGear(0), true);
	BOOST_CHECK_EQUAL(m_car.SetGear(1), true);
	BOOST_CHECK_EQUAL(m_car.SetGear(4), false);
	BOOST_CHECK_EQUAL(m_car.SetGear(-1), true);
	BOOST_CHECK_EQUAL(m_car.SetGear(0), true);
	BOOST_CHECK_EQUAL(m_car.TurnOffEngine(), true);
}

BOOST_FIXTURE_TEST_CASE(testSetSpeedInConnectionWithGear, Fixture)
{
	BOOST_REQUIRE(m_car.TurnOnEngine());
	BOOST_CHECK_EQUAL(m_car.SetSpeed(20), false);
	BOOST_CHECK_EQUAL(m_car.SetSpeed(0), false);

	BOOST_CHECK_EQUAL(m_car.SetGear(1), true);
	BOOST_CHECK_EQUAL(m_car.SetSpeed(30), true);
	BOOST_CHECK_EQUAL(m_car.SetGear(2), true);
	BOOST_CHECK_EQUAL(m_car.SetSpeed(50), true);
	BOOST_CHECK_EQUAL(m_car.SetGear(3), true);
	BOOST_CHECK_EQUAL(m_car.SetSpeed(60), true);
	BOOST_CHECK_EQUAL(m_car.SetGear(4), true);
	BOOST_CHECK_EQUAL(m_car.SetSpeed(90), true);
	BOOST_CHECK_EQUAL(m_car.SetGear(5), true);
	BOOST_CHECK_EQUAL(m_car.SetSpeed(150), true);

	BOOST_CHECK_EQUAL(m_car.SetGear(4), false);

	BOOST_CHECK_EQUAL(m_car.SetSpeed(60), true);
	BOOST_CHECK_EQUAL(m_car.SetGear(3), true);
	BOOST_CHECK_EQUAL(m_car.SetSpeed(30), true);
	BOOST_CHECK_EQUAL(m_car.SetGear(1), true);

	BOOST_CHECK_EQUAL(m_car.SetSpeed(25), true);

	BOOST_CHECK_EQUAL(m_car.SetGear(-1), false);

	BOOST_CHECK_EQUAL(m_car.SetGear(0), true);
	BOOST_CHECK_EQUAL(m_car.SetSpeed(15), true);

	BOOST_CHECK_EQUAL(m_car.SetSpeed(30), false);

	BOOST_CHECK_EQUAL(m_car.SetSpeed(0), true);
	BOOST_CHECK_EQUAL(m_car.TurnOffEngine(), true);
}

BOOST_FIXTURE_TEST_CASE(testSwitchToSendAFirstReversing, Fixture)
{
	BOOST_REQUIRE(m_car.TurnOnEngine());
	BOOST_CHECK_EQUAL(m_car.SetGear(-1), true);
	BOOST_CHECK_EQUAL(m_car.SetSpeed(20), true);
	BOOST_CHECK_EQUAL(m_car.SetGear(0), true);

	BOOST_CHECK_EQUAL(m_car.SetGear(1), false);

	BOOST_CHECK_EQUAL(m_car.SetSpeed(0), true);
	BOOST_CHECK_EQUAL(m_car.SetGear(1), true);

}

BOOST_FIXTURE_TEST_CASE(testSetBigSpeedAboutLowGear, Fixture)
{
	BOOST_REQUIRE(m_car.TurnOnEngine());
	BOOST_CHECK_EQUAL(m_car.SetGear(1), true);

	BOOST_CHECK_EQUAL(m_car.SetSpeed(60), false);
}

BOOST_FIXTURE_TEST_CASE(testTurnOffEngineWithReverseGear, Fixture)
{
	BOOST_REQUIRE(m_car.TurnOnEngine());
	BOOST_CHECK_EQUAL(m_car.SetGear(-1), true);

	BOOST_CHECK_EQUAL(m_car.TurnOffEngine(), false);
	
	BOOST_CHECK_EQUAL(m_car.SetSpeed(10), true);
	BOOST_CHECK_EQUAL(m_car.SetGear(0), true);

	BOOST_CHECK_EQUAL(m_car.TurnOffEngine(), false);

	BOOST_CHECK_EQUAL(m_car.SetSpeed(0), true);
	BOOST_CHECK_EQUAL(m_car.TurnOffEngine(), true);
}

BOOST_FIXTURE_TEST_CASE(testSwitchGearWithNeutralToNeutralWithEngineOff, Fixture)
{
	BOOST_CHECK_EQUAL(m_car.SetGear(0), true);

	BOOST_CHECK_EQUAL(m_car.SetGear(1), false);
	BOOST_CHECK_EQUAL(m_car.SetSpeed(30), false);
}

BOOST_AUTO_TEST_SUITE_END()