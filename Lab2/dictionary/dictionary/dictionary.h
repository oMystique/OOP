#pragma once
#include <map>
#include <string>
#include <iostream>

class CDictionary 
{
public:
	CDictionary();
	bool ParseFileInDictionary(std::string const &fileName);
	bool AddWordInDictionary(std::string const &word, std::string const &translate);
	bool DictionaryHasATranslation(std::string const &word)const;
	bool SaveDictionaryInFile(std::string const &fileName)const;
	bool DictIsChanged()const;
	std::string GetTranslatedWord(std::string const &word)const;
	std::map <std::string, std::string> GetDictionary()const;
private:
	std::map <std::string, std::string> m_dictionary;
	bool m_dictIsChanged;
};
