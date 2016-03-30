#pragma once
#include "dictionary.h"

class CApplication
{
public:
	CApplication(std::string const &fileName);
	void Execute();
	bool WorkIsNotSuccesfull()const;
private:
	CDictionary m_dictionary;
	std::string m_fileName;
	bool m_isError;
};