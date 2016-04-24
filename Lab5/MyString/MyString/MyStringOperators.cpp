#include "stdafx.h"
#include "../MyString/MyString.h"

using namespace std;

std::ostream & operator <<(std::ostream & strm, CMyString const & string)
{
	strm << string.GetStringData();
	return strm;
}