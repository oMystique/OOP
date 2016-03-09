// HTMLDecode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <map>
#include "HTMLDecode.h"

using namespace std;

string HTMLDecode(string const &htmlString)
{
	map<string, string> arrayOfCharactersToReplaced = 
	{ 
		{"&quot", "\"" },
		{"&apos", "'"},
		{"&lt", "<"},
		{"&qt", ">"},
		{"&amp", "&"} 
	};
	string returnString;
	for (unsigned i = 0; i < htmlString.size(); i++)
	{
		if (htmlString[i] == '&') 
		{
			for (auto it = arrayOfCharactersToReplaced.begin(); it != arrayOfCharactersToReplaced.end(); it++)
			{
				if (htmlString.substr(i, it->first.size()) == it->first)
				{
					returnString.append(it->second);
					i += it->first.size();
					break;
				}
			}
		}
		returnString += htmlString[i];
	}
	return returnString;
}

