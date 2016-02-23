#include "replace.h"

int main(int argc, char *argv[])
{
	if (IsCountArgumentsCorrect(argc))
	{
		return CopyFileWithStringReplacing(argv);
	}
	return 1;
}