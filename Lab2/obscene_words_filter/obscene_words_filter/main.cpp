#include "stdafx.h"
#include <Windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	CObsceneWordsFilter filter;
	filter.ParsingFileToWordsSet("input.txt");
	filter.Execute();
	return 0;
}

