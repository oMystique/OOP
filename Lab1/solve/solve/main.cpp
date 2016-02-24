#include "application.h"

int main(int argc, char *argv[])
{
	if (IsCountArgumentsCorrect(argc))
	{
		return !FindingRootsOperations(atof(argv[1]), atof(argv[2]), atof(argv[3]));
	}
	return 1;
}