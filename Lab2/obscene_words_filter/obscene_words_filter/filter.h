#pragma once
#include <set>
#include <iostream>
#include <string>

class CObsceneWordsFilter
{
public:
	CObsceneWordsFilter();
	void ParsingFileToWordsSet(std::string const &fileName);
	bool WorkIsSuccesfull();
	void Execute();
private:

private:
	std::set<std::wstring> m_obsceneWords;
	bool m_isError;
};