#pragma once
#include <iostream>
#include <fstream>
#include <vector>

bool IsCountArgumentsCorrect(int const &argc);
void OpenFiles(char const *inputFileName, std::ifstream &inputFile,
	char const *outputFileName, std::ofstream &outputFile);
bool IsOpenedFilesCorrect(std::ifstream &inputFile, std::ofstream &outputFile);
