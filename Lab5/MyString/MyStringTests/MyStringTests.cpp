#include "stdafx.h"
#include "../MyString/MyString.h"
#include <string>
#include <sstream>

struct my_string_can_be_declared_by_default_
{
	CMyString myString;
};

BOOST_FIXTURE_TEST_SUITE(before_declared_empty_string, my_string_can_be_declared_by_default_)

	BOOST_AUTO_TEST_CASE(default_pointer_to_an_array_of_char_strings_is_null)
	{
		BOOST_CHECK(myString.GetStringData()[0] == '\0');
	}

	BOOST_AUTO_TEST_CASE(default_length_of_the_string_is_equal_to_zero)
	{
		BOOST_CHECK_EQUAL(myString.GetLength(), 0u);
	}

	BOOST_AUTO_TEST_CASE(my_str_have_a_null_char_on_end)
	{
		BOOST_CHECK_EQUAL(myString.GetStringData()[myString.GetLength()], '\0');
	}

	BOOST_AUTO_TEST_CASE(attempt_to_take_substring_if_empty_str_returns_exception)
	{
		BOOST_REQUIRE_THROW(auto substr = myString.SubString(0u, 30u), std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(can_clear_empty_string)
	{
		BOOST_CHECK_NO_THROW(myString.Clear());
	}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_CASE(can_create_my_string_without_null_char)
{
	CMyString myStr("\0");
	BOOST_CHECK_EQUAL(myStr.GetStringData(), "\0");
	BOOST_CHECK_EQUAL(myStr.GetLength(), 0u);
}

BOOST_AUTO_TEST_CASE(my_string_without_null_char_in_center_str_will_be_cut)
{
	CMyString myStr("Test\0 String");
	BOOST_CHECK_EQUAL(myStr.GetStringData()[myStr.GetLength()], '\0');
	BOOST_CHECK_EQUAL(myStr.GetLength(), 4u);
}

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
		BOOST_CHECK_EQUAL(myString.GetLength(), 11u);
	}

	BOOST_AUTO_TEST_CASE(attempt_to_take_correct_substring_returns_this_substr)
	{
		auto substr = myString.SubString(0u, 4u);
		BOOST_CHECK_EQUAL(substr.GetLength(), 4u);
		BOOST_CHECK_EQUAL(substr.GetStringData(), "Test");
	}

	BOOST_AUTO_TEST_CASE(my_str_have_a_null_char_on_end)
	{
		BOOST_CHECK_EQUAL(myString.GetStringData()[myString.GetLength()], '\0');
	}


	BOOST_AUTO_TEST_CASE(attempt_to_take_substring_without_incorrect_args_returns_null_str)
	{
		BOOST_REQUIRE_THROW(auto substr = myString.SubString(4u, 0u), std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(attempt_to_take_incorrect_substring_returns_exception)
	{
		BOOST_REQUIRE_THROW(auto substr = myString.SubString(20u, 30u), std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(can_clear_initialized_string)
	{
		BOOST_CHECK_NO_THROW(myString.Clear());
		BOOST_CHECK_EQUAL(myString.GetLength(), 0u);
		BOOST_CHECK_EQUAL(myString.GetStringData()[0], '\0');
	}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_CASE(can_to_take_substr_with_max_length_more_by_str_length)
{
	CMyString str("12345");
	BOOST_CHECK_EQUAL(str.SubString(0, 6), "12345");
}

struct my_string_can_be_declared_by_value_and_length_
{
	my_string_can_be_declared_by_value_and_length_()
		: myString("Test String", 11u)
	{};

	CMyString myString;
};

BOOST_FIXTURE_TEST_SUITE(before_declared_string_by_value_and_length, my_string_can_be_declared_by_value_and_length_)

	BOOST_AUTO_TEST_CASE(pointer_to_an_array_of_char_strings_is_equal_to_test_str)
	{
		BOOST_CHECK_EQUAL(myString.GetStringData(), "Test String");
	}

	BOOST_AUTO_TEST_CASE(default_length_of_the_string_is_equal_to_length_test_str)
	{
		BOOST_CHECK_EQUAL(myString.GetLength(), 11u);
	}

	BOOST_AUTO_TEST_CASE(attempt_to_take_correct_substring_returns_this_substr)
	{
		auto substr = myString.SubString(0u, 4u);
		BOOST_CHECK_EQUAL(substr.GetLength(), 4u);
		BOOST_CHECK_EQUAL(substr.GetStringData(), "Test");
	}

	BOOST_AUTO_TEST_CASE(my_str_have_a_null_char_on_end)
	{
		BOOST_CHECK_EQUAL(myString.GetStringData()[myString.GetLength()], '\0');
	}

	BOOST_AUTO_TEST_CASE(attempt_to_take_substring_without_incorrect_args_returns_exception)
	{
		BOOST_REQUIRE_THROW(auto substr = myString.SubString(4u, 0u), std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(attempt_to_take_incorrect_substring_returns_exception)
	{
		BOOST_REQUIRE_THROW(auto substr = myString.SubString(20u, 30u), std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(can_clear_initialized_string)
	{
		BOOST_CHECK_NO_THROW(myString.Clear());
		BOOST_CHECK_EQUAL(myString.GetLength(), 0u);
		BOOST_CHECK_EQUAL(myString.GetStringData()[0], '\0');
	}

BOOST_AUTO_TEST_SUITE_END()


void ExpectStringDataImpl(const CMyString & s, const char *data, size_t size)
{
	BOOST_REQUIRE_EQUAL(s.GetLength(), size - 1);
	BOOST_REQUIRE_EQUAL(s.GetStringData(), data);
	BOOST_REQUIRE_EQUAL(memcmp(s.GetStringData(), data, size), 0);
}

template <size_t N>
void ExpectStringData(const CMyString & s, const char(&data)[N])
{
	ExpectStringDataImpl(s, data, N);
}

BOOST_AUTO_TEST_CASE(SelfConcatenationAfterClearing)
{
	CMyString s("hello");
	s.Clear();
	s += s;
	ExpectStringData(s, "");
}

BOOST_AUTO_TEST_CASE(my_string_without_null_char_in_center_str_will_not_be_cut_off)
{
	CMyString myStr("Test\0 String", 12u);
	ExpectStringData(myStr, "Test\0 String");
	BOOST_CHECK_EQUAL(myStr.GetStringData(), "Test\0 String");
	BOOST_CHECK_EQUAL(myStr.GetLength(), 12u);
}


struct my_string_can_be_copied_existing_my_str_
{
	my_string_can_be_copied_existing_my_str_()
		: myString("Test String", 11u)
		, copiedMyStr(myString)
	{
	};

	CMyString myString;
	CMyString copiedMyStr;
};

BOOST_FIXTURE_TEST_SUITE(before_copied_my_str, my_string_can_be_copied_existing_my_str_)

	BOOST_AUTO_TEST_CASE(character_string_of_existing_string_is_equal_copied_string)
	{
		BOOST_CHECK_EQUAL(myString.GetStringData(), copiedMyStr.GetStringData());
	}

	BOOST_AUTO_TEST_CASE(existing_strings_length_is_equal_copied_strings_length)
	{
		BOOST_CHECK_EQUAL(myString.GetLength(), copiedMyStr.GetLength());
	}

BOOST_AUTO_TEST_SUITE_END()


struct my_string_can_be_moved_from_rvalue_my_str_
{
	my_string_can_be_moved_from_rvalue_my_str_()
		: myString(CMyString("Test String", 11u))
	{
	};

	CMyString myString;
};

BOOST_FIXTURE_TEST_SUITE(before_moved_to_my_str, my_string_can_be_moved_from_rvalue_my_str_)

	BOOST_AUTO_TEST_CASE(character_string_of_existing_string_is_equal_to_moved_string)
	{
		BOOST_CHECK_EQUAL(myString.GetStringData(), "Test String");
	}

	BOOST_AUTO_TEST_CASE(existing_strings_length_is_equal_copied_strings_length)
	{
		BOOST_CHECK_EQUAL(myString.GetLength(), 11u);
	}

BOOST_AUTO_TEST_SUITE_END()


struct my_string_can_be_copied_from_stl_string_
{
	my_string_can_be_copied_from_stl_string_()
		: stlString("Test String")
		, myString(stlString)
	{
	};

	std::string stlString;
	CMyString myString;
};

BOOST_FIXTURE_TEST_SUITE(before_copied_from_stl_string, my_string_can_be_copied_from_stl_string_)

	BOOST_AUTO_TEST_CASE(character_string_of_existing_string_is_equal_to_stl_string)
	{
		BOOST_CHECK_EQUAL(myString.GetStringData(), "Test String");
	}

	BOOST_AUTO_TEST_CASE(existing_strings_length_is_equal_copied_stl_strings_length)
	{
		BOOST_CHECK_EQUAL(myString.GetLength(), 11u);
	}

BOOST_AUTO_TEST_SUITE_END()


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
	BOOST_CHECK_EQUAL(myString.GetLength(), 10u);
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
		BOOST_CHECK_EQUAL(stlAddStr.GetLength(), 10u);

		BOOST_CHECK_EQUAL(charArrAddStr.GetLength(), 12u);

		BOOST_CHECK_EQUAL(myAddStr.GetLength(), 9u);
	}

	BOOST_AUTO_TEST_CASE(can_be_assign_addition_of_itself)
	{
		BOOST_CHECK_NO_THROW(myAddStr = myAddStr + myAddStr);

		BOOST_CHECK_EQUAL(myAddStr.GetStringData(), "MY stringMY string");
	}

BOOST_AUTO_TEST_SUITE_END()

//operator ==
BOOST_AUTO_TEST_SUITE(comparison_operator)

	BOOST_AUTO_TEST_CASE(strings_are_equal)
	{
		BOOST_CHECK(CMyString("Test String") == CMyString("Test String", 11u));
	}

	BOOST_AUTO_TEST_CASE(strings_are_not_equal)
	{
		BOOST_CHECK(!(CMyString("Test String1") == CMyString("Test String", 11u)));
	}

	BOOST_AUTO_TEST_CASE(null_character_will_not_be_ignored)
	{
		BOOST_CHECK(!(CMyString("Test") == CMyString("Test\0 String", 12u)));
	}

BOOST_AUTO_TEST_SUITE_END()

//operator !=
BOOST_AUTO_TEST_SUITE(inequality_operator)

	BOOST_AUTO_TEST_CASE(strings_are_equal)
	{
		BOOST_CHECK(!(CMyString("Test String") != CMyString("Test String", 11u)));
	}

	BOOST_AUTO_TEST_CASE(strings_are_not_equal)
	{
		BOOST_CHECK(CMyString("Test String1") != CMyString("Test String", 11u));
	}

	BOOST_AUTO_TEST_CASE(null_character_will_not_be_ignored)
	{
		BOOST_CHECK(CMyString("Test") != CMyString("Test\0 String", 12u));
	}

	BOOST_AUTO_TEST_CASE(different_strings_with_equal_prefixs_is_not_equal)
	{
		BOOST_CHECK(CMyString("ab") != CMyString("abcd", 12u));
	}


BOOST_AUTO_TEST_SUITE_END()

//operator <
BOOST_AUTO_TEST_SUITE(less_operator)

	BOOST_AUTO_TEST_CASE(can_find_out_which_of_rows_preceded_by_another_in_alphabetical_order)
	{
		BOOST_CHECK((CMyString("ab") < CMyString("abc", 3)));
	}

	BOOST_AUTO_TEST_CASE(left_str_is_not_less_by_right_str)
	{
		BOOST_CHECK(!(CMyString("abz") < CMyString("abcd", 3)));
	}

	BOOST_AUTO_TEST_CASE(if_strings_is_equal_operator_less_return_false)
	{
		BOOST_CHECK(!(CMyString("Test", 4u) < CMyString("Test")));
	}

BOOST_AUTO_TEST_SUITE_END()

//operator >
BOOST_AUTO_TEST_SUITE(more_operator)

	BOOST_AUTO_TEST_CASE(can_find_out_which_of_rows_preceded_by_another_in_alphabetical_order)
	{
		BOOST_CHECK(!(CMyString("ab") > CMyString("abc", 3)));
	}

	BOOST_AUTO_TEST_CASE(left_str_is_more_by_right_str)
	{
		BOOST_CHECK((CMyString("abz") > CMyString("abcd", 3)));
	}

	BOOST_AUTO_TEST_CASE(if_strings_is_equal_operator_more_return_true)
	{
		BOOST_CHECK(!(CMyString("Test", 4u) > CMyString("Test", 4u)));
	}

BOOST_AUTO_TEST_SUITE_END()

//operator <=
BOOST_AUTO_TEST_SUITE(less_or_equal_operator)

	BOOST_AUTO_TEST_CASE(can_find_out_which_of_rows_preceded_by_another_in_alphabetical_order)
	{
		BOOST_CHECK((CMyString("ab") <= CMyString("abc", 3)));
	}

	BOOST_AUTO_TEST_CASE(left_str_is_more_by_right_str_and_operator_return_false)
	{
		BOOST_CHECK(!(CMyString("abz") <= CMyString("abcd", 3)));
	}

	BOOST_AUTO_TEST_CASE(if_strings_is_equal_operator_less_and_equal_return_true)
	{
		BOOST_CHECK((CMyString("Test", 4u) <= CMyString("Test", 4u)));
	}

BOOST_AUTO_TEST_SUITE_END()

//operator >=
BOOST_AUTO_TEST_SUITE(more_or_equal_operator)

	BOOST_AUTO_TEST_CASE(if_left_str_is_less_to_right_str_then_return_false)
	{
		BOOST_CHECK(!(CMyString("ab") >= CMyString("abc", 3)));
	}

	BOOST_AUTO_TEST_CASE(left_str_is_more_by_right_str_and_operator_return_true)
	{
		BOOST_CHECK(!(CMyString("abz") <= CMyString("abcd", 3)));
	}

	BOOST_AUTO_TEST_CASE(if_strings_is_equal_operator_more_and_equal_return_true)
	{
		BOOST_CHECK((CMyString("Test", 4u) <= CMyString("Test", 4u)));
	}

BOOST_AUTO_TEST_SUITE_END()

//operator [] for read
BOOST_AUTO_TEST_SUITE(indexed_access_to_characters_to_read_operator)

	BOOST_AUTO_TEST_CASE(access_to_an_arbitrary_element_will_return_value_of_this_item)
	{
		BOOST_CHECK_EQUAL(CMyString("SomeString")[0], 'S');
	}

	BOOST_AUTO_TEST_CASE(access_index_equal_to_length_of_the_string_will_return_exception_out_of_range)
	{
		CMyString str("SomeString");
		BOOST_REQUIRE_THROW(str[str.GetLength()], std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(access_index_longer_than_string_returns_exception_out_of_range)
	{
		BOOST_REQUIRE_THROW(CMyString("SomeString")[400], std::out_of_range);
	}

BOOST_AUTO_TEST_SUITE_END()

//operator [] for write
BOOST_AUTO_TEST_SUITE(indexed_access_to_characters_to_write_operator)

	BOOST_AUTO_TEST_CASE(access_to_an_arbitrary_element_will_return_value_of_this_item)
	{
		CMyString str("SomeString");
		BOOST_REQUIRE(str[0] = 'H');
		BOOST_CHECK_EQUAL(str.GetStringData(), "HomeString");
	}

	BOOST_AUTO_TEST_CASE(access_index_equal_to_length_of_the_string_will_return_exception_out_of_range)
	{
		CMyString str("SomeString");
		BOOST_REQUIRE_THROW(str[str.GetLength()] = 'Z', std::out_of_range);
	}

BOOST_AUTO_TEST_SUITE_END()


// operator << (ostream)

BOOST_AUTO_TEST_SUITE(ostream_operator_tests)

	BOOST_AUTO_TEST_CASE(output_to_ostream_string_without_null_char_in_middle)
	{
		std::ostringstream strm;
		strm << CMyString("SomeString");
		BOOST_CHECK_EQUAL(strm.str(), "SomeString");
	}

	BOOST_AUTO_TEST_CASE(output_to_ostream_string_with_null_char_in_middle)
	{
		std::ostringstream strm;
		strm << CMyString("Some\0String");
		BOOST_CHECK_EQUAL(strm.str(), "Some\0String");
	}

	BOOST_AUTO_TEST_CASE(output_to_ostream_empty_string)
	{
		std::ostringstream strm;
		strm << CMyString("");
		BOOST_CHECK_EQUAL(strm.str(), "");
	}

BOOST_AUTO_TEST_SUITE_END()

// operator >> (istream)

void VerifyCorrectWorkIstreamOperator(std::string const &str)
{
	std::istringstream strm(str);
	CMyString myStr;
	strm >> myStr;
	BOOST_CHECK_EQUAL(myStr.GetStringData(), str);
}

BOOST_AUTO_TEST_SUITE(istream_operator_tests)

	BOOST_AUTO_TEST_CASE(input_from_istream_to_mystring_without_null_char_in_middle)
	{
		VerifyCorrectWorkIstreamOperator("SomeString");
	}

	BOOST_AUTO_TEST_CASE(input_from_istream_to_mystring_with_null_char_in_middle)
	{
		VerifyCorrectWorkIstreamOperator("Some\0String");
	}

	BOOST_AUTO_TEST_CASE(input_to_mystring_from_istream_empty_string)
	{
		VerifyCorrectWorkIstreamOperator("");
	}

BOOST_AUTO_TEST_SUITE_END()

//ITERATOR tests;
struct declare_mystring_for_iterator_tests_
{
	declare_mystring_for_iterator_tests_()
		: myStr("Iterator tests", 15)
		, constMyStr("Iterator const tests", 21)
	{
	}
	CMyString myStr;
	const CMyString constMyStr;
};

BOOST_FIXTURE_TEST_SUITE(before_declare_mystring_for_iterator_tests, declare_mystring_for_iterator_tests_)

	BOOST_AUTO_TEST_CASE(can_just_call_the_iterator_and_get_point_to_start_str)
	{
		auto it = myStr.begin();
		BOOST_CHECK_EQUAL(*it, myStr[0]);
	}

	BOOST_AUTO_TEST_CASE(can_get_point_to_end_str)
	{
		auto it = myStr.end();
		--it;
		BOOST_CHECK_EQUAL(*it, myStr[myStr.GetLength() - 1]);
	}

	BOOST_AUTO_TEST_CASE(can_iterate_over_constant_string_in_forward_direction)
	{
		size_t i = 0;
		for (CMyString::ConstIterator it = constMyStr.begin(); it != constMyStr.end(); ++it)
		{
			BOOST_CHECK_EQUAL(*it, constMyStr[i]);
			++i;
		}
	}

	BOOST_AUTO_TEST_CASE(can_iterate_over_constant_string_in_opposite_direction)
	{
		size_t i = constMyStr.GetLength() - 1;
		for (CMyString::ConstIterator it = constMyStr.rbegin(); it != constMyStr.rend(); ++it)
		{
			BOOST_CHECK_EQUAL(*it, constMyStr[i]);
			--i;
		}
	}

	BOOST_AUTO_TEST_CASE(can_iterate_over_non_constant_string_in_forward_direction)
	{
		size_t i = 0;
		for (CMyString::Iterator it = myStr.begin(); it != myStr.end(); ++it)
		{
			BOOST_CHECK_EQUAL(*it, myStr[i]);
			++i;
		}
	}

	BOOST_AUTO_TEST_CASE(can_iterate_over_non_constant_string_in_opposite_direction)
	{
		size_t i = myStr.GetLength() - 1;
		for (CMyString::Iterator it = myStr.rbegin(); it != myStr.rend(); ++it)
		{
			BOOST_CHECK_EQUAL(*it, myStr[i]);
			--i;
		}
	}

	BOOST_AUTO_TEST_CASE(can_get_distance_between_two_iterators)
	{
		BOOST_CHECK_EQUAL(myStr.end() - myStr.begin(), 15);

		BOOST_CHECK_EQUAL(std::distance(myStr.rbegin(), myStr.rend()), -15);
	}

	BOOST_AUTO_TEST_CASE(can_addition_iter_and_integer)
	{
		auto it = myStr.begin() + 3;
		BOOST_CHECK_EQUAL(*it, 'r');
	}

	BOOST_AUTO_TEST_CASE(can_addition_integer_and_iter)
	{
		auto it = 3 + myStr.begin();
		BOOST_CHECK_EQUAL(*it, 'r');
	}

	BOOST_AUTO_TEST_CASE(has_indexed_access_only_for_read_to_elements_of_const_line_relative_to_iterator)
	{
		auto it = constMyStr.begin();
		BOOST_CHECK_EQUAL(it[3], 'r');
	}

	BOOST_AUTO_TEST_CASE(supports_iteration_over_the_elements_by_means_of_range_based_for)
	{
		size_t i = 0;
		for (auto it: myStr)
		{
			BOOST_CHECK_EQUAL(it, myStr[i]);
			++i;
		}
	}

BOOST_AUTO_TEST_SUITE_END()