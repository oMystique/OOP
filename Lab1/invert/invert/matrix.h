#pragma once
#include <iostream>
#include <fstream>

static const int MATRIX_SIZE = 3;

class CMatrix {
public:
	CMatrix(char *argv[]);
private:
	void CheckCorrectnessArgs();
	void FillingAnArrayOfData();
	void CalculateDeterminant();
	void CalculateMatrixMinors();
	void TransposeMatrix(float const matrixMinors[MATRIX_SIZE][MATRIX_SIZE]);
	void FinalCalculateAndPrintMatrix();
private:
	float m_matrix[MATRIX_SIZE][MATRIX_SIZE];
	float m_determinant;
	std::ifstream m_inputFile;
};


float FindAndCalculateConcreteMinor(int const &iPos, int const &jPos, float const matrix[MATRIX_SIZE][MATRIX_SIZE]);