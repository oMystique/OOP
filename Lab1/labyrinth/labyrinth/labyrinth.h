#pragma once
#include "application.h"

static const int MAX_LABYRINTH_SIZE = 100;
static const int FINAL_POINT = 1;
static const int WALL = 255;
static const int START_POINT = 253;
static const int FREE_WAY = 254;

int OperationWithFilesAndLabyrinth(char *argv[]);

struct SLabyrinth 
{
public:
	SLabyrinth();
	std::vector<std::vector<char> > inputLabyrinthArray;
	int finalCoordinateX;
	int finalCoordinateY;
	int countLines;
	int countColumns;
};