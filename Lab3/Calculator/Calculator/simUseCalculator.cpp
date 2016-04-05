#include "stdafx.h"
#include "simUseCalculator.h"

using namespace std;
using namespace std::placeholders;

CSimUseCalculator::CSimUseCalculator(CCalculator &calculator, istream &input, ostream &output) 
	: m_calculator(calculator)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "var", bind(&CSimUseCalculator::DeclareVariable, this, _1) },
		{ "let", bind(&CSimUseCalculator::AssignValueToVariable, this, _1) }, 
		{ "fn", bind(&CSimUseCalculator::DeclareFunction, this, _1) }, 
		{ "print", bind(&CSimUseCalculator::PrintInfoAboutIdentifier, this, _1) }, 
		{ "printvars", bind(&CSimUseCalculator::PrintSortedVariables, this) }, 
		{ "printfns", bind(&CSimUseCalculator::PrintSortedFunctions, this) } 
	})
{
}

bool CSimUseCalculator::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it->second(strm);
		return true;
	}

	return false;
}

void CSimUseCalculator::DeclareVariable(istream &args)
{
	string identifier;
	args >> identifier;

	m_calculator.SetVarIdentifier(identifier);
}

void CSimUseCalculator::AssignValueToVariable(istream &args)
{
	string var;
	args >> var;

	if (!m_calculator.SetVarValue(var))
	{
		cout << "Incorrect let var value." << endl;
	}
}

void CSimUseCalculator::DeclareFunction(istream &args)
{
	string fn;
	args >> fn;

	if (!m_calculator.SetFunctionValue(fn))
	{
		cout << "Incorrect function declare." << endl;
	}
}

void CSimUseCalculator::PrintInfoAboutIdentifier(istream &args)const
{
	string identifier;
	args >> identifier;

	m_calculator.PrintInfoAboutIdentifier(identifier);
}

void CSimUseCalculator::PrintSortedVariables()const
{
	m_calculator.PrintVariables();
}

void CSimUseCalculator::PrintSortedFunctions()const
{
	m_calculator.PrintFunctions();
}
