#include "replace.h"

int CopyFileWithStringReplacing(char *argv[])
{
	std::ifstream inputFile;
	std::ofstream outputFile;
	std::string searchString = argv[3];
	OpenFiles(argv[1], argv[2], inputFile, outputFile);
	if ((IsSearchStringNotEmpty(searchString)) && (IsOpenedFilesCorrect(inputFile, outputFile)))
	{
		std::string replaceString = argv[4];
		std::string currentString;
		std::string bufferString;
		std::string::size_type pos;
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
		return 0;
	}
	return 1;
}