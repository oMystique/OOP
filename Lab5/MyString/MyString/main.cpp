#include "stdafx.h"
#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{

	CMyString mStr("Hello");
	for (auto it = mStr.begin(); it != mStr.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << endl;
	for (auto it = mStr.rbegin(); it != mStr.rend(); --it)
	{
		cout << *it << endl;
	}
	cout << endl;
	for (auto it : mStr)
	{
		cout << it << endl;
	}

	cout << mStr.rbegin() - mStr.rend() << endl;
	 
	return 0;
}

