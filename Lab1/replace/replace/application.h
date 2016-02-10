#pragma once
#include <string>
#include <iostream>
#include <fstream>

bool IsArgumentsCorrect(int const &argc, char *argv[],
					std::ifstream &inputFile, std::ofstream &outputFile);