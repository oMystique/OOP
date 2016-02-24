#include "application.h"

static const unsigned int COUNT_ARGS = 2;

void PrintBaseInstructions()
{
	std::cout << "       Run program on the commmand line with param-s:" << std::endl;
	std::cout << "       invert.exe matrixFile.txt" << std::endl;
	std::cout << "Good luck. :)" << std::endl;
}

bool IsOpenedFileCorrect(std::ifstream &inputFile)
{
	if (!inputFile)
	{
		std::cout << "ERROR: Don't opening input file." << std::endl;
		return false;
	}
	return true;
}

void OpenFile(char const *inputFileName, std::ifstream &inputFile)
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

bool ParsingFileAndIvertMatrix(char *nameInputFile) 
{
	std::ifstream inputFile;
	OpenFile(nameInputFile, inputFile);
	if (IsOpenedFileCorrect(inputFile))
	{
		std::vector<std::vector<float> > matrix(MATRIX_SIZE, std::vector<float>(MATRIX_SIZE));
		FillingAnArrayOfData(inputFile, matrix);
		return InvertMatrix(matrix);
	}
	return false;
}