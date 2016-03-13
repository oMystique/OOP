#pragma once
#include <map>
#include <string>
#include <iostream>

class CDictionary
{
public:
	CDictionary(std::string const &fileName);
	void Execute();
	bool WorkIsSuccesfull();
private:
	void ParseFileInDictionary();
	void SaveDictionaryInFile();
	bool AddWordInDictionary(std::string const &word);
	bool DictionaryHasATranslation(std::string const &word);
private:
	std::map <std::string, std::string> m_dictionary;
	std::string m_fileName;
	bool m_isError;
	bool m_dictIsChanged;
};