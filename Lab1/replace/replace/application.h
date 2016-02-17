#pragma once
#include <string>
#include <iostream>
#include <fstream>

bool IsCountArgumentsCorrect(int const &argc);
void OpenFiles(char const *inputFileName, char const *outputFileName,
	std::ifstream &inputFile, std::ofstream &outputFile);
bool IsOpenedFilesCorrect(std::ifstream &inputFile, std::ofstream &outputFile);
bool IsSearchStringNotEmpty(std::string const &searchString);