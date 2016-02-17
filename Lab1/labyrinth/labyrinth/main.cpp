#include "labyrinth.h"

int main(int argc, char *argv[])
{
	if (IsCountArgumentsCorrect(argc))
	{
		OperationWithFilesAndLabyrinth(argv);
	}
}