#include "stdafx.h"
#include "simUseCalculator.h"
#include "calculatorPuppeteer.h"

using namespace std;

int main()
{
	CCalculatorPuppeteer calc;
	CSimUseCalculator simUseCalc(calc, cin, cout);

	while ((!cin.eof()) && (!cin.fail()))
	{
		cout << ">: ";
		if (!simUseCalc.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}

	return 0;
}