#include "labyrinth.h"
#include <string>

static const int MAX_LABYRINTH_SIZE = 100;
static const int FINAL_POINT = 999;
static const int WALL = 255;
static const int START_POINT = 1;
static const int FREE_WAY = -1;

void FillingAnInputArrayOfData(std::ifstream &inputFile, 
						std::vector<std::vector<char> > &inputLabyrinthArray,
						int &countLines, int &countColumns)
{
	std::string str;
	while (!inputFile.eof()) {
		std::getline(inputFile, str);
		if (str.size() > 0) {
			if (countColumns < static_cast<int>(str.size()))
			{
				countColumns = static_cast<int>(str.size());
			}
			for (int i = 0; i != str.size(); i++)
			{
				inputLabyrinthArray[countLines][i] = str[i];
			}
			countLines++;
		}
	}
}

void SaveLabyrinthOnFile(std::vector<std::vector<char> > &labyrinth,
					int const &countLines, int const &countColumns,
					std::ofstream &outputFile)
{
	for (int i = 0; i < countLines; i++)
	{
		for (int j = 0; j < countColumns; j++)
		{
			outputFile << labyrinth[i][j];
		}
		outputFile << std::endl;
	}
}

bool CopyArrayFromCharToIntIsSuccesfully(std::vector<std::vector<int> > &intArray,
					std::vector<std::vector<char> > const &charArray,
					int const &countLines, int const &countColumns,
					int &finalCoordinateX, int &finalCoordinateY)
{
	bool startPointMet = false;
	bool finalPointMet = false;
	for (int i = 0; i < countLines; i++)
	{
		for (int j = 0; j < countColumns; j++)
		{
			if (charArray[i][j] == '#')
			{
				intArray[i][j] = WALL;
			}
			else if (charArray[i][j] == ' ')
			{
				intArray[i][j] = FREE_WAY;
			}
			else if (charArray[i][j] == 'A')
			{
				if (startPointMet) 
				{
					return false;
				}
				startPointMet = true;
				intArray[i][j] = START_POINT;
			}
			else if (charArray[i][j] == 'B') 
			{
				finalCoordinateX = i;
				finalCoordinateY = j;
				if (finalPointMet) 
				{
					return false;
				}
				finalPointMet = true;
				intArray[i][j] = FINAL_POINT;
			}
		}
	}
	return (startPointMet && finalPointMet);
}

char StepWayToTop(int &x, int &y, std::vector<std::vector<int> > &workArray,
		std::vector<std::vector<char> > &outputArray,
		int const &countLines, int const &countColumns, bool &finalPointMet) 
{
	if ((workArray[x][y] != FINAL_POINT) && (workArray[x][y] != START_POINT))
	{
		outputArray[x][y] = '.';
	}
	if (workArray[x][y] == START_POINT)
	{
		finalPointMet = true;
		return 0;
	}
	if (workArray[x][y] == WALL)
	{
		return 0;
	}

	if ((workArray[x + 1][y] < workArray[x][y]) && (x + 1 <= countLines))
	{ 
		x++;                        
		return 1;                   
	}                             
	if ((workArray[x - 1][y] < workArray[x][y]) && (x - 1 >= 0))
	{ 
		x--;                    
		return 1;                   
	}                               
	if ((y + 1 <= countColumns) && (workArray[x][y + 1] < workArray[x][y]))
	{ 
		y++;                     
		return 1;                  
	}                               
	y--;
	return 1;                    
}

int WavePropagation(int const &number, std::vector<std::vector<int> > &workLabyrinthArray,
		int const &countLines, int const &countColumns)
{                             
	int flag = 0;        
	for (int i = 0; i < countColumns; i++) 
	{    
		for (int j = 0; j < countLines; j++)    
		{
			if (workLabyrinthArray[j][i] == number) {
				if ((workLabyrinthArray[j + 1][i] == FREE_WAY) && (j + 1 < countLines))
				{    
					workLabyrinthArray[j + 1][i] = number + 1;
					flag = 1;                 
				}
				if ((workLabyrinthArray[j - 1][i] == FREE_WAY) && (j - 1 >= 0))
				{
					workLabyrinthArray[j - 1][i] = number + 1;
					flag = 1;
				}
				if ((workLabyrinthArray[j][i + 1] == FREE_WAY) && (i + 1 < countColumns))
				{
					workLabyrinthArray[j][i + 1] = number + 1;
					flag = 1;
				}
				if ((workLabyrinthArray[j][i - 1] == FREE_WAY) && (i - 1 >= 0))
				{
					workLabyrinthArray[j][i - 1] = number + 1;
					flag = 1;
				}
			}
		}
	}
	return flag;
}

bool FilesIsCorrect(std::ifstream &inputFile, std::ofstream &outputFile,
				char const *nameInputFile, char const *nameOutputFile)
{
	OpenFiles(nameInputFile, inputFile, nameOutputFile, outputFile);
	if (!IsOpenedFilesCorrect(inputFile, outputFile))
	{
		return false;
	}
	return true;
}

void OperationWithLabyrinth(std::vector<std::vector<char> > &inputLabyrinthArray,
						int const &countLines, int const &countColumns) 
{
	std::vector<std::vector<int> > workLabyrinthArray(countLines, std::vector<int>(countColumns));
	int finalCoordinateX;
	int finalCoordinateY;
	if (CopyArrayFromCharToIntIsSuccesfully(workLabyrinthArray, inputLabyrinthArray,
		countLines, countColumns, finalCoordinateX, finalCoordinateY))
	{
		int number = START_POINT;
		while (WavePropagation(number, workLabyrinthArray, countLines, countColumns))
		{
			number++;
		}
		bool finalPointMet = false;
		std::vector<std::vector<char> > outputLabyrinthArray = inputLabyrinthArray;
		while (StepWayToTop(finalCoordinateX, finalCoordinateY, workLabyrinthArray,
			outputLabyrinthArray, countLines, countColumns, finalPointMet))
		{
		}
		if (finalPointMet) {
			inputLabyrinthArray = outputLabyrinthArray;
		}
	}
}

void OperationWithFilesAndLabyrinth(char *argv[]) 
{
	std::ifstream inputLabyrinthFile;
	std::ofstream outputLabyrinthFile;
	if (!FilesIsCorrect(inputLabyrinthFile, outputLabyrinthFile, argv[1], argv[2])) 
	{
		return;
	}
	std::vector<std::vector<char> > inputLabyrinthArray(MAX_LABYRINTH_SIZE, std::vector<char>(MAX_LABYRINTH_SIZE));
	int countLines = 0;
	int countColumns = 0;
	FillingAnInputArrayOfData(inputLabyrinthFile, inputLabyrinthArray, countLines, countColumns);
	OperationWithLabyrinth(inputLabyrinthArray, countLines, countColumns);
	SaveLabyrinthOnFile(inputLabyrinthArray, countLines, countColumns, outputLabyrinthFile);
}


