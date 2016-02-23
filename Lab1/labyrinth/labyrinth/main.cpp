#include "labyrinth.h"

int main(int argc, char *argv[])
{
	if (IsCountArgumentsCorrect(argc))
	{
		return OperationWithFilesAndLabyrinth(argv);
	}
	return 1;
}