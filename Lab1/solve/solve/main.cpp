#include <iostream>
#include <iomanip>
#include <math.h>

static const unsigned int COUNT_ARGS = 4;
static const double GET_HALF = 2.f;

void ExitProgram() {
	system("pause");
	exit(0);
}

void PrintBaseInstructions() {
	std::cout << "       Run program on the commmand line with param-s:" << std::endl;
	std::cout << "       solve.exe A B C" << std::endl;
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

double CalculateRoot(double const &d, int const sign, double const &a, double const &b) {
	return ((-b + sqrt(d) * (sign)) / (GET_HALF * a));
}

double CalculateDiscriminant(double const &a, double const &b, double const &c) {
	return (pow(b, GET_HALF) - (4 * a * c));
}

void CalculateAndPrintRoots(double const &a, double const &b, double const &d) {
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	if (d == 0) {
		std::cout << std::setprecision(4) << CalculateRoot(0, 0, a, b) << std::endl;
	}
	else {
		std::cout << std::setprecision(4) << CalculateRoot(d, 1, a, b) << " ";
		std::cout << std::setprecision(4) << CalculateRoot(d, -1, a, b) << std::endl;
	}
}

void FindingRootsOperations(char *argv[]) {
	double a = atof(argv[1]);
	double b = atof(argv[2]);
	double c = atof(argv[3]);
	if (a == 0) {
		std::cout << "ERROR: A parameter should not be set to 0." << std::endl;
		ExitProgram();
	}
	double d;
	d = CalculateDiscriminant(a, b, c);
	if (d < 0) {
		std::cout << "*_Sorry, but discriminant is less than zero. There is no real root. ";
	}
	else {
		CalculateAndPrintRoots(a, b, d);
	}
}

int main(int argc, char *argv[]) {
	CheckCountArgs(argc);
	FindingRootsOperations(argv);
	system("pause");
	return 0;
}