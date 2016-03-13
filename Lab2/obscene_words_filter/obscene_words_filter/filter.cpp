#include "stdafx.h"
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <sstream>

using namespace std;

CObsceneWordsFilter::CObsceneWordsFilter():
	m_isError(false)
{
}

bool IsNotAlphaSpace(wchar_t symbol) {
	if (!iswalpha(symbol) && !iswspace(symbol))
	{
		return true;
	}
	return false;
}

void CObsceneWordsFilter::Execute()
{
	wstring inputString;
	wcout << inputString << endl;
	set <wstring> workSet;
	set <wstring> intersectsSet;
	wstring bufferString;
	wstring outputString;
	while (true)
	{
		workSet.clear();

		cout << "Input your message or press enter by empty string to exit: " << endl;
		getline(wcin, inputString);
		outputString = inputString;
		replace_if(inputString.begin(), inputString.end(), IsNotAlphaSpace, ' ');
		wistringstream strStream(inputString);

		while (strStream >> bufferString)
		{
			workSet.emplace(bufferString);
		}

		set_intersection(workSet.begin(), workSet.end(), m_obsceneWords.begin(), m_obsceneWords.end(), inserter(intersectsSet, intersectsSet.begin()));
		for (auto word : intersectsSet)
		{
			outputString.erase(outputString.find(word));
		}

		wcout << outputString << endl;
	}
}

void CObsceneWordsFilter::ParsingFileToWordsSet(string const &fileName)
{
	wifstream inputFile(fileName, ifstream::in);
	if (!inputFile.is_open())
	{
		m_isError = true;
		return;
	}

	wstring inputString;
	while (!inputFile.eof())
	{
		inputFile >> inputString;
		m_obsceneWords.emplace(inputString);
		//boost::algorithm::to_lower_copy(inputString, locale("rus")) ^^^
	}
}