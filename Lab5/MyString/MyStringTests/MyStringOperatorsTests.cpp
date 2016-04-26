#include "stdafx.h"
#include "../MyString/MyString.h"
#include <string>

// operator =
struct my_string_allows_you_assign_meaning_other_strings_
{
	my_string_allows_you_assign_meaning_other_strings_()
		: assignedMyStr("SomeString")
	{
		myString = assignedMyStr;
	}
	CMyString myString;
	CMyString assignedMyStr;
};

BOOST_FIXTURE_TEST_SUITE(before_assignment_other_string_to_my_string, my_string_allows_you_assign_meaning_other_strings_)

	BOOST_AUTO_TEST_CASE(character_string_of_my_string_is_equal_assignment_string)
	{
		BOOST_CHECK_EQUAL(myString.GetStringData(), "SomeString");
	}

	BOOST_AUTO_TEST_CASE(existing_strings_length_is_equal_assignment_strings_length)
	{
		BOOST_CHECK_EQUAL(myString.GetLength(), 10);
	}

	BOOST_AUTO_TEST_CASE(can_be_assign_itself)
	{
		BOOST_CHECK_NO_THROW(myString = myString);
		
		BOOST_CHECK_EQUAL(myString.GetStringData(), "SomeString");
	}

BOOST_AUTO_TEST_SUITE_END()


// operator + for CMyString, std::string, const char*
struct my_string_have_the_addition_operator_
{
	my_string_have_the_addition_operator_()
	{
		stlAddStr = std::string("STL") + CMyString(" string");
		charArrAddStr = "CHAR*" + CMyString(" string");
		myAddStr = CMyString("MY") + CMyString(" string");
	}
	CMyString stlAddStr;
	CMyString charArrAddStr;
	CMyString myAddStr;
};

BOOST_FIXTURE_TEST_SUITE(before_addition_strings, my_string_have_the_addition_operator_)

	BOOST_AUTO_TEST_CASE(characters_string_of_my_string_is_equal_assignment_strings)
	{
		BOOST_CHECK_EQUAL(stlAddStr.GetStringData(), "STL string");

		BOOST_CHECK_EQUAL(charArrAddStr.GetStringData(), "CHAR* string");

		BOOST_CHECK_EQUAL(myAddStr.GetStringData(), "MY string");
	}

	BOOST_AUTO_TEST_CASE(existing_strings_length_is_equal_assignment_strings_length)
	{
		BOOST_CHECK_EQUAL(stlAddStr.GetLength(), 10);

		BOOST_CHECK_EQUAL(charArrAddStr.GetLength(), 12);

		BOOST_CHECK_EQUAL(myAddStr.GetLength(), 9);
	}

	BOOST_AUTO_TEST_CASE(can_be_assign_addition_of_itself)
	{
		BOOST_CHECK_NO_THROW(myAddStr = myAddStr + myAddStr);

		BOOST_CHECK_EQUAL(myAddStr.GetStringData(), "MY stringMY string");
	}

BOOST_AUTO_TEST_SUITE_END()