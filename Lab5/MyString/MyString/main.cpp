#include "stdafx.h"
#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
	cout << memcmp("abc", "abc", 3) << endl;
	return 0;
}

