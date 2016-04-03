#pragma once
#include <map>

static const double VAL_NOT_EXISTING = -INFINITY;

struct FunctionParamethers
{
	std::string value1 = "";
	std::string operand = "";
	std::string value2 = "";
};

typedef std::map<std::string, double> VarsArray;
typedef std::map<std::string, FunctionParamethers> FunctionsArray;

class CCalculator
{
public:
	double GetVarValue(std::string const &varIdentifier)const;
	double GetFunctionValue(std::string const &fnIdentifier)const;

	void PrintInfoAboutIdentifier(std::string const &identifier)const;
	void PrintVariables()const;
	void PrintFunctions()const;

	bool SetVarValue(std::string const &varIdentifier, std::string const &varValue);
	bool SetVarIdentifier(std::string const &varIdentifier);
	bool SetFunctionValue(std::string const &fnIdentifier, std::string const &fnValue1, std::string const &fnOperand, std::string const &fnValue2);
private:
	bool VariableIsDeclared(std::string const &varIdentifier)const;
	bool FunctionIsDeclared(std::string const &fnIdentifier)const;
	bool OperandIsCorrect(std::string const &operand)const;

	double CalculateFunction(double value1, std::string const &operand, double value2)const;
	double GetValue(std::string const &identifier)const;
private:
	VarsArray m_vars;
	FunctionsArray m_functions;
};