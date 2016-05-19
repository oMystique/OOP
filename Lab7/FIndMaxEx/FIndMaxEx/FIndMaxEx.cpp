// FIndMaxEx.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "FindMaxEx.h"
#include <list>

using namespace std;
//template <>
//bool FindMax<const char *>(std::vector<const char*> const& arr, const char*& maxValue)
//{
//	if (arr.size() == 0)
//	{
//		return false;
//	}
//	maxValue = *std::max_element(arr.begin(), arr.end(), [](const char *str1, const char *str2) {
//		return strcmp(str1, str2) != 1 ? true : false;
//	});
//
//	return true;
//}

int main()
{
	{
		std::vector<int> vecInt = { 1, 2, 3, 4, 5 };
		int max;
		FindMax(vecInt, max, [](int a, int b) {return a < b;});

		cout << max << endl;
	}

	{
		std::vector<std::string> vecStr = { "a", "ab", "abc", "ad" };
		std::string max;
		FindMax(vecStr, max, [](std::string const &str1, std::string const &str2) {return str1 < str2;});

		cout << max.c_str() << endl;
	}

	{
		std::vector<const char *> vecChars = { "a", "ab", "abc", "ad" };
		const char * max;
		FindMax(vecChars, max, [](const char *str1, const char *str2) {
					return strcmp(str1, str2) != 1 ? true : false;
				});

		cout << max << endl;
	}

	{
		list<int> lst;
		auto end = lst.end();

		lst.push_back(1);

		cout << (lst.end() == end) << endl;

	}

    return 0;
}

