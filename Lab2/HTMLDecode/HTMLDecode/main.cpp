#include "stdafx.h"
#include <iostream>
#include "HTMLDecode.h"

using namespace std;

std::string ReadingFromStream()
{
	return {(istreambuf_iterator<char>(std::cin)), istreambuf_iterator<char>()};
}

int _tmain()
{
	cout << "Input html string for decoding: " << endl;
	string inputString = ReadingFromStream();
	string outputString = HTMLDecode(inputString);
	cout << "Output decoded string: " << endl;
	cout << outputString << endl;
	return 0;
}
