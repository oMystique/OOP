#include "stdafx.h"
#include "../StringList/StringList.h"

using namespace std;

struct EmptyStringList
{
	CStringList list;
};

BOOST_FIXTURE_TEST_SUITE(String_list, EmptyStringList)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(is_empty)
		{
			BOOST_CHECK_EQUAL(list.GetSize(), 0u);
			BOOST_CHECK(list.IsEmpty());
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(after_appeding_a_string)
		BOOST_AUTO_TEST_CASE(increases_its_size_by_1)
		{
			auto oldSize = list.GetSize();
			list.Append("hello");
			BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 1);
			list.Append("hello");
			BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 2);
		}
		BOOST_AUTO_TEST_CASE(makes_it_accessible_via_GetBackElement_method)
		{
			list.Append("hello");
			BOOST_CHECK_EQUAL(list.GetBackElement(), "hello");
			list.Append("goodbye");
			BOOST_CHECK_EQUAL(list.GetBackElement(), "goodbye");
		}
		BOOST_AUTO_TEST_CASE(makes_it_accessible_via_iterator_to_first_element)
		{
			list.Append("hello");
			auto it = list.begin();
			BOOST_CHECK_EQUAL(addressof(*it), addressof(list.GetBackElement()));
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(after_add_a_string_to_front)
		BOOST_AUTO_TEST_CASE(increases_its_size_by_1)
		{
			auto oldSize = list.GetSize();
			list.AddToFront("hello");
			BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 1);
			list.AddToFront("hello");
			BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 2);
		}
		BOOST_AUTO_TEST_CASE(makes_it_accessible_via_GetFrontElement_method)
		{
			list.AddToFront("hello");
			BOOST_CHECK_EQUAL(list.GetFrontElement(), "hello");
			list.AddToFront("goodbye");
			BOOST_CHECK_EQUAL(list.GetFrontElement(), "goodbye");
		}
		BOOST_AUTO_TEST_CASE(makes_it_accessible_via_iterator_to_first_element)
		{
			list.AddToFront("hello");
			auto it = list.begin();
			BOOST_CHECK_EQUAL(addressof(*it), addressof(list.GetFrontElement()));
			BOOST_CHECK_EQUAL(addressof(*it), addressof(list.GetBackElement()));
		}
	BOOST_AUTO_TEST_SUITE_END()

	struct FilledStringList
		: EmptyStringList
	{
		FilledStringList()
		{
			list.Append("Hello, ");
			list.Append("World!");
			list.Append("It's");
			list.Append("me,");
			list.Append("Lack of sleep.");
		}
	};
	BOOST_FIXTURE_TEST_SUITE(after_filled_the_string_list, FilledStringList)

		struct ClearedStringList : FilledStringList
		{
			ClearedStringList()
			{
				list.Clear();
			}
		};
		BOOST_FIXTURE_TEST_SUITE(after_clear_a_string_list, ClearedStringList)
			BOOST_AUTO_TEST_CASE(list_is_empty)
			{
				BOOST_CHECK(list.IsEmpty());
			}
			BOOST_AUTO_TEST_CASE(list_size_is_equal_zero)
			{
				BOOST_CHECK_EQUAL(list.GetSize(), 0);
			}
			BOOST_AUTO_TEST_CASE(can_clear_already_empty_list_with_no_throw)
			{
				BOOST_REQUIRE_NO_THROW(list.Clear());
			}
			BOOST_AUTO_TEST_CASE(attempt_to_get_front_element_throw_exception)
			{
				BOOST_REQUIRE_THROW(list.GetFrontElement(), std::runtime_error);
			}
			BOOST_AUTO_TEST_CASE(attempt_to_get_back_element_throw_exception)
			{
				BOOST_REQUIRE_THROW(list.GetBackElement(), std::runtime_error);
			}
		BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()