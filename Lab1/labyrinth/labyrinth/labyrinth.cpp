#include "labyrinth.h"
#include <algorithm>
#include <string>

SLabyrinth::SLabyrinth()
{
	inputLabyrinthArray.resize(MAX_LABYRINTH_SIZE, std::vector<char>(MAX_LABYRINTH_SIZE));
	finalCoordinateX = 0;
	finalCoordinateY = 0;
	countLines = 0;
	countColumns = 0;
}

void FillingAnInputArrayOfData(std::ifstream &inputFile, 
						SLabyrinth &labyrinth)
{
	std::string str;
	while (!inputFile.eof())
	{
		std::getline(inputFile, str);
		if (str.size() > 0) 
		{
			if (labyrinth.countColumns < static_cast<int>(str.size()))
			{
				labyrinth.countColumns = static_cast<int>(str.size());
			}
			for (int i = 0; i != str.size(); i++)
			{
				labyrinth.inputLabyrinthArray[labyrinth.countLines][i] = str[i];
			}
			labyrinth.countLines++;
		}
	}
}

void SaveLabyrinthOnFile(SLabyrinth const &labyrinth,
					std::ofstream &outputFile)
{
	for (int i = 0; i < labyrinth.countLines; i++)
	{
		for (int j = 0; j < labyrinth.countColumns; j++)
		{
			outputFile << labyrinth.inputLabyrinthArray[i][j];
		}
		outputFile << std::endl;
	}
}

bool CopyArrayFromCharToIntIsSuccesfully(std::vector<std::vector<int> > &intArray,
	SLabyrinth &labyrinth)
{
	bool startPointMet = false;
	bool finalPointMet = false;
	for (int i = 0; i < labyrinth.countLines; i++)
	{
		for (int j = 0; j < labyrinth.countColumns; j++)
		{
			char const &currentCharElement = labyrinth.inputLabyrinthArray[i][j];
			int &currentIntElement = intArray[i][j];
			if (currentCharElement == '#')
			{
				currentIntElement = WALL;
			}
			else if (currentCharElement == ' ')
			{
				currentIntElement = FREE_WAY;
			}
			else if (currentCharElement == 'A')
			{
				if (startPointMet) 
				{
					std::cout << "Found more than one starting points A." << std::endl;
					return false;
				}
				startPointMet = true;
				currentIntElement = START_POINT;
				labyrinth.finalCoordinateX = i;
				labyrinth.finalCoordinateY = j;
			}
			else if (currentCharElement == 'B')
			{
				if (finalPointMet) 
				{
					std::cout << "Found more than one final points B." << std::endl;
					return false;
				}
				finalPointMet = true;
				currentIntElement = FINAL_POINT;
			}
		}
	}
	return (startPointMet && finalPointMet);
}

char StepWayToTop(SLabyrinth &labyrinth, std::vector<std::vector<int> > &workArray,
	std::vector<std::vector<char> > &outputArray, bool &finalPointMet)
{
	int &x = labyrinth.finalCoordinateX;
	int &y = labyrinth.finalCoordinateY;
	int const &currentElement = workArray[x][y];
	int minElement = std::min((std::min(workArray[x + 1][y], workArray[x - 1][y])),
		(std::min(workArray[x][y + 1], workArray[x][y - 1])));
	if ((currentElement != FINAL_POINT) && (currentElement != START_POINT) && (currentElement != WALL))
	{	
		outputArray[x][y] = '.';
	}
	if (currentElement == FINAL_POINT)
	{
		finalPointMet = true;
		return 0;
	}
	if (minElement > workArray[x][y]) {
		return 0;
	}
	if ((minElement == workArray[x + 1][y]) && (workArray[x + 1][y] < currentElement) && (x + 1 <= labyrinth.countLines))
	{
		x++;
		return 1;
	}
	if ((minElement == workArray[x - 1][y]) && (workArray[x - 1][y] < currentElement) && (x - 1 >= 0))
	{
		x--;
		return 1;
	}
	if ((y + 1 <= labyrinth.countColumns) && (minElement == workArray[x][y + 1]) && (workArray[x][y + 1] < currentElement))
	{
		y++;
		return 1;
	}
	y--;
	return 1;
}

void WorkingWithCell(int &currentLabyrinthElement, int &isOver,
	int const &minBorder, int const &maxBorder, int const &nextValue) 
{
	if ((currentLabyrinthElement == FREE_WAY) && (minBorder < maxBorder))
	{
		currentLabyrinthElement = nextValue;
		isOver = 1;
	}
}

int WavePropagation(int const &number, std::vector<std::vector<int> > &waveArray,
	SLabyrinth const &labyrinth)
{                             
	int isOver = 0;
	for (int i = 0; i < labyrinth.countColumns; i++) 
	{    
		for (int j = 0; j < labyrinth.countLines; j++)    
		{
			if (waveArray[j][i] == number) 
			{
				WorkingWithCell(waveArray[j + 1][i], isOver, j + 1, labyrinth.countLines, number + 1);
				WorkingWithCell(waveArray[j - 1][i], isOver, -1, j - 1, number + 1);
				WorkingWithCell(waveArray[j][i + 1], isOver, i + 1, labyrinth.countColumns, number + 1);
				WorkingWithCell(waveArray[j][i - 1], isOver, -1, i - 1, number + 1);
			}
		}
	}
	return isOver;
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

int FindingWay(SLabyrinth &labyrinth)
{
	std::vector<std::vector<int> > waveArray(labyrinth.countLines, std::vector<int>(labyrinth.countColumns));
	if (CopyArrayFromCharToIntIsSuccesfully(waveArray, labyrinth))
	{
		int number = 1;
		while (WavePropagation(number, waveArray, labyrinth))
		{
			number++;
		}
		bool finalPointMet = false;
		std::vector<std::vector<char> > outputLabyrinthArray = labyrinth.inputLabyrinthArray;
		while (StepWayToTop(labyrinth, waveArray,
			outputLabyrinthArray, finalPointMet))
		{
		}
		if (finalPointMet) {
			labyrinth.inputLabyrinthArray = outputLabyrinthArray;
		}
		return 1;
	}
	return 0;
}

int OperationWithFilesAndLabyrinth(char *argv[]) 
{
	std::ifstream inputLabyrinthFile;
	std::ofstream outputLabyrinthFile;
	if (!FilesIsCorrect(inputLabyrinthFile, outputLabyrinthFile, argv[1], argv[2]))
	{
		return 1;
	}
	SLabyrinth labyrinth;
	FillingAnInputArrayOfData(inputLabyrinthFile, labyrinth);
	if (FindingWay(labyrinth)) {
		SaveLabyrinthOnFile(labyrinth, outputLabyrinthFile);
		return 0;
	}
	return 1;
}


