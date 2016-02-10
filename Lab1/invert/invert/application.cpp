#include "application.h"


static const unsigned int COUNT_ARGS = 2;

void PrintBaseInstructions()
{
	std::cout << "       Run program on the commmand line with param-s:" << std::endl;
	std::cout << "       invert.exe matrixFile.txt" << std::endl;
	std::cout << "Good luck. :)" << std::endl;
}

bool IsOpenedFilesCorrect(std::ifstream &inputFile)
{
	if (!inputFile)
	{
		std::cout << "ERROR: Don't opening input or output file." << std::endl;
		return false;
	}
	return true;
}

void OpenFiles(char const *inputFileName, std::ifstream &inputFile)
{
	inputFile.open(inputFileName, std::ifstream::in);
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


void FillingAnArrayOfData(std::ifstream &inputFile, std::vector<std::vector<float> > &matrix)
{
	for (unsigned int i = 0; i < MATRIX_SIZE; i++)
	{
		for (unsigned int j = 0; j < MATRIX_SIZE; j++)
		{
			inputFile >> matrix[i][j];
		}
	}
}

bool IsArgumentsCorrect(int const &argc, char *argv[], std::vector<std::vector<float> > &matrix)
{
	if (!IsCountArgumentsCorrect(argc))
	{
		return false;
	}
	std::ifstream inputFile;
	OpenFiles(argv[1], inputFile);
	if (!IsOpenedFilesCorrect(inputFile))
	{
		return false;
	}
	FillingAnArrayOfData(inputFile, matrix);
	inputFile.close();
	return true;
}
