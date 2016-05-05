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

	auto strr = string();
	strr[0] = '1';
	cout << strr[0] << endl;

	auto mSt = CMyString();
//	mSt[0] = 'a';
	cout << mSt << endl;

	return 0;
}

