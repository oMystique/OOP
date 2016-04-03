#include "stdafx.h"
#include "../Calculator/calculator.h"
#include <iomanip>

using namespace std;

bool CCalculator::FunctionIsDeclared(string const &fnIdentifier)const
{
	return (m_functions.find(fnIdentifier) != m_functions.end());
}

bool CCalculator::VariableIsDeclared(string const &varIdentifier)const
{
	return (m_vars.find(varIdentifier) != m_vars.end());
}

bool CCalculator::OperandIsCorrect(string const &operand)const
{
	return ((operand == "+") || (operand == "/") || (operand == "*") || (operand == "-"));
}

double CCalculator::CalculateFunction(double value1, string const &operand, double value2)const
{
	if (operand == "+")
	{
		return value1 + value2;
	}
	else if (operand == "*")
	{
		return value1 * value2;
	}
	else if (operand == "/")
	{
		return value1 / value2;
	}
	else if (operand == "-")
	{
		return value1 - value2;
	}
	return value1;
}

double CCalculator::GetValue(string const &identifier)const
{
	if (FunctionIsDeclared(identifier))
	{
		return GetFunctionValue(identifier);
	}
	else if (VariableIsDeclared(identifier))
	{
		return GetVarValue(identifier);
	}
	return 0;
}

double CCalculator::GetFunctionValue(string const &fnIdentifier)const
{
	double value1;
	double value2;
	if (FunctionIsDeclared(fnIdentifier))
	{
		FunctionParamethers fnParamethers = (m_functions.find(fnIdentifier))->second;
		value1 = GetValue(fnParamethers.value1);
		value2 = GetValue(fnParamethers.value2);
		if (isnan(value1) || isnan(value2))
		{
			return NAN;
		}
		return CalculateFunction(value1, fnParamethers.operand, value2);
	}
	return VAL_NOT_EXISTING;
}

void CCalculator::PrintInfoAboutIdentifier(std::string const & identifier) const
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	if (FunctionIsDeclared(identifier) && (GetFunctionValue(identifier) != VAL_NOT_EXISTING))
	{
		cout << setprecision(2) <<GetFunctionValue(identifier) << endl;
	}
	else if (VariableIsDeclared(identifier) && (GetVarValue(identifier) != VAL_NOT_EXISTING))
	{
		cout << setprecision(2) << GetVarValue(identifier) << endl;
	}
}

void CCalculator::PrintVariables()const
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	for (auto it : m_vars)
	{
		cout << it.first << ":" << setprecision(2) <<  it.second << endl;
	}
}

void CCalculator::PrintFunctions()const
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	for (auto it : m_functions)
	{
		cout << it.first << ":" << setprecision(2) << GetFunctionValue(it.first) << endl;
	}
}

double CCalculator::GetVarValue(string const &varIdentifier)const
{
	if (VariableIsDeclared(varIdentifier))
	{
		return (m_vars.find(varIdentifier))->second;
	}
	return VAL_NOT_EXISTING;
}

bool CCalculator::SetVarValue(string const &varIdentifier, string const &varValue)
{
	if (!FunctionIsDeclared(varIdentifier) && (!varIdentifier.empty()))
	{
		SetVarIdentifier(varIdentifier);
		if (VariableIsDeclared(varValue))
		{
			m_vars[varIdentifier] = GetVarValue(varValue);
		}
		else if (FunctionIsDeclared(varValue))
		{
			m_vars[varIdentifier] = GetFunctionValue(varValue);
		}
		else
		{
			m_vars[varIdentifier] = atof(varValue.c_str());
		}
		return true;
	}
	return false;
}

bool CCalculator::SetVarIdentifier(string const &varIdentifier)
{
	if (!VariableIsDeclared(varIdentifier) && (!varIdentifier.empty()))
	{
		m_vars.emplace(varIdentifier, NAN);
		return true;
	}
	return false;
}

bool CCalculator::SetFunctionValue(string const &fnIdentifier, string const &fnValue1, string const &fnOperand, string const &fnValue2)
{
	if ((!FunctionIsDeclared(fnIdentifier)) && (!VariableIsDeclared(fnIdentifier)) && (!fnIdentifier.empty()))
	{
		FunctionParamethers fnParamethers;
		if (!((FunctionIsDeclared(fnValue1)) || (VariableIsDeclared(fnValue1))))
		{
			return false;
		}
		fnParamethers.value1 = fnValue1;
		if ((!fnValue2.empty()))
		{
			if (!(OperandIsCorrect(fnOperand)))
			{
				return false;
			}
			fnParamethers.operand = fnOperand;
			fnParamethers.value2 = fnValue2;
		}
		m_functions.emplace(fnIdentifier, fnParamethers);
		return true;
	}
	return false;
}