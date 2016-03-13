#include "stdafx.h"
#include <Windows.h>

using namespace std;

bool CheckNumberOfArguments(int countArgs)
{
	return (countArgs == 2);
}

int main(int argc, char *argv[])
{
	if (!CheckNumberOfArguments(argc))
	{
		cout << "Invalid arguments. Enter the path to the program and dictionary file." << endl;
		return 1;
	}

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	CDictionary dict(argv[1]);
	dict.Execute();
	return dict.WorkIsSuccesfull();
}

