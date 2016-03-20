#include "stdafx.h"
#include <fstream>
#include "dictionary.h"

using namespace std;

static const string INPUT_STOPPER = "...";


bool CApplication::WorkIsNotSuccesfull()
{
	return m_isError;
}

map<string, string> CDictionary::GetDictionary()
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

bool CDictionary::SaveDictionaryInFile(string const &fileName)
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

bool CDictionary::DictionaryHasATranslation(string const &word)
{
	return m_dictionary.find(word) != m_dictionary.end();
}

std::string CDictionary::GetTranslatedWord(std::string const &word)
{
	return m_dictionary.at(word);
}

bool CDictionary::DictIsChanged()
{
	return m_dictIsChanged;
}

CApplication::CApplication(string const &fileName):
	m_fileName(fileName),
	m_isError(false)
{
}

void CApplication::Execute()
{
	string inputString;
	string translate;
	m_isError = m_dictionary.ParseFileInDictionary(m_fileName);
	while ((inputString != INPUT_STOPPER) && (!m_isError))
	{
		cout << "Type a word to translate. Or type ... to exit." << endl;
		getline(cin, inputString);
		if (m_dictionary.DictionaryHasATranslation(inputString))
		{
			cout << m_dictionary.GetTranslatedWord(inputString) << endl;
		}
		else if (inputString != INPUT_STOPPER)
		{
			cout << "In the dictionary this word is missing. Enter the translation." << endl;
			getline(cin, translate);
			if (!m_dictionary.AddWordInDictionary(inputString, translate))
			{
				cout << "Word was ignored." << endl;
			}
		}
	}

	if (m_dictionary.DictIsChanged())
	{
		cout << "Do you want to save changes to a file ? y/n" << endl;
		getline(cin, inputString);
		if (inputString == "y")
		{
			m_isError = m_dictionary.SaveDictionaryInFile(m_fileName);
		}
	}

	if (m_isError)
	{
		cout << "Error reading or writing the file." << endl;
	}
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