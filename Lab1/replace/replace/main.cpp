#include "application.h"

static const unsigned int COUNT_ARGS = 5;

void PrintBaseInstructions() {
	std::cout << "       Run program on the commmand line with param-s:" << std::endl;
	std::cout << "       replace.exe inputFile outputFile searchString replaceString" << std::endl;
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
	CApplication app(argv);
	return 0;
}