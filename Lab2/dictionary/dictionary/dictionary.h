#pragma once
#include <map>
#include <string>
#include <iostream>

class CDictionary final
{
public:
	bool ParseFileInDictionary(std::string const &fileName);
	bool SaveDictionaryInFile(std::string const &fileName);
	bool AddWordInDictionary(std::string const &word, std::string const &translate);
	bool DictionaryHasATranslation(std::string const &word);
	bool DictIsChanged();
	std::string GetTranslatedWord(std::string const &word);
	std::map <std::string, std::string> GetDictionary();
private:
	std::map <std::string, std::string> m_dictionary;
	bool m_dictIsChanged;
};

class CApplication
{
public:
	CApplication(std::string const &fileName);
	void Execute();
	bool WorkIsNotSuccesfull();
private:
	CDictionary m_dictionary;
	std::string m_fileName;
	bool m_isError;
};