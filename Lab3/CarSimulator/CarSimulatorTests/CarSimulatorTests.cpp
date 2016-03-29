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

BOOST_FIXTURE_TEST_CASE(testTurnOnTheCarsEngine, Fixture)
{
	BOOST_CHECK(m_car.TurnOnEngine() == true);
	BOOST_CHECK(m_car.TurnOnEngine() == false);
}

BOOST_FIXTURE_TEST_CASE(testTurnOffTheCarsEngine, Fixture)
{
	BOOST_CHECK(m_car.EngineIsOn() == false);

	BOOST_CHECK(m_car.TurnOnEngine() == true);
	BOOST_CHECK(m_car.EngineIsOn() == true);

	BOOST_CHECK(m_car.TurnOffEngine() == true);
	BOOST_CHECK(m_car.EngineIsOn() == false);
}

BOOST_FIXTURE_TEST_CASE(testAutoStatusWithOffEngine, Fixture)
{
	BOOST_CHECK(m_car.EngineIsOn() == false);

	BOOST_CHECK(m_car.GetGear() == 0);
	BOOST_CHECK(m_car.GetSpeed() == 0);
	BOOST_CHECK(m_car.GetDirection() == DirectionMovement::standOnTheSpot);
}

BOOST_FIXTURE_TEST_CASE(testReStartingEngine, Fixture)
{
	BOOST_CHECK(m_car.EngineIsOn() == false);

	BOOST_CHECK(m_car.TurnOnEngine() == true);
	BOOST_CHECK(m_car.EngineIsOn() == true);

	BOOST_CHECK(m_car.TurnOnEngine() == false);
	BOOST_CHECK(m_car.EngineIsOn() == true);
}

BOOST_FIXTURE_TEST_CASE(testReOffEngine, Fixture)
{
	BOOST_CHECK(m_car.EngineIsOn() == false);

	BOOST_CHECK(m_car.TurnOnEngine() == true);
	BOOST_CHECK(m_car.EngineIsOn() == true);

	BOOST_CHECK(m_car.TurnOffEngine() == true);
	BOOST_CHECK(m_car.EngineIsOn() == false);

	BOOST_CHECK(m_car.TurnOffEngine() == false);
	BOOST_CHECK(m_car.EngineIsOn() == false);
}

BOOST_FIXTURE_TEST_CASE(testTurnOffCarsEngineWithNonZeroGear, Fixture)
{
	BOOST_REQUIRE(m_car.TurnOnEngine());

	BOOST_CHECK(m_car.SetGear(1) == true);
	BOOST_CHECK(m_car.TurnOffEngine() == false);
	BOOST_CHECK(m_car.EngineIsOn() == true);
}

BOOST_FIXTURE_TEST_CASE(testTurnOffCarsEngineWithNonZeroSpeedAndZeroGear, Fixture)
{
	BOOST_REQUIRE(m_car.TurnOnEngine());

	BOOST_CHECK(m_car.SetGear(1) == true);
	BOOST_CHECK(m_car.SetSpeed(1) == true);
	BOOST_CHECK(m_car.SetGear(0) == true);
	BOOST_CHECK(m_car.TurnOffEngine() == false);
	BOOST_CHECK(m_car.EngineIsOn() == true);
}

BOOST_FIXTURE_TEST_CASE(testSetGearWithOffCarsEngine, Fixture)
{
	BOOST_CHECK(m_car.EngineIsOn() == false);
	BOOST_CHECK(m_car.SetGear(1) == false);
}

BOOST_FIXTURE_TEST_CASE(testSetGearWithOnCarsEngine, Fixture)
{
	BOOST_REQUIRE(m_car.TurnOnEngine());
	BOOST_CHECK(m_car.EngineIsOn() == true);
	BOOST_CHECK(m_car.SetGear(1) == true);
}

BOOST_FIXTURE_TEST_CASE(testSetReverseFromNeutralGearAtZeroSpeed, Fixture)
{
	BOOST_REQUIRE(m_car.TurnOnEngine());
	BOOST_CHECK(m_car.GetSpeed() == 0);
	BOOST_CHECK(m_car.GetGear() == 0);
	BOOST_CHECK(m_car.SetGear(-1) == true);
	BOOST_CHECK(m_car.GetGear() == -1);
}

BOOST_FIXTURE_TEST_CASE(testSetReverseFromNeutralGearAtNonZeroSpeed, Fixture)
{
	BOOST_REQUIRE(m_car.TurnOnEngine());

	BOOST_CHECK(m_car.SetGear(1) == true);
	BOOST_CHECK(m_car.SetSpeed(10) == true);
	BOOST_CHECK(m_car.GetSpeed() == 10);
	BOOST_CHECK(m_car.GetGear() == 1);

	BOOST_CHECK(m_car.SetGear(0) == true);
	BOOST_CHECK(m_car.GetGear() == 0);

	BOOST_CHECK(m_car.SetGear(-1) == false);

	BOOST_CHECK(m_car.GetGear() == 0);
	BOOST_CHECK(m_car.GetDirection() == DirectionMovement::movingForward);
}

