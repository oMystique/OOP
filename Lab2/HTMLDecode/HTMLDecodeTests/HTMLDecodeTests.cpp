// HTMLDecodeTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../HTMLDecode/HTMLDecode.h"

BOOST_AUTO_TEST_SUITE(DecodeStringElementsToHtmlEntities)

BOOST_AUTO_TEST_CASE(DecodeNotEmptyString)
{
	std::string testString = "&quot;ASDASDASDASD&quot; &ap&amp;os &&apos; &gt; &amp; &lt; &lT &amp;&amp;&amp;";
	BOOST_CHECK_EQUAL(HTMLDecode(testString), "\"ASDASDASDASD\" &ap&os &' > & < &lT &&&");
};

BOOST_AUTO_TEST_CASE(DecodeEmptyString)
{
	std::string testString = "";
	BOOST_CHECK_EQUAL(HTMLDecode(testString), "");
};

BOOST_AUTO_TEST_SUITE_END()