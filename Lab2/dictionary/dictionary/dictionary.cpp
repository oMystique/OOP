#include "stdafx.h"
#include <fstream>

using namespace std;

static const string INPUT_STOPPER = "...";

CDictionary::CDictionary(string const &fileName) :
	m_fileName(fileName),
	m_isError(false),
	m_dictIsChanged(false)
{
}

bool CDictionary::WorkIsSuccesfull()
{
	return m_isError;
}

bool CDictionary::AddWordInDictionary(string const &word)
{
	string translate;
	getline(cin, translate);
	if (translate.size() > 0)
	{
		m_dictionary.emplace(word, translate);
		m_dictIsChanged = true;
		return true;
	}
	return false;
}

void CDictionary::SaveDictionaryInFile()
{
	ofstream outputFile(m_fileName, ostream::out);
	if (!outputFile.is_open())
	{
		m_isError = true;
	}
	for (auto &dict : m_dictionary)
	{
		outputFile << dict.first << ":" << dict.second << endl;
	}
}

bool CDictionary::DictionaryHasATranslation(string const &word)
{
	return m_dictionary.find(word) != m_dictionary.end();
}

void CDictionary::Execute()
{
	ParseFileInDictionary();
	string inputString;

	while ((inputString != INPUT_STOPPER) && (!m_isError))
	{
		cout << "Type a word to translate. Or type ... to exit." << endl;
		getline(cin, inputString);
		if (DictionaryHasATranslation(inputString))
		{
			cout << m_dictionary.at(inputString) << endl;;
		}
		else if (inputString != INPUT_STOPPER)
		{
			cout << "In the dictionary this word is missing. Enter the translation." << endl;
			if (!AddWordInDictionary(inputString))
			{
				cout << "Word was ignored." << endl;
			}
		}
	}

	if (m_dictIsChanged)
	{
		cout << "Do you want to save changes to a file ? y/n" << endl;
		getline(cin, inputString);
		if (inputString == "y")
		{
			SaveDictionaryInFile();
		}
	}

	if (m_isError)
	{
		cout << "Error reading or writing the file." << endl;
	}
}

void CDictionary::ParseFileInDictionary()
{
	ifstream inputFile(m_fileName, ifstream::in);
	string bufferStr;
	if (!inputFile.is_open())
	{
		m_isError = true;
		return;
	}
	size_t separatorPos;
	while (getline(inputFile, bufferStr))
	{
		separatorPos = bufferStr.find_first_of(":");
		m_dictionary.emplace(bufferStr.substr(0, separatorPos), bufferStr.substr(separatorPos + 1, bufferStr.size()));
	}
}