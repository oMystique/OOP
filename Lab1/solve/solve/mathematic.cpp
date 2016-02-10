#include "mathematic.h"

double CalculateRoot(double const &d, int const sign, double const &a, double const &b)
{
	return ((-b + sqrt(d) * (sign)) / (GET_HALF * a));
}

double CalculateDiscriminant(double const &a, double const &b, double const &c)
{
	return (pow(b, GET_HALF) - (4 * a * c));
}

void CalculateAndPrintRoots(double const &a, double const &b, double const &d)
{
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	if (d == 0)
	{
		std::cout << std::setprecision(4) << CalculateRoot(0, 0, a, b) << std::endl;
	}
	else
	{
		std::cout << std::setprecision(4) << CalculateRoot(d, 1, a, b) << " ";
		std::cout << std::setprecision(4) << CalculateRoot(d, -1, a, b) << std::endl;
	}
}

void FindingRootsOperations(double a, double b, double c)
{
	double d;
	d = CalculateDiscriminant(a, b, c);
	if (d < 0)
	{
		std::cout << "*_Sorry, but discriminant is less than zero. There is no real root. ";
	}
	else
	{
		CalculateAndPrintRoots(a, b, d);
	}
}
