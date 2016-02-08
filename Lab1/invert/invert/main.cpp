#include "matrix.h"

static const unsigned int COUNT_ARGS = 2;

void ExitProgram() {
	system("pause");
	exit(0);
}

void PrintBaseInstructions() {
	std::cout << "       Run program on the commmand line with param-s:" << std::endl;
	std::cout << "       invert.exe nameFile" << std::endl;
	std::cout << "Good luck. :)" << std::endl;
}

void CheckCountArgs(int const &argc) {
	if (argc < COUNT_ARGS) {
		std::cout << "ERROR: Not enough arguments for the program." << std::endl;
		PrintBaseInstructions();
		ExitProgram();
	}
	else if (argc > COUNT_ARGS) {
		std::cout << "ERROR: Too many arguments." << std::endl;
		PrintBaseInstructions();
		ExitProgram();
	}
}

int main(int argc, char *argv[]) {
	CheckCountArgs(argc);
	CMatrix matrix(argv);
	system("pause");
	return 0;
}