BOOST_FIXTURE_TEST_CASE(testSetReverseFromFirstGearAtZeroSpeed, Fixture)
{
	BOOST_REQUIRE(m_car.TurnOnEngine());
	BOOST_CHECK(m_car.SetGear(1) == true);
	BOOST_CHECK(m_car.SetSpeed(10) == true);
	BOOST_CHECK(m_car.GetSpeed() == 10);
	BOOST_CHECK(m_car.GetGear() == 1);
	BOOST_CHECK(m_car.SetSpeed(0) == true);
	BOOST_CHECK(m_car.GetSpeed() == 0);
	BOOST_CHECK(m_car.GetGear() == 1);

	BOOST_CHECK(m_car.SetGear(-1) == true);
	BOOST_CHECK(m_car.GetGear() == -1);

	BOOST_CHECK(m_car.GetDirection() == DirectionMovement::standOnTheSpot);
}

BOOST_FIXTURE_TEST_CASE(testSetReverseFromFirstGearAtNonZeroSpeed, Fixture)
{
	BOOST_REQUIRE(m_car.TurnOnEngine());

	BOOST_CHECK(m_car.SetGear(1) == true);
	BOOST_CHECK(m_car.SetSpeed(10) == true);
	BOOST_CHECK(m_car.GetSpeed() == 10);
	BOOST_CHECK(m_car.GetGear() == 1);

	BOOST_CHECK(m_car.SetGear(-1) == false);

	BOOST_CHECK(m_car.GetGear() == 1);
	BOOST_CHECK(m_car.GetDirection() == DirectionMovement::movingForward);
}

BOOST_FIXTURE_TEST_CASE(testSetSpeedWithOffCarsEngine, Fixture)
{
	BOOST_CHECK(m_car.EngineIsOn() == false);
	BOOST_CHECK(m_car.SetSpeed(1) == false);
}

BOOST_FIXTURE_TEST_CASE(testSetSpeedOnFirstGear, Fixture)
{
	BOOST_REQUIRE(m_car.TurnOnEngine());
	BOOST_REQUIRE(m_car.SetGear(1));

	BOOST_CHECK(m_car.SetSpeed(3) == true);
	BOOST_CHECK(m_car.GetSpeed() == 3);
}

BOOST_FIXTURE_TEST_CASE(testSetImpossibleSpeedOnFirstGear, Fixture)
{
	BOOST_REQUIRE(m_car.TurnOnEngine());
	BOOST_REQUIRE(m_car.SetGear(1));

	BOOST_CHECK(m_car.SetSpeed(60) == false);
	BOOST_CHECK(m_car.GetSpeed() == 0);
}

BOOST_FIXTURE_TEST_CASE(testSetNeutralFromFirstGearOnNonZeroSpeed, Fixture)
{
	BOOST_REQUIRE(m_car.TurnOnEngine());
	BOOST_REQUIRE(m_car.SetGear(1));
	BOOST_REQUIRE(m_car.SetSpeed(10));

	BOOST_CHECK(m_car.SetGear(0) == true);

	BOOST_CHECK(m_car.GetSpeed() == 10);
	BOOST_CHECK(m_car.GetGear() == 0);
}

BOOST_FIXTURE_TEST_CASE(testIncreaseSpeedOnNeutralGear, Fixture)
{
	BOOST_REQUIRE(m_car.TurnOnEngine());

	BOOST_CHECK(m_car.GetSpeed() == 0);
	BOOST_CHECK(m_car.GetGear() == 0);

	BOOST_CHECK(m_car.SetSpeed(1) == false);
}

BOOST_FIXTURE_TEST_CASE(testLoweringSpeedOnNeutralGear, Fixture)
{
	BOOST_REQUIRE(m_car.TurnOnEngine());
	BOOST_REQUIRE(m_car.SetGear(1));
	BOOST_REQUIRE(m_car.SetSpeed(10));

	BOOST_CHECK(m_car.GetSpeed() == 10);
	BOOST_CHECK(m_car.GetGear() == 1);
	BOOST_CHECK(m_car.SetGear(0) == true);

	BOOST_CHECK(m_car.SetSpeed(5) == true);
	BOOST_CHECK(m_car.SetSpeed(0) == true);
}

BOOST_FIXTURE_TEST_CASE(testTryMovingBackwardWhenTheActualDrivingForward, Fixture)
{
	BOOST_CHECK(m_car.TurnOnEngine() == true);
	BOOST_CHECK(m_car.SetGear(1) == true);
	BOOST_CHECK(m_car.SetSpeed(3) == true);

	BOOST_CHECK(m_car.SetGear(-1) == false);
	BOOST_CHECK(m_car.GetDirection() != DirectionMovement::movingBackward);
}

BOOST_FIXTURE_TEST_CASE(testTryMovingForwardWhenTheActualDrivingBackWard, Fixture)
{
	BOOST_CHECK(m_car.TurnOnEngine() == true);
	BOOST_CHECK(m_car.SetGear(-1) == true);
	BOOST_CHECK(m_car.SetSpeed(3) == true);

	BOOST_CHECK(m_car.SetGear(1) == false);
	BOOST_CHECK(m_car.GetDirection() == DirectionMovement::movingBackward);
}

BOOST_AUTO_TEST_SUITE_END()