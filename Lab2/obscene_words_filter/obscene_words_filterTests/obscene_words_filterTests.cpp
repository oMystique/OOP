// obscene_words_filterTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../obscene_words_filter/filter.h"

BOOST_AUTO_TEST_SUITE(testSuiteObsceneWordsFilter)

struct Fixture
{
	Fixture()
	{
		m_filter.ParsingFileInWordsSet("input.txt");
	}
	~Fixture()
	{
	}
	CObsceneWordsFilter m_filter;;
};

BOOST_FIXTURE_TEST_CASE(testParseFileInWordsSet, Fixture)
{
	BOOST_CHECK_EQUAL(m_filter.ParsingFileInWordsSet("input.txt"), false);
}

BOOST_FIXTURE_TEST_CASE(testFilterFirstString, Fixture)
{
	BOOST_CHECK(m_filter.FilteringOfInputString(L"You crud") == L"You ");
}

BOOST_FIXTURE_TEST_CASE(testFilterSecondString, Fixture)
{
	BOOST_CHECK(m_filter.FilteringOfInputString(L"You stupid CRUD, man!") == L"You  CRUD, man!");
}

BOOST_FIXTURE_TEST_CASE(testEmptyString, Fixture)
{
	BOOST_CHECK(m_filter.FilteringOfInputString(L"") == L"");
}

BOOST_AUTO_TEST_SUITE_END()
