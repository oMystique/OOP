// CalculatorTests.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "../Calculator/calculator.h"

struct CalculatorFixture
{
	CCalculator calc;
};

BOOST_FIXTURE_TEST_SUITE(Calculator, CalculatorFixture)

	//����� �������� ����� ���������� � �������� ������	
	BOOST_AUTO_TEST_CASE(can_declare_new_var_with_given_name)
	{
		BOOST_CHECK(calc.SetVarIdentifier("y"));
	}

	//���� ���������� �� ���������, �� ������� ��������� �������� ������ ��� ��������������� ��������
	BOOST_AUTO_TEST_CASE(if_var_does_not_exist_get_value_return_non_exist_paramether)
	{
		BOOST_CHECK_EQUAL(calc.GetVarValue("y"), VAL_NOT_EXISTING);
	}

	//���� ���������� �� ������� ����, �� ��� ������� ��������� �������� - ��� ���������
	BOOST_AUTO_TEST_CASE(if_var_does_not_exist_its_created)
	{
		BOOST_CHECK_EQUAL(calc.GetVarValue("x"), VAL_NOT_EXISTING);
		BOOST_CHECK(calc.SetVarValue("x", "123"));
		BOOST_CHECK_EQUAL(calc.GetVarValue("x"), 123);
	}

	//��� ���������� �� ����� ���� ������
	BOOST_AUTO_TEST_CASE(var_name_can_not_be_empty)
	{
		BOOST_CHECK(!calc.SetVarIdentifier(""));
		BOOST_CHECK(!calc.SetVarValue("", "20"));
	}

	
	//�������� ���������� y
	struct declare_new_var_ : CalculatorFixture
	{
		declare_new_var_()
		{
			calc.SetVarIdentifier("y");
		}
	};

	//����� ���������� ���������� � ������ 'y'
	BOOST_FIXTURE_TEST_SUITE(declare_new_var, declare_new_var_)

		//��� ������������� �������� �� ��������� ����� NAN
		BOOST_AUTO_TEST_CASE(variable_default_to_NAN)
		{
			BOOST_CHECK(std::isnan(calc.GetVarValue("y")));
		}
		
		//�������� ����� ��������
		BOOST_AUTO_TEST_CASE(can_set_new_value)
		{
			BOOST_CHECK(calc.SetVarValue("y", "15"));
			BOOST_CHECK_EQUAL(calc.GetVarValue("y"), 15);
		}

		//������ �������� ���������� ��������
		BOOST_AUTO_TEST_CASE(not_can_declare_var_again)
		{
			BOOST_CHECK(!calc.SetVarIdentifier("y"));
		}

	BOOST_AUTO_TEST_SUITE_END()

	//����� �������� ��� ����������
	struct again_declare_new_var_ : declare_new_var_
	{
		again_declare_new_var_()
		{
			calc.SetVarValue("y", "10");
			calc.SetVarValue("x", "30");
		}
	};

	//����� ���������� ���������� � ������ 'x'
	BOOST_FIXTURE_TEST_SUITE(again_declare_new_var, again_declare_new_var_)

		//���������� ����� ��������� �������� ������ ����������
		BOOST_AUTO_TEST_CASE(can_set_other_variable_value)
		{
			BOOST_CHECK_EQUAL(calc.GetVarValue("y"), 10);
			BOOST_CHECK_EQUAL(calc.GetVarValue("x"), 30);

			BOOST_CHECK(calc.SetVarValue("y", "x"));
			BOOST_CHECK_EQUAL(calc.GetVarValue("y"), 30);
		}

		//������� ������� ������� � ������������ ��������� ���������� ��������
		BOOST_AUTO_TEST_CASE(can_not_call_function_with_an_invalid_operand)
		{
			BOOST_CHECK(!calc.SetFunctionValue("function", "x", "", "y"));
		}

		//����� �������� ������� � ����� ������������ ����������
		BOOST_AUTO_TEST_CASE(can_declare_function_with_one_paramether)
		{
			BOOST_CHECK(calc.SetFunctionValue("function", "x", "", ""));
			BOOST_CHECK_EQUAL(calc.GetFunctionValue("function"), calc.GetVarValue("x"));
		}

		//����� �������� �������, ������� ��������� �� � ������� �������� ����������
		BOOST_AUTO_TEST_CASE(squaring_x)
		{
			BOOST_CHECK(calc.SetFunctionValue("function", "x", "*", "x"));
			BOOST_CHECK_EQUAL(calc.GetFunctionValue("function"), 900);
		}

	BOOST_AUTO_TEST_SUITE_END()

	//������ �������� ������� � ��������������� �����������
	BOOST_AUTO_TEST_CASE(can_declare_function_with_non_existent_variable)
	{
		BOOST_CHECK(!calc.SetFunctionValue("function", "z", "+", "f"));
		BOOST_CHECK_EQUAL(calc.GetFunctionValue("fuction"), VAL_NOT_EXISTING);
	}

	//��� ������� �� ����� ���� ������
	BOOST_AUTO_TEST_CASE(fn_name_can_not_be_empty)
	{
		BOOST_CHECK(calc.SetVarIdentifier("var"));
		BOOST_CHECK(!calc.SetFunctionValue("", "var", "", ""));
	}

	//����� �������� ������� � �������� ���������, ������� ����� ���������� x � y
	struct declare_func_ :again_declare_new_var_
	{
		declare_func_()
		{
			calc.SetFunctionValue("SumXandY", "x", "+", "y");
		}
	};

	//����� ���������� �������
	BOOST_FIXTURE_TEST_SUITE(declare_func, declare_func_)

		//������� ����� ��������� ��������� x+y
		BOOST_AUTO_TEST_CASE(can_add_up_x_and_y)
		{
			BOOST_CHECK_EQUAL(calc.GetFunctionValue("SumXandY"), 40);
		}

		//������ �������� ������� ��������
		BOOST_AUTO_TEST_CASE(can_not_declare_function_again)
		{
			BOOST_CHECK(!calc.SetFunctionValue("SumXandY", "x", "+", "y"));
		}

		//������ �������� ����� �������, ���� � ��� ��� ������
		BOOST_AUTO_TEST_CASE(can_not_declare_function_if_her_name_is_busy)
		{
			BOOST_CHECK(!calc.SetFunctionValue("x", "y", "", ""));
		}

	BOOST_AUTO_TEST_SUITE_END()

	//������� ��� ���� �������, � ��� �� ���������� z �� ��������� 4
	struct declare_func_again_ :declare_func_
	{
		declare_func_again_()
		{
			calc.SetVarValue("z", "4");
			calc.SetFunctionValue("DivSumXandYonZ", "SumXandY", "/", "z");
		}
	};

	//����� ���������� ������� DivSumXandYonZ, ������� ��������� ������� ����� x � y �� �������� ���������� z
	BOOST_FIXTURE_TEST_SUITE(declare_func_again, declare_func_again_)

		//������� ����� ��������� ��������� (x + y) / z
		BOOST_AUTO_TEST_CASE(can_div_func_on_var)
		{
			BOOST_CHECK_EQUAL(calc.GetFunctionValue("DivSumXandYonZ"), 10);
		}

		//���������� ����� ��������� �������� ���������� ���������� �������
		BOOST_AUTO_TEST_CASE(variable_can_be_assigned_value_of_calculation_result_of_function)
		{
			BOOST_CHECK(calc.SetVarValue("XandYdivZ", "DivSumXandYonZ"));
			BOOST_CHECK_EQUAL(calc.GetVarValue("XandYdivZ"), 10);
		}

		//���� �������� �������� ����������, �� ��� ��������� � �� ������������ � �������
		BOOST_AUTO_TEST_CASE(function_can_change_its_value_due_to_variable)
		{
			BOOST_CHECK(calc.SetVarValue("z", "10"));
			BOOST_CHECK_EQUAL(calc.GetFunctionValue("DivSumXandYonZ"), 4);
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()