#include "matrix.h"
#include <iomanip>

float FindAndCalculateConcreteMinor(int const &iPos, int const &jPos, std::vector<std::vector<float> > const &matrix) 
{
	float minor[4];
	int posMinor = 0;
	for (unsigned int i = 0; i < MATRIX_SIZE; i++)
	{
		for (unsigned int j = 0; j < MATRIX_SIZE; j++)
		{
			if (((i != iPos) && (j != jPos)) && (posMinor < 4))
			{
				minor[posMinor] = matrix[i][j];
				posMinor++;
			}
		}
	}
	return (float(pow((-1), (iPos + 1 + jPos + 1))) * (minor[0] * minor[3] - minor[2] * minor[1]));
}

float CalculateDeterminant(std::vector<std::vector<float> > const &matrix)
{
	return (matrix[0][0] * FindAndCalculateConcreteMinor(0, 0, matrix) +
		matrix[0][1] * FindAndCalculateConcreteMinor(0, 1, matrix) +
		matrix[0][2] * FindAndCalculateConcreteMinor(0, 2, matrix));
}

bool IsCorrectDeterminant(float const &determinant) 
{
	if (determinant == 0) 
	{
		std::cout << "*_Sorry, but the matrix determinant = 0" << std::endl;
		std::cout << "*_The inverse matrix does not exist." << std::endl;
		return false;
	}
	return true;
}


void CalculateMatrixMinors(std::vector<std::vector<float> > const &matrix,
				std::vector<std::vector<float> > &minorMatrix)
{
	for (unsigned int i = 0; i < MATRIX_SIZE; i++)
	{
		for (unsigned int j = 0; j < MATRIX_SIZE; j++)
		{
			minorMatrix[i][j] = FindAndCalculateConcreteMinor(i, j, matrix);
		}
	}
}

void TransposeMatrix(std::vector<std::vector<float> > &matrix,
					std::vector<std::vector<float> > const &minorMatrix)
{
	for (unsigned int i = 0; i < MATRIX_SIZE; i++) 
	{
		for (unsigned int j = 0; j < MATRIX_SIZE; j++)
		{
			matrix[i][j] = minorMatrix[j][i];
		}
	}
}

void FinalCalculateAndPrintMatrix(std::vector<std::vector<float> > &matrix, float const &determinant)
{
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	for (unsigned int i = 0; i < MATRIX_SIZE; i++)
	{
		for (unsigned int j = 0; j < MATRIX_SIZE; j++) 
		{
			std::cout << std::setprecision(3) << matrix[i][j] / determinant << " ";
		}
		std::cout << std::endl;
	}
}

void InvertMatrix(std::vector<std::vector<float> > &matrix)
{
	float determinant;
	std::vector<std::vector<float> > minorMatrix(MATRIX_SIZE, std::vector<float>(MATRIX_SIZE));
	determinant = CalculateDeterminant(matrix);
	if (!IsCorrectDeterminant(determinant)) 
	{
		return;
	}
	CalculateMatrixMinors(matrix, minorMatrix);
	TransposeMatrix(matrix, minorMatrix);
	FinalCalculateAndPrintMatrix(matrix, determinant);
}