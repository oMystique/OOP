#include "replace.h"

int main(int argc, char *argv[])
{
	if (IsCountArgumentsCorrect(argc))
	{
		CopyFileWithStringReplacing(argv);
	}
	return 0;
}