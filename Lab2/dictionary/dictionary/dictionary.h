#pragma once
#include <map>
#include <string>
#include <iostream>

namespace testSuiteDictionary
{
	struct testAddWordInDictionary;
	struct testGetTrueTranslating;
	struct testGetFalseTranslating;
	struct testParseFileInDictionary;
	struct testAddEmptyWordInDictionary;
}

class CDictionary
{
	friend struct::testSuiteDictionary::testAddWordInDictionary;
	friend struct::testSuiteDictionary::testGetTrueTranslating;
	friend struct::testSuiteDictionary::testGetFalseTranslating;
	friend struct::testSuiteDictionary::testParseFileInDictionary;
	friend struct::testSuiteDictionary::testAddEmptyWordInDictionary;
public:
	CDictionary(std::string const &fileName);
	void Execute();
	bool WorkIsNotSuccesfull();
private:
	void ParseFileInDictionary();
	void SaveDictionaryInFile();
	bool AddWordInDictionary(std::string const &word, std::string const &translate);
	bool DictionaryHasATranslation(std::string const &word);
	std::string GetTranslatedWord(std::string const &word);
	std::map<std::string, std::string> GetDictionary();
private:
	std::map <std::string, std::string> m_dictionary;
	std::string m_fileName;
	bool m_isError;
	bool m_dictIsChanged;
};