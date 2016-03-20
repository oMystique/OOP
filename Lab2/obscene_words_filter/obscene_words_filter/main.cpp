#include "stdafx.h"
#include <Windows.h>

bool CheckNumberOfArguments(int countArgs)
{
	return (countArgs == 2);
}

int main(int argc, char *argv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	if (!CheckNumberOfArguments(argc))
	{
		std::cout << "Invalid arguments. Enter the path to the program and dictionary file." << std::endl;
		return 1;
	}

	CApplication app(argv[1]);
	app.Execute();
	return app.WorkIsSuccessfull();
}

