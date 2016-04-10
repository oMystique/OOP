#pragma once
#include "calculator.h"
#include <functional>

class CCalculatorPuppeteer
{
public:
	void PrintInfoAboutIdentifier(std::string const &identifier)const;
	void PrintVariables()const;
	void PrintFunctions()const;

	void SetVarValue(std::string const &var);
	void SetVarIdentifier(std::string const &varIdentifier);
	void SetFunctionValue(std::string const &fn);
private:
	bool ParseLValueAndRValue(std::string const &str, std::string & lValue, std::string &rValue);
	bool ParseRvalue(std::string const &rvalue, std::string &value1, std::string &operand, std::string &value2);
private:
	CCalculator m_calculator;
};