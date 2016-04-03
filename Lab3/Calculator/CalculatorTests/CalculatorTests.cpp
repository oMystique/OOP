// CalculatorTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Calculator/calculator.h"

struct CalculatorFixture
{
	CCalculator calc;
};

BOOST_FIXTURE_TEST_SUITE(Calculator, CalculatorFixture)

	//можно объявить новую переменную с заданным именем	
	BOOST_AUTO_TEST_CASE(can_declare_new_var_with_given_name)
	{
		BOOST_CHECK(calc.SetVarIdentifier("y"));
	}

	//если переменная не объявлена, то функция получения значения вернет нам соответствующее значение
	BOOST_AUTO_TEST_CASE(if_var_does_not_exist_get_value_return_non_exist_paramether)
	{
		BOOST_CHECK_EQUAL(calc.GetVarValue("y"), VAL_NOT_EXISTING);
	}

	//если переменная не создана явно, то при попытке присвоить значение - она создастся
	BOOST_AUTO_TEST_CASE(if_var_does_not_exist_its_created)
	{
		BOOST_CHECK_EQUAL(calc.GetVarValue("x"), VAL_NOT_EXISTING);
		BOOST_CHECK(calc.SetVarValue("x", "123"));
		BOOST_CHECK_EQUAL(calc.GetVarValue("x"), 123);
	}

	//имя переменной не может быть пустым
	BOOST_AUTO_TEST_CASE(var_name_can_not_be_empty)
	{
		BOOST_CHECK(!calc.SetVarIdentifier(""));
		BOOST_CHECK(!calc.SetVarValue("", "20"));
	}

	
	//создадим переменную y
	struct declare_new_var_ : CalculatorFixture
	{
		declare_new_var_()
		{
			calc.SetVarIdentifier("y");
		}
	};

	//после объявления переменной с именем 'y'
	BOOST_FIXTURE_TEST_SUITE(declare_new_var, declare_new_var_)

		//при инициализации значение по умолчанию равно NAN
		BOOST_AUTO_TEST_CASE(variable_default_to_NAN)
		{
			BOOST_CHECK(std::isnan(calc.GetVarValue("y")));
		}
		
		//значение можно изменить
		BOOST_AUTO_TEST_CASE(can_set_new_value)
		{
			BOOST_CHECK(calc.SetVarValue("y", "15"));
			BOOST_CHECK_EQUAL(calc.GetVarValue("y"), 15);
		}

		//нельзя объявить переменную повторно
		BOOST_AUTO_TEST_CASE(not_can_declare_var_again)
		{
			BOOST_CHECK(!calc.SetVarIdentifier("y"));
		}

	BOOST_AUTO_TEST_SUITE_END()

	//можно объявить ещё переменную
	struct again_declare_new_var_ : declare_new_var_
	{
		again_declare_new_var_()
		{
			calc.SetVarValue("y", "10");
			calc.SetVarValue("x", "30");
		}
	};

	//после объявления переменной с именем 'x'
	BOOST_FIXTURE_TEST_SUITE(again_declare_new_var, again_declare_new_var_)

		//переменной можно присвоить значение другой переменной
		BOOST_AUTO_TEST_CASE(can_set_other_variable_value)
		{
			BOOST_CHECK_EQUAL(calc.GetVarValue("y"), 10);
			BOOST_CHECK_EQUAL(calc.GetVarValue("x"), 30);

			BOOST_CHECK(calc.SetVarValue("y", "x"));
			BOOST_CHECK_EQUAL(calc.GetVarValue("y"), 30);
		}

		//попытка вызвать функцию с некорректным операндом завершится неудачей
		BOOST_AUTO_TEST_CASE(can_not_call_function_with_an_invalid_operand)
		{
			BOOST_CHECK(!calc.SetFunctionValue("function", "x", "", "y"));
		}

		//можно объявить функцию с одним единственным параметром
		BOOST_AUTO_TEST_CASE(can_declare_function_with_one_paramether)
		{
			BOOST_CHECK(calc.SetFunctionValue("function", "x", "", ""));
			BOOST_CHECK_EQUAL(calc.GetFunctionValue("function"), calc.GetVarValue("x"));
		}

		//можно объявить функцию, которая возводила бы в квадрат заданную переменную
		BOOST_AUTO_TEST_CASE(squaring_x)
		{
			BOOST_CHECK(calc.SetFunctionValue("function", "x", "*", "x"));
			BOOST_CHECK_EQUAL(calc.GetFunctionValue("function"), 900);
		}

	BOOST_AUTO_TEST_SUITE_END()

	//нельзя объявить функцию с несуществующими переменными
	BOOST_AUTO_TEST_CASE(can_declare_function_with_non_existent_variable)
	{
		BOOST_CHECK(!calc.SetFunctionValue("function", "z", "+", "f"));
		BOOST_CHECK_EQUAL(calc.GetFunctionValue("fuction"), VAL_NOT_EXISTING);
	}

	//имя функции не может быть пустым
	BOOST_AUTO_TEST_CASE(fn_name_can_not_be_empty)
	{
		BOOST_CHECK(calc.SetVarIdentifier("var"));
		BOOST_CHECK(!calc.SetFunctionValue("", "var", "", ""));
	}

	//можно объявить функцию с заданным названием, которая будет складывать x и y
	struct declare_func_ :again_declare_new_var_
	{
		declare_func_()
		{
			calc.SetFunctionValue("SumXandY", "x", "+", "y");
		}
	};

	//после объявления функции
	BOOST_FIXTURE_TEST_SUITE(declare_func, declare_func_)

		//функция может посчитать выражение x+y
		BOOST_AUTO_TEST_CASE(can_add_up_x_and_y)
		{
			BOOST_CHECK_EQUAL(calc.GetFunctionValue("SumXandY"), 40);
		}

		//нельзя объявить функцию повторно
		BOOST_AUTO_TEST_CASE(can_not_declare_function_again)
		{
			BOOST_CHECK(!calc.SetFunctionValue("SumXandY", "x", "+", "y"));
		}

		//нельзя объявить новую функцию, если её имя уже занято
		BOOST_AUTO_TEST_CASE(can_not_declare_function_if_her_name_is_busy)
		{
			BOOST_CHECK(!calc.SetFunctionValue("x", "y", "", ""));
		}

	BOOST_AUTO_TEST_SUITE_END()

	//объявим ещё одну функцию, а так же переменную z со значением 4
	struct declare_func_again_ :declare_func_
	{
		declare_func_again_()
		{
			calc.SetVarValue("z", "4");
			calc.SetFunctionValue("DivSumXandYonZ", "SumXandY", "/", "z");
		}
	};

	//после объявления функции DivSumXandYonZ, которая выполняет деление суммы x и y на значение переменной z
	BOOST_FIXTURE_TEST_SUITE(declare_func_again, declare_func_again_)

		//функция может посчитать выражение (x + y) / z
		BOOST_AUTO_TEST_CASE(can_div_func_on_var)
		{
			BOOST_CHECK_EQUAL(calc.GetFunctionValue("DivSumXandYonZ"), 10);
		}

		//переменной можно присвоить значение результата вычисления функции
		BOOST_AUTO_TEST_CASE(variable_can_be_assigned_value_of_calculation_result_of_function)
		{
			BOOST_CHECK(calc.SetVarValue("XandYdivZ", "DivSumXandYonZ"));
			BOOST_CHECK_EQUAL(calc.GetVarValue("XandYdivZ"), 10);
		}

		//если изменить значение переменной, то это отразится и на использующей её функции
		BOOST_AUTO_TEST_CASE(function_can_change_its_value_due_to_variable)
		{
			BOOST_CHECK(calc.SetVarValue("z", "10"));
			BOOST_CHECK_EQUAL(calc.GetFunctionValue("DivSumXandYonZ"), 4);
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()