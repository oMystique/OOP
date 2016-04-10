#pragma once
#include "../Calculator/Additions.h"
#include "../Calculator/function.h"
#include "../Calculator/var.h"

class CCalculator
{
public:
	boost::optional<double> GetVarValue(std::string const &varIdentifier)const;
	boost::optional<double> GetFunctionValue(std::string const &fnIdentifier)const;
	boost::optional<double> GetInfoAboutIdentifier(std::string const &identifier)const;

	Vars GetVariables()const;
	Functions GetFunctions()const;

	bool SetVarValue(std::string const &varIdentifier, std::string const &varValue);
	bool SetVarIdentifier(std::string const &varIdentifier);
	bool SetFunctionValue(std::string const &fnIdentifier, std::string const &value1, std::string const &operand, std::string const &value2);
private:
	double CalculateFunction(double value1, std::string const &operand, double value2)const;

	bool VariableIsDeclared(std::string const &varIdentifier)const;
	bool FunctionIsDeclared(std::string const &fnIdentifier)const;

	void SetSubscriber(CFunction &func, std::string const &identifier);
private:
	Vars m_vars;
	Functions m_functions;
};