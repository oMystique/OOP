#include "stdafx.h"
#include <fstream>
#include "dictionary.h"

using namespace std;

CDictionary::CDictionary() :
	m_dictIsChanged(false)
{
}

map<string, string> CDictionary::GetDictionary()const
{
	return m_dictionary;
}

bool CDictionary::AddWordInDictionary(string const &word, string const &translate)
{
	if ((!word.empty()) && (!translate.empty()))
	{
		m_dictIsChanged = true;
		m_dictionary.emplace(word, translate);
		return true;
	}
	return false;
}

bool CDictionary::SaveDictionaryInFile(string const &fileName)const
{
	ofstream outputFile(fileName, ostream::out);
	if (!outputFile.is_open())
	{
		return true;
	}
	for (auto &dict : m_dictionary)
	{
		outputFile << dict.first << ":" << dict.second << endl;
	}
	return false;
}

bool CDictionary::DictionaryHasATranslation(string const &word)const
{
	return m_dictionary.find(word) != m_dictionary.end();
}

std::string CDictionary::GetTranslatedWord(std::string const &word)const
{
	return m_dictionary.at(word);
}

bool CDictionary::DictIsChanged()const
{
	return m_dictIsChanged;
}


bool CDictionary::ParseFileInDictionary(string const &fileName)
{
	ifstream inputFile(fileName, ifstream::in);
	string bufferStr;
	if (!inputFile.is_open())
	{
		return true;
	}
	size_t separatorPos;
	while (getline(inputFile, bufferStr))
	{
		separatorPos = bufferStr.find_first_of(":");
		m_dictionary.emplace(bufferStr.substr(0, separatorPos), bufferStr.substr(separatorPos + 1, bufferStr.size()));
	}
	return false;
}