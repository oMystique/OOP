#include "stdafx.h"
#include <fstream>
#include <sstream>
#include "filter.h"
#include <boost/algorithm/string.hpp>

using namespace std;

CApplication::CApplication(string const &fileName):
	m_isError(false),
	m_fileName(fileName)
{
}

bool IsNotAlphaSpace(wchar_t symbol) 
{
	return (!iswalpha(symbol) && !iswspace(symbol));
}

set<wstring> CObsceneWordsFilter::ParseStringInSet(wstring str)
{
	replace_if(str.begin(), str.end(), IsNotAlphaSpace, ' ');
	wistringstream strStream(str);

	wstring bufferString;
	set <wstring> workSet;
	while (strStream >> bufferString)
	{
		workSet.emplace(bufferString);
	}

	return workSet;
}

void CObsceneWordsFilter::CleanStringOfObsceneWords(wstring &outputString, set <wstring> obsceneWordsInString)
{
	for (auto word : obsceneWordsInString)
	{
		outputString.erase(outputString.find(word), word.size());
	}
}

std::set<std::wstring> CObsceneWordsFilter::GetSetOfObsceneWordsOfString(set<wstring> const &wordsSet)const
{
	set<wstring> intersectsSet;
	set_intersection(wordsSet.begin(), wordsSet.end(), m_obsceneWords.begin(),
		m_obsceneWords.end(), inserter(intersectsSet, intersectsSet.begin()));
	return intersectsSet;
}

wstring CObsceneWordsFilter::FilteringOfInputString(wstring workString)
{
	auto wordsSet = ParseStringInSet(workString);
	auto obsceneWordsSet = GetSetOfObsceneWordsOfString(wordsSet);
	CleanStringOfObsceneWords(workString, obsceneWordsSet);
	return workString;
}

bool CObsceneWordsFilter::ParsingFileInWordsSet(string const &fileName)
{
	wifstream inputFile(fileName, ifstream::in);
	if (!inputFile.is_open())
	{
		return true;
	}

	wstring inputString;
	while (!inputFile.eof())
	{
		inputFile >> inputString;
		m_obsceneWords.emplace(inputString);
	}
	return false;
}

bool CApplication::WorkIsSuccessfull()const
{
	return m_isError;
}

void CApplication::Execute()
{
	wstring inputString = L"String Is Not Empty";
	m_isError = m_filter.ParsingFileInWordsSet(m_fileName);
	while (!inputString.empty())
	{
		cout << "Input your message or press enter by empty string to exit: " << endl;
		getline(wcin, inputString);
		wcout << m_filter.FilteringOfInputString(inputString) << endl;
	}
	cout << "Goodbye :)" << endl;
}