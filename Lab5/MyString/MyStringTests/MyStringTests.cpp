// MyStringTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../MyString/MyString.h"

struct my_string_can_be_declared_by_default_
{
	CMyString myString;
};

BOOST_FIXTURE_TEST_SUITE(before_declared_string, my_string_can_be_declared_by_default_)

	BOOST_AUTO_TEST_CASE(default_pointer_to_an_array_of_char_strings_is_nullptr)
	{
		BOOST_CHECK(myString.GetStringData() == nullptr);
	}

	BOOST_AUTO_TEST_CASE(default_length_of_the_string_is_equal_to_zero)
	{
		BOOST_CHECK_EQUAL(myString.GetLength(), 0);
	}

	BOOST_AUTO_TEST_CASE(attempt_to_take_substring_returns_nullptr_and_zero_length)
	{
		auto substr = myString.SubString(0, 30);
		BOOST_CHECK_EQUAL(substr.GetLength(), 0);
		BOOST_CHECK(substr.GetStringData() == nullptr);
	}

	BOOST_AUTO_TEST_CASE(can_clear_empty_string)
	{
		BOOST_CHECK_NO_THROW(myString.Clear());
	}

BOOST_AUTO_TEST_SUITE_END()


struct my_string_can_be_declared_by_value_
{
	CMyString myString("Test String");
};