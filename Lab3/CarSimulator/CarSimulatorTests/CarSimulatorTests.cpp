// CarSimulatorTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../CarSimulator/CarSimulator.h"

BOOST_AUTO_TEST_SUITE(testSuiteDictionary)

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

BOOST_FIXTURE_TEST_CASE(testParseFileInDictionary, Fixture)
{
	BOOST_CHECK_EQUAL(false, false);
}


BOOST_AUTO_TEST_SUITE_END()