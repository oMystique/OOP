// HTMLDecodeTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../HTMLDecode/HTMLDecode.h"

BOOST_AUTO_TEST_SUITE(EncodeStringElementsToHtmlEntities)

BOOST_AUTO_TEST_CASE(EncodeNotEmptyString)
{
	std::string testString = "&quotASDASDASDASD&quot &ap&ampos &&apos &qt &amp &lt &lT";
	BOOST_CHECK_EQUAL(HTMLDecode(testString), "\"ASDASDASDASD\" &ap&os &' > & < &lT");
};

BOOST_AUTO_TEST_CASE(EncodeEmptyString)
{
	std::string testString = "";
	BOOST_CHECK_EQUAL(HTMLDecode(testString), "");
};

BOOST_AUTO_TEST_SUITE_END()