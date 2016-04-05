#pragma once
#include "../Calculator/Additions.h"

class CCalculator
{
public:
	double GetVarValue(std::string const &varIdentifier)const;
	double GetFunctionValue(std::string const &fnIdentifier)const;

	void PrintInfoAboutIdentifier(std::string const &identifier)const;
	void PrintVariables()const;
	void PrintFunctions()const;

	bool SetVarValue(std::string const &var);
	bool SetVarIdentifier(std::string const &varIdentifier);
	bool SetFunctionValue(std::string const &var);
private:
	bool VariableIsDeclared(std::string const &varIdentifier)const;
	bool FunctionIsDeclared(std::string const &fnIdentifier)const;
	bool ParseLValueAndRValue(std::string const &str, std::string & lValue, std::string &rValue);
	bool ParseRvalue(std::string const &rvalue, std::string &value1, std::string &operand, std::string &value2);

	double CalculateFunction(double value1, std::string const &operand, double value2)const;
	double GetValue(std::string const &identifier)const;
private:
	VarsArray m_vars;
	FunctionsArray m_functions;
};