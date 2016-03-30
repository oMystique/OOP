#include "stdafx.h"
#include "application.h"

using namespace std;

static const string INPUT_STOPPER = "...";

CApplication::CApplication(string const &fileName) :
	m_fileName(fileName),
	m_isError(false)
{
}

bool CApplication::WorkIsNotSuccesfull()const
{
	return m_isError;
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