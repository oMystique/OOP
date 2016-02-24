#include "application.h"


int main(int argc, char *argv[]) 
{
	if (IsCountArgumentsCorrect(argc))
	{
		return !ParsingFileAndIvertMatrix(argv[1]);
	}
	return 0;
}