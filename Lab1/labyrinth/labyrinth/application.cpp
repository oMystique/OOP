#include "application.h"

static const unsigned int COUNT_ARGS = 3;

void PrintBaseInstructions()
{
	std::cout << "       Run program on the commmand line with param-s:" << std::endl;
	std::cout << "       labyrinth.exe inputFile.txt outputFile" << std::endl;
	std::cout << "Good luck. :)" << std::endl;
}

bool IsOpenedFilesCorrect(std::ifstream &inputFile, std::ofstream &outputFile)
{
	if ((!inputFile) || (!outputFile))
	{
		std::cout << "ERROR: Don't opening input or output file." << std::endl;
		return false;
	}
	return true;
}

void OpenFiles(char const *inputFileName, std::ifstream &inputFile,
			char const *outputFileName, std::ofstream &outputFile)
{
	inputFile.open(inputFileName, std::ifstream::in);
	outputFile.open(outputFileName, std::ofstream::out);
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