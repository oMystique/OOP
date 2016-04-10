#include "stdafx.h"
#include "simUseCalculator.h"

using namespace std;
using namespace std::placeholders;

CSimUseCalculator::CSimUseCalculator(CCalculatorPuppeteer calcPuppeteer, istream &input, ostream &output)
	: m_calcPuppeteer(calcPuppeteer)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "var", bind(&CSimUseCalculator::DeclareVariable, this, std::placeholders::_1) },
		{ "let", bind(&CSimUseCalculator::AssignValueToVariable, this, std::placeholders::_1) },
		{ "fn", bind(&CSimUseCalculator::DeclareFunction, this, std::placeholders::_1) },
		{ "print", bind(&CSimUseCalculator::PrintInfoAboutIdentifier, this, std::placeholders::_1) },
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

	m_calcPuppeteer.SetVarIdentifier(identifier);
}

void CSimUseCalculator::AssignValueToVariable(istream &args)
{
	string var;
	args >> var;

	m_calcPuppeteer.SetVarValue(var);
}

void CSimUseCalculator::DeclareFunction(istream &args)
{
	string fn;
	args >> fn;

	m_calcPuppeteer.SetFunctionValue(fn);
}

void CSimUseCalculator::PrintInfoAboutIdentifier(istream &args)const
{
	string identifier;
	args >> identifier;

	m_calcPuppeteer.PrintInfoAboutIdentifier(identifier);
}

void CSimUseCalculator::PrintSortedVariables()const
{
	m_calcPuppeteer.PrintVariables();
}

void CSimUseCalculator::PrintSortedFunctions()const
{
	m_calcPuppeteer.PrintFunctions();
}
