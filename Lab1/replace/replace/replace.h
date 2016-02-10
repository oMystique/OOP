#pragma once
#include <string>
#include <iostream>
#include <fstream>

void ReplaceEvent(std::string const &searchString, std::string const &replaceString,
	std::ifstream &inputFile, std::ofstream &outputFile);