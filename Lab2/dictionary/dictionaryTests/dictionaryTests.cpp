// dictionaryTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../dictionary/dictionary.h"
#include <map>

BOOST_AUTO_TEST_SUITE(testSuiteDictionary)

struct Fixture
{
	Fixture()
	{
		m_dictionary.ParseFileInDictionary("input.txt");
	}
	~Fixture()
	{
	}
	CDictionary m_dictionary;
};


BOOST_FIXTURE_TEST_CASE(testParseFileInDictionary, Fixture)
{
	BOOST_CHECK_EQUAL(m_dictionary.ParseFileInDictionary("input.txt"), false);
}

BOOST_FIXTURE_TEST_CASE(testAddWordInDictionary, Fixture)
{
	m_dictionary.AddWordInDictionary("rofl", "истеричный смех");
	BOOST_CHECK_EQUAL("истеричный смех", m_dictionary.GetTranslatedWord("rofl"));
}

BOOST_FIXTURE_TEST_CASE(testAddEmptyWordInDictionary, Fixture)
{
	auto oldDict = m_dictionary.GetDictionary();
	m_dictionary.AddWordInDictionary("", "истеричный смех");
	BOOST_CHECK_EQUAL(oldDict == m_dictionary.GetDictionary(), true);
}

BOOST_FIXTURE_TEST_CASE(testGetTrueTranslating, Fixture)
{
	BOOST_CHECK_EQUAL(m_dictionary.DictionaryHasATranslation("world"), true);
}

BOOST_FIXTURE_TEST_CASE(testGetFalseTranslating, Fixture)
{
	BOOST_CHECK_EQUAL(m_dictionary.DictionaryHasATranslation("Vladimir_Jirinovsky"), false);
}

BOOST_AUTO_TEST_SUITE_END()