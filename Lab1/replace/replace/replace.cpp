#include "replace.h"

void ReplaceEvent(std::string const &searchString, std::string const &replaceString,
				std::ifstream &inputFile, std::ofstream &outputFile)
{
	std::string currentString;
	std::string bufferString;
	std::string::size_type pos;
	std::cout << "*_Find string: " << searchString <<
		", Replace string: " << replaceString << std::endl;
	while (!inputFile.eof())
	{
		std::getline(inputFile, currentString);
		bufferString = "";
		for (pos = 0; pos != currentString.size();)
		{
			if (currentString.substr(pos, searchString.size()) == searchString)
			{
				pos += searchString.size();
				bufferString += replaceString;
			}
			else
			{
				bufferString += currentString[pos];
				pos++;
			}
		}
		outputFile << bufferString << std::endl;
	}
}