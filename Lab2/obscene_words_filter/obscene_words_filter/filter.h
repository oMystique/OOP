#pragma once
#include <set>
#include <iostream>
#include <string>

class CObsceneWordsFilter 
{
public:
	bool ParsingFileInWordsSet(std::string const &fileName);
	std::wstring FilteringOfInputString(std::wstring inputString);
private:
	void CleanStringOfObsceneWords(std::wstring &outputString, std::set <std::wstring> obsceneWordsInString);
	std::set<std::wstring> ParseStringInSet(std::wstring str);
	std::set<std::wstring> GetSetOfObsceneWordsOfString(std::set<std::wstring> const &wordsSet)const;
private:
	std::set<std::wstring> m_obsceneWords;
};

class CApplication
{
public:
	CApplication(std::string const &fileName);
	bool WorkIsSuccessfull()const;
	void Execute();
private:
	CObsceneWordsFilter m_filter;
	std::string m_fileName;
	bool m_isError;
};