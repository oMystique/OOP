// MyStringTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../MyString/MyString.h"
#include <memory>

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
	my_string_can_be_declared_by_value_()
		: myString("Test String")
	{};

	CMyString myString;
};

BOOST_FIXTURE_TEST_SUITE(before_declared_string_by_value, my_string_can_be_declared_by_value_)

	BOOST_AUTO_TEST_CASE(pointer_to_an_array_of_char_strings_is_equal_to_test_str)
	{
		BOOST_CHECK_EQUAL(myString.GetStringData(), "Test String");
	}

	BOOST_AUTO_TEST_CASE(default_length_of_the_string_is_equal_to_length_test_str)
	{
		BOOST_CHECK_EQUAL(myString.GetLength(), 12);
	}

	BOOST_AUTO_TEST_CASE(attempt_to_take_correct_substring_returns_this_substr)
	{
		auto substr = myString.SubString(0, 4);
		BOOST_CHECK_EQUAL(substr.GetLength(), 5);
		BOOST_CHECK_EQUAL(substr.GetStringData(), "Test");
	}

	BOOST_AUTO_TEST_CASE(attempt_to_take_incorrect_substring_returns_empty_my_str)
	{
		auto substr = myString.SubString(20, 30);
		BOOST_CHECK_EQUAL(substr.GetLength(), 0);
		BOOST_CHECK(substr.GetStringData() == nullptr);
	}

	BOOST_AUTO_TEST_CASE(can_clear_initialized_string)
	{
		BOOST_CHECK_NO_THROW(myString.Clear());
		BOOST_CHECK_EQUAL(myString.GetLength(), 0);
		BOOST_CHECK(myString.GetStringData() == nullptr);

	}

BOOST_AUTO_TEST_SUITE_END()