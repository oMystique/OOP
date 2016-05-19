// FindMaxExTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../FIndMaxEx/FindMaxEx.h"

BOOST_AUTO_TEST_SUITE(FindMax_Tests)

	struct SportMansVector
	{
		std::vector<SportsMan> sportsmansVector = {
			SportsMan("Filipp", "Azisovich", "Kirkorov", 216.5, 50.3),
			SportsMan("Baskov", "Djigurhanyanov", "Nikolay", 100.5, 21.5)	
		};
	};

	BOOST_FIXTURE_TEST_SUITE(find_max_paramathers_in_sportmans_vector, SportMansVector)



	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()