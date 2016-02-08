#pragma once
#include <string.h>
#include <iostream>
#include <fstream>

class CApplication {
public:
	CApplication(char *argv[]);
	~CApplication();
private:
	void CheckCorrectnessArgs();
	void ReplaceEvent();
private:
	std::string m_searchString;
	std::string m_replaceString;
	std::ofstream m_outputFile;
	std::ifstream m_inputFile;
};


void ExitProgram();
