#include "application.h"

int main(int argc, char *argv[])
{
	if (IsArgumentsCorrect(argc, argv))
	{
		FindingRootsOperations(atof(argv[1]), atof(argv[2]), atof(argv[3]));
	}
	return 0;
}