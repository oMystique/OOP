#include "stdafx.h"
#include "../Calculator/calculator.h"
#include <algorithm>
#include <cctype>

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

boost::optional<double> CCalculator::GetFunctionValue(string const &fnIdentifier)const
{
	double value1 = 0;
	double value2 = 0;
	boost::optional<double> output;
	if (FunctionIsDeclared(fnIdentifier))
	{
		auto &fn = *(m_functions.find(fnIdentifier))->second;
		if (fn.IsChanged())
		{
			value1 = GetInfoAboutIdentifier(fn.GetFnParamethers().value1).get();
			if (GetInfoAboutIdentifier(fn.GetFnParamethers().value2).is_initialized())
			{
				value2 = GetInfoAboutIdentifier(fn.GetFnParamethers().value2).get();
			}

			if (isnan(value1) || isnan(value2))
			{
				return NAN;
			}

			fn.SetValue(CalculateFunction(value1, fn.GetFnParamethers().operand, value2));
			fn.Change(false);
		}
		output = fn.GetValue();
	}

	return output;
}

boost::optional<double> CCalculator::GetInfoAboutIdentifier(string const & identifier)const
{
	boost::optional<double> value;

	if (FunctionIsDeclared(identifier))
	{
		value = GetFunctionValue(identifier);
	}
	else if (VariableIsDeclared(identifier))
	{
		value = GetVarValue(identifier);
	}

	return value;
}

Vars CCalculator::GetVariables()const
{
	return m_vars;
}

Functions CCalculator::GetFunctions()const
{
	return m_functions;
}

boost::optional<double> CCalculator::GetVarValue(string const &varIdentifier)const
{
	boost::optional<double> output;

	if (VariableIsDeclared(varIdentifier))
	{
		output = (m_vars.find(varIdentifier))->second->GetValue();
	}

	return output;
}

bool CCalculator::SetVarValue(string const &varIdentifier, string const &varValue)
{
	if (!FunctionIsDeclared(varIdentifier) && (!varIdentifier.empty()))
	{
		SetVarIdentifier(varIdentifier);
		if (VariableIsDeclared(varValue))
		{
			m_vars[varIdentifier]->SetValue(GetVarValue(varValue).get());
		}
		else if (FunctionIsDeclared(varValue))
		{
			m_vars[varIdentifier]->SetValue(GetFunctionValue(varValue).get());
		}
		else
		{
			m_vars[varIdentifier]->SetValue(atof(varValue.c_str()));
		}
		m_vars[varIdentifier]->NotifyUpdate();

		return true;
	}

	return false;
}

bool CCalculator::SetVarIdentifier(string const &varIdentifier)
{
	if (!VariableIsDeclared(varIdentifier) && (!varIdentifier.empty()))
	{
		auto var = make_shared<CVar>(NAN);
		m_vars.emplace(varIdentifier, var);

		return true;
	}

	return false;
}

void CCalculator::SetSubscriber(CFunction &func, std::string const &identifier)
{
	if (FunctionIsDeclared(identifier))
	{
		m_functions[identifier]->SubscribeToFunction(boost::bind(&CFunction::OnUpdate, &func));
	}
	else if (VariableIsDeclared(identifier))
	{
		m_vars[identifier]->SubscribeToFunction(boost::bind(&CFunction::OnUpdate, &func));
	}
}

bool CCalculator::SetFunctionValue(std::string const &fnIdentifier, std::string const &value1, std::string const &operand, std::string const &value2)
{
	FunctionParamethers fnParamethers(value1, operand, value2);

	if ((!FunctionIsDeclared(fnIdentifier)) && (!VariableIsDeclared(fnIdentifier)) && (!fnIdentifier.empty()))
	{
		if (!((FunctionIsDeclared(value1) || (VariableIsDeclared(value1))) 
			|| ((FunctionIsDeclared(value2) || VariableIsDeclared(value2))
				&& (!value2.empty()))))
		{
			return false;
		}
		auto func = make_shared<CFunction>(fnParamethers);
		SetSubscriber(*func, value1);
		SetSubscriber(*func, value2);
		m_functions.emplace(fnIdentifier, func);
		return true;
	}

	return false;
}