#include "application.h"

static const unsigned int COUNT_ARGS = 5;
static const unsigned int MAX_FILE_SIZE_IN_GB = 2;

void PrintBaseInstructions()
{
	std::cout << "       Run program on the commmand line with param-s:" << std::endl;
	std::cout << "       replace.exe inputFile outputFile searchString replaceString" << std::endl;
	std::cout << "Good luck. :)" << std::endl;
}

std::streamoff GetFileSizeInGygaBites(std::ifstream &file)
{
	std::streamoff currentSeek;
	currentSeek = file.tellg();
	file.seekg(0, file.end);
	std::streamoff fileLength;
	fileLength = file.tellg();
	file.seekg(currentSeek);
	return fileLength / int(pow(1024, 3));
}

bool IsOpenedFilesCorrect(std::ifstream &inputFile, std::ofstream &outputFile)
{
	if ((!inputFile) || (!outputFile))
	{
		std::cout << "ERROR: Don't opening input or output file." << std::endl;
		return false;
	}
	if (GetFileSizeInGygaBites(inputFile) >= MAX_FILE_SIZE_IN_GB)
	{
		std::cout << "ERROR: Too many file size." << std::endl;
		return false;
	}
	return true;
}

void OpenFiles(char const *inputFileName, char const *outputFileName,
			std::ifstream &inputFile, std::ofstream &outputFile)
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

bool IsSearchStringNotEmpty(std::string const &searchString)
{
	if (searchString == "")
	{
		std::cout << "ERROR: The search string is empty." << std::endl;
		return false;
	}
	return true;
}

bool IsArgumentsCorrect(int const &argc, char *argv[],
					std::ifstream &inputFile, std::ofstream &outputFile)
{
	if (!IsCountArgumentsCorrect(argc))
	{
		return false;
	}
	else if (!IsSearchStringNotEmpty(argv[3]))
	{
		return false;
	}
	OpenFiles(argv[1], argv[2], inputFile, outputFile);
	if (!IsOpenedFilesCorrect(inputFile, outputFile))
	{
		return false;
	}
	return true;
}
