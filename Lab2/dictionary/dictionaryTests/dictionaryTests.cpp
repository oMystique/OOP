// dictionaryTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../dictionary/dictionary.h"
#include <map>

BOOST_AUTO_TEST_SUITE(testSuiteDictionary)

struct Fixture
{
	Fixture():
		dictionary("input.txt")
	{
	}
	~Fixture()
	{
	}
	CDictionary dictionary;
};


BOOST_FIXTURE_TEST_CASE(testParseFileInDictionary, Fixture)
{
	BOOST_CHECK_EQUAL(dictionary.WorkIsNotSuccesfull(), false);
}

BOOST_FIXTURE_TEST_CASE(testAddWordInDictionary, Fixture)
{
	dictionary.AddWordInDictionary("rofl", "истеричный смех");
	BOOST_CHECK_EQUAL("истеричный смех", dictionary.GetTranslatedWord("rofl"));
}

BOOST_FIXTURE_TEST_CASE(testAddEmptyWordInDictionary, Fixture)
{
	auto oldDict = dictionary.GetDictionary();
	dictionary.AddWordInDictionary("", "истеричный смех");
	BOOST_CHECK_EQUAL(oldDict == dictionary.GetDictionary(), true);
}

BOOST_FIXTURE_TEST_CASE(testGetTrueTranslating, Fixture)
{
	BOOST_CHECK_EQUAL(dictionary.DictionaryHasATranslation("world"), true);
}

BOOST_FIXTURE_TEST_CASE(testGetFalseTranslating, Fixture)
{
	BOOST_CHECK_EQUAL(dictionary.DictionaryHasATranslation("Vladimir_Jirinovsky"), false);
}

BOOST_AUTO_TEST_SUITE_END()