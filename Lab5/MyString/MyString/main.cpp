#include "stdafx.h"
#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
	CMyString str("asd");
	auto a = "asd" + str;
	auto b = string("123") + str;
	cout << a << endl << b << endl;
	cout << string("asdasd").substr(7, 10) << endl;;
	return 0;
}

