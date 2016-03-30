// CarSimulatorTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../CarSimulator/CarSimulator.h"


struct CarFixture
{
	CCar m_car;
};

BOOST_FIXTURE_TEST_SUITE(Car, CarFixture)

	// двигатель машины изначально выключен
	BOOST_AUTO_TEST_CASE(engine_initially_off)
	{
		BOOST_CHECK(!m_car.EngineIsOn());
	}

	// на нулевой скорости и передаче
	BOOST_AUTO_TEST_CASE(at_zero_speed_and_zero_gear)
	{
		BOOST_CHECK_EQUAL(m_car.GetGear(), 0);
	}

	//	стоит, не двигаясь
	BOOST_AUTO_TEST_CASE(standing_not_moving)
	{
		BOOST_CHECK(m_car.GetDirection() == DirectionMovement::standOnTheSpot);
	}

	// не позволяет сменить передачу
	BOOST_AUTO_TEST_CASE(does_not_allow_change_gear)
	{
		BOOST_CHECK(!m_car.SetGear(1)); 
		BOOST_CHECK_EQUAL(m_car.GetGear(), 0);
	}

	// не позволяет сменить скорость
	BOOST_AUTO_TEST_CASE(does_not_allow_change_speed)
	{
		BOOST_CHECK(!m_car.SetSpeed(10));
		BOOST_CHECK_EQUAL(m_car.GetSpeed(), 0);
	}

	// может быть включен
	BOOST_AUTO_TEST_CASE(may_be_turn_on)
	{
		BOOST_CHECK(m_car.TurnOnEngine());
		BOOST_CHECK(m_car.EngineIsOn());
	}

	struct when_turned_on_ :CarFixture
	{
		when_turned_on_()
		{
			m_car.TurnOnEngine();
		}
	};

	// после включения
	BOOST_FIXTURE_TEST_SUITE(when_turned_on, when_turned_on_)

		// позволяет включить первую передачу
		BOOST_AUTO_TEST_CASE(allows_set_first_gear)
		{
			BOOST_CHECK(m_car.SetGear(1));
			BOOST_CHECK_EQUAL(m_car.GetGear(), 1);
		}

		// позволяет включить заднюю передачу
		BOOST_AUTO_TEST_CASE(allows_set_reverse_gear)
		{
			BOOST_CHECK(m_car.SetGear(-1));
			BOOST_CHECK_EQUAL(m_car.GetGear(), -1);
		}

		// не позволяет переключиться на несуществующую передачу
		BOOST_AUTO_TEST_CASE(It_does_not_allow_the_switch_to_a_non_existent_gear)
		{
			BOOST_CHECK(!m_car.SetGear(20));
			BOOST_CHECK_EQUAL(m_car.GetGear(), 0);
		}

		// не может быть выключен на задней передаче
		BOOST_AUTO_TEST_CASE(can_not_turned_off_on_reverse_gear)
		{
			BOOST_CHECK(m_car.SetGear(-1));
			BOOST_CHECK(!m_car.TurnOffEngine());
		}

		// не может быть выключен на первой передаче
		BOOST_AUTO_TEST_CASE(can_not_turned_off_on_first_gear)
		{
			BOOST_CHECK(m_car.SetGear(1));
			BOOST_CHECK(!m_car.TurnOffEngine());
		}

		// может быть выключен на нейтральной передаче
		BOOST_AUTO_TEST_CASE(can_turned_off_on_neutral_gear)
		{
			BOOST_CHECK(m_car.SetGear(0));
			BOOST_CHECK(m_car.TurnOffEngine());
		}
	BOOST_AUTO_TEST_SUITE_END()

	struct at_1st_gear_ :when_turned_on_
	{
		at_1st_gear_()
		{
			m_car.SetGear(1);
		}
	};

	// на первой скорости
	BOOST_FIXTURE_TEST_SUITE(at_1st_gear, at_1st_gear_)

		// движется вперед если скорость не равна нулю
		BOOST_AUTO_TEST_CASE(allow_moving_forward_if_speed_non_zero)
		{
			BOOST_CHECK(m_car.SetSpeed(1));
			BOOST_CHECK(m_car.GetDirection() == DirectionMovement::movingForward);
		}

		// развивает скорость от 0 до 30
		BOOST_AUTO_TEST_CASE(accelerates_from_0_to_30)
		{
			BOOST_CHECK_EQUAL(m_car.GetSpeed(), 0);
			BOOST_CHECK(m_car.SetSpeed(30));
			BOOST_CHECK(!m_car.SetSpeed(35));
			BOOST_CHECK_EQUAL(m_car.GetSpeed(), 30);
		}

		// позволяет переключиться на нейтральную передачу на заданной скорости
		BOOST_AUTO_TEST_CASE(allow_set_neutral_gear_at_given_speed)
		{
			BOOST_CHECK(m_car.SetSpeed(1));
			BOOST_CHECK(m_car.SetGear(0));
			BOOST_CHECK_EQUAL(m_car.GetGear(), 0);
			BOOST_CHECK_EQUAL(m_car.GetSpeed(), 1);
		}

		// позволяет переключиться на заднюю передачу на нулевой скорости
		BOOST_AUTO_TEST_CASE(allow_set_reverse_gear_at_zero_speed)
		{
			BOOST_CHECK(m_car.SetGear(-1));
			BOOST_CHECK_EQUAL(m_car.GetGear(), -1);
			BOOST_CHECK_EQUAL(m_car.GetSpeed(), 0);
		}

		// позволяет переключиться на заднюю передачу на нулевой скорости
		BOOST_AUTO_TEST_CASE(not_allow_set_reverse_gear_at_non_zero_speed)
		{
			BOOST_CHECK(m_car.SetSpeed(1));
			BOOST_CHECK(!m_car.SetGear(-1));
			BOOST_CHECK_EQUAL(m_car.GetGear(), 1);
			BOOST_CHECK_EQUAL(m_car.GetSpeed(), 1);
		}

		// позволяет переключиться на вторую передачу
		BOOST_AUTO_TEST_CASE(allow_set_2nd_gear)
		{

			BOOST_CHECK(m_car.SetSpeed(21));
			BOOST_CHECK(m_car.SetGear(2));
			BOOST_CHECK_EQUAL(m_car.GetGear(), 2);
			BOOST_CHECK_EQUAL(m_car.GetSpeed(), 21);
		}
	BOOST_AUTO_TEST_SUITE_END()

	struct at_0_gear_in_during_movement_ :at_1st_gear_
	{
		at_0_gear_in_during_movement_()
		{
			m_car.SetSpeed(10);
			m_car.SetGear(0);
		}
	};

	// на 0 передаче во время движения
	BOOST_FIXTURE_TEST_SUITE(at_0_gear_in_during_movement, at_0_gear_in_during_movement_)

		// не позволяет увеличить скорость
		BOOST_AUTO_TEST_CASE(does_not_allow_to_increase_the_speed)
		{
			BOOST_CHECK(!m_car.SetSpeed(20));
			BOOST_CHECK_EQUAL(m_car.GetSpeed(), 10);
		}

		// позволяет уменьшить скорость или оставить прежней
		BOOST_AUTO_TEST_CASE(reduces_the_speed_or_leave_earlier)
		{
			BOOST_CHECK(m_car.SetSpeed(10));
			BOOST_CHECK(m_car.SetSpeed(9));
			BOOST_CHECK_EQUAL(m_car.GetSpeed(), 9);
		}

		// позволяет включить допустимую передачу если скорость позволяет
		BOOST_AUTO_TEST_CASE(enables_the_gear_of_permissible_if_the_speed_allows)
		{
			BOOST_CHECK(m_car.SetGear(1));
			BOOST_CHECK_EQUAL(m_car.GetGear(), 1);
			BOOST_CHECK(m_car.SetSpeed(20));

			BOOST_CHECK(m_car.SetGear(0));
			BOOST_CHECK_EQUAL(m_car.GetGear(), 0);
			BOOST_CHECK_EQUAL(m_car.GetSpeed(), 20);

			BOOST_CHECK(m_car.SetGear(2));
			BOOST_CHECK_EQUAL(m_car.GetGear(), 2);
			BOOST_CHECK_EQUAL(m_car.GetSpeed(), 20);
		}

		// не позволяет выключить двигатель
		BOOST_AUTO_TEST_CASE(does_not_allow_the_engine_to_switch_off)
		{
			BOOST_CHECK(!m_car.TurnOffEngine());
			BOOST_CHECK(m_car.EngineIsOn());
		}

		// не позволяет переключиться на заднюю передачу
		BOOST_AUTO_TEST_CASE(does_not_allow_the_switch_to_reverse_gear)
		{
			BOOST_CHECK(!m_car.SetGear(-1));
			BOOST_CHECK_EQUAL(m_car.GetGear(), 0);
		}
	BOOST_AUTO_TEST_SUITE_END()

	struct at_reverse_gear_in_during_moment_ :when_turned_on_
	{
		at_reverse_gear_in_during_moment_()
		{
			m_car.SetGear(-1);
			m_car.SetSpeed(1);
		}
	};

	// на задней скорости во время движения
	BOOST_FIXTURE_TEST_SUITE(at_reverse_gear_in_during_moment, at_reverse_gear_in_during_moment_)

		// развивает скорость от 0 до 20
		BOOST_AUTO_TEST_CASE(accelerates_from_0_to_20)
		{
			BOOST_CHECK(m_car.SetSpeed(20));
			BOOST_CHECK(!m_car.SetSpeed(35));
			BOOST_CHECK_EQUAL(m_car.GetSpeed(), 20);
		}

		// позволяет переключиться на нейтральную передачу на заданной скорости
		BOOST_AUTO_TEST_CASE(allow_set_neutral_gear_at_given_speed)
		{
			BOOST_CHECK(m_car.SetGear(0));
			BOOST_CHECK_EQUAL(m_car.GetGear(), 0);
			BOOST_CHECK_EQUAL(m_car.GetSpeed(), 1);
		}

		//не позволяет выключить двигатель
		BOOST_AUTO_TEST_CASE(does_not_allow_the_engine_to_switch_off)
		{
			BOOST_CHECK(!m_car.TurnOffEngine());
			BOOST_CHECK(m_car.EngineIsOn());
		}

		//не позволяет переключиться на первую передачу
		BOOST_AUTO_TEST_CASE(does_not_allow_set_first_gear)
		{
			BOOST_CHECK(!m_car.SetGear(1));
			BOOST_CHECK_EQUAL(m_car.GetGear(), -1);
		}

		//движется назад
		BOOST_AUTO_TEST_CASE(moving_backward)
		{
			BOOST_CHECK(m_car.GetDirection() == DirectionMovement::movingBackward);
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()