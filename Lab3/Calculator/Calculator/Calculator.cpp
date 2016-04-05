#include "stdafx.h"
#include "../Calculator/calculator.h"
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

bool CCalculator::FunctionIsDeclared(string const &fnIdentifier)const
{
	return (m_functions.find(fnIdentifier) != m_functions.end());
}

bool CCalculator::VariableIsDeclared(string const &varIdentifier)const
{
	return (m_vars.find(varIdentifier) != m_vars.end());
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

void CCalculator::PrintInfoAboutIdentifier(string const & identifier)const
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

bool CCalculator::ParseLValueAndRValue(string const & str, string &lValue, string &rValue)
{
	if (isdigit(str.c_str()[0]))
	{
		return false;
	}

	auto equallyPos = str.find_first_of("=", 1);

	if ((equallyPos == string::npos) || (equallyPos + 1 == str.size()))
	{
		return false;
	}
	lValue = str.substr(0, equallyPos);
	rValue = str.substr(equallyPos + 1, str.size());

	return true;
}

bool CCalculator::SetVarValue(string const &var)
{
	string varIdentifier;
	string varValue;
	if (!ParseLValueAndRValue(var, varIdentifier, varValue))
	{
		return false;
	}
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

bool CCalculator::ParseRvalue(std::string const & rvalue, std::string & value1, std::string & operand, std::string & value2)
{
	vector<string> operands = { "+", "*", "/", "-" };
	size_t operandPos = string::npos;

	for (auto it : operands)
	{
		operandPos = rvalue.find_first_of(it);
		if (operandPos != string::npos)
		{
			break;
		}
	}

	if (operandPos != string::npos)
	{
		value1 = rvalue.substr(0, operandPos);
		operand = rvalue.c_str()[operandPos];
		value2 = rvalue.substr(operandPos + 1, rvalue.size());
	}
	else
	{
		value1 = rvalue;
	}

	return true;
}

bool CCalculator::SetFunctionValue(string const &fn)
{
	string fnIdentifier;
	string value;
	FunctionParamethers fnParamethers;

	if (!ParseLValueAndRValue(fn, fnIdentifier, value) || 
		(!ParseRvalue(value, fnParamethers.value1, fnParamethers.operand, fnParamethers.value2)))
	{
		return false;
	}

	if ((!FunctionIsDeclared(fnIdentifier)) && (!VariableIsDeclared(fnIdentifier)) && (!fnIdentifier.empty()))
	{
		if (!((FunctionIsDeclared(fnParamethers.value1) || (VariableIsDeclared(fnParamethers.value1))) 
			|| (FunctionIsDeclared(fnParamethers.value2) || VariableIsDeclared(fnParamethers.value2)
				&& (!fnParamethers.value2.empty()))))
		{
			return false;
		}

		m_functions.emplace(fnIdentifier, fnParamethers);
		return true;
	}

	return false;
}