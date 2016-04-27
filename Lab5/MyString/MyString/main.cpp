#include "stdafx.h"
#include <iostream>
#include "MyString.h"

int main()
{
	CMyString str1("abvgd", 5);
	std::cout << str1.GetSortedAlphabeticallyChars() << std::endl;
	return 0;
}

