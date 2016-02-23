#include "application.h"

void PrintBaseInstructions()
{
	std::cout << "       Run program on the commmand line with param-s:" << std::endl;
	std::cout << "       solve.exe A B C" << std::endl;
	std::cout << "Good luck. :)" << std::endl;
}

bool IsCountArgumentsCorrect(int const &argc)
{
	if (argc < COUNT_ARGS)
	{
		std::cout << "ERROR: Not enough arguments for the program." << std::endl;
		PrintBaseInstructions();
		return false;
	}
	else if (argc > COUNT_ARGS)
	{
		std::cout << "ERROR: Too many arguments." << std::endl;
		PrintBaseInstructions();
		return false;
	}
	return true;
}