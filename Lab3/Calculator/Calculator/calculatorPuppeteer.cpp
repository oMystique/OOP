#include "stdafx.h"
#include "calculatorPuppeteer.h"
#include <iostream>
#include <boost/utility/string_ref.hpp>
#include <iomanip>

using namespace std;
using boost::string_ref;

void CCalculatorPuppeteer::PrintInfoAboutIdentifier(string const & identifier) const
{
	auto value = m_calculator.GetInfoAboutIdentifier(identifier);

	if (!value.is_initialized())
	{
		cout << "Value not existing." << endl;
	}
	else
	{
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << setprecision(2) << value << endl;
	}
	
}

void CCalculatorPuppeteer::PrintVariables()const
{
	cout.setf(ios_base::fixed, ios_base::floatfield);

	for (auto it : m_calculator.GetVariables())
	{
		cout << it.first << ":" << setprecision(2) << it.second->GetValue() << endl;
	}

}

void CCalculatorPuppeteer::PrintFunctions()const
{
	cout.setf(ios_base::fixed, ios_base::floatfield);

	for (auto it : m_calculator.GetFunctions())
	{
		cout << it.first << ":" << setprecision(2) << m_calculator.GetFunctionValue(it.first) << endl;
	}
}

void CCalculatorPuppeteer::SetVarValue(string const & var)
{
	string varIdentifier;
	string varValue;

	if (!ParseLValueAndRValue(var, varIdentifier, varValue)
		|| (!m_calculator.SetVarValue(varIdentifier, varValue)))
	{
		cout << "Incorrect expression." << endl;
	}
}

void CCalculatorPuppeteer::SetVarIdentifier(string const & varIdentifier)
{
	if (!m_calculator.SetVarIdentifier(varIdentifier))
	{
		cout << "Incorrect var name." << endl;
	}
}

void CCalculatorPuppeteer::SetFunctionValue(string const & fn)
{
	string fnIdentifier;
	string rvalue;

	string value1;
	string operand;
	string value2;

	if (!ParseLValueAndRValue(fn, fnIdentifier, rvalue) ||
		(!ParseRvalue(rvalue, value1, operand, value2)) 
		|| !m_calculator.SetFunctionValue(fnIdentifier, value1, operand, value2))
	{
		cout << "Incorrect expression." << endl;
	}
}

bool CCalculatorPuppeteer::ParseLValueAndRValue(string const & str, string & lValue, string & rValue)
{
	if (isdigit(str.c_str()[0]))
	{
		return false;
	}

	string_ref strRef(str);
	auto equallyPos = strRef.find("=");

	if ((equallyPos == string::npos) || (equallyPos + 1 == str.size()))
	{
		return false;
	}

	lValue = strRef.substr(0, equallyPos).to_string();
	rValue = strRef.substr(equallyPos + 1, str.size()).to_string();

	return true;
}

bool CCalculatorPuppeteer::ParseRvalue(string const & rvalue, string & value1, string & operand, string & value2)
{
	vector<string> operands = { "+", "*", "/", "-" };

	string_ref rvalueRef(rvalue);

	size_t operandPos = string::npos;

	for (auto it : operands)
	{
		operandPos = rvalueRef.find(it);
		if (operandPos != string::npos)
		{
			break;
		}
	}

	if (operandPos != string::npos)
	{
		value1 = rvalueRef.substr(0, operandPos).to_string();
		operand = rvalueRef.to_string().c_str()[operandPos];
		value2 = rvalueRef.substr(operandPos + 1, rvalue.size()).to_string();
	}
	else
	{
		value1 = rvalue;
	}

	return true;
}
