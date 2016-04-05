#pragma once
#include <map>
#include <boost/algorithm/string/case_conv.hpp>

static const double VAL_NOT_EXISTING = -INFINITY;

struct FunctionParamethers
{
	std::string value1 = "";
	std::string operand = "";
	std::string value2 = "";
};

struct StrLess : public std::binary_function<std::string, std::string, bool>
{
	bool operator () (const std::string &str1, const std::string &str2) { return _stricoll(str1.c_str(), str2.c_str()) < 0; }
};

typedef std::map<std::string, double, StrLess> VarsArray;
typedef std::map<std::string, FunctionParamethers, StrLess> FunctionsArray;

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