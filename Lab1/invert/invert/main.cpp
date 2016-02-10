#include "application.h"

static const unsigned int COUNT_ARGS = 2;

int main(int argc, char *argv[]) 
{
	std::vector<std::vector<float> > matrix(MATRIX_SIZE, std::vector<float>(MATRIX_SIZE));
	if (IsArgumentsCorrect(argc, argv, matrix))
	{
		InvertMatrix(matrix);
	}
	return 0;
}