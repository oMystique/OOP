#pragma once
#include <boost/noncopyable.hpp>
#include <map>
#include <functional>
#include "calculatorPuppeteer.h"

class CSimUseCalculator: boost::noncopyable
{
public:
	CSimUseCalculator(CCalculatorPuppeteer calcPuppeteer, std::istream &input, std::ostream &output);
	bool HandleCommand();
private:
	void DeclareVariable(std::istream & args);
	void AssignValueToVariable(std::istream & args);
	void DeclareFunction(std::istream &args);

	void PrintInfoAboutIdentifier(std::istream &args)const;
	void PrintSortedVariables()const;
	void PrintSortedFunctions()const;
private:
	typedef std::map<std::string, std::function<void(std::istream & args) >> ActionMap;

	std::istream &m_input;
	std::ostream &m_output;

	CCalculatorPuppeteer m_calcPuppeteer;
	const ActionMap m_actionMap;
};