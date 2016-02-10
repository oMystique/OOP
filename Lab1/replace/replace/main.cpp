#include "application.h"
#include "replace.h"

int main(int argc, char *argv[])
{
	std::ifstream inputFile;
	std::ofstream outputFile;
	if (IsArgumentsCorrect(argc, argv, inputFile, outputFile))
	{
		ReplaceEvent(argv[3], argv[4], inputFile, outputFile);
	}
	return 0;
}