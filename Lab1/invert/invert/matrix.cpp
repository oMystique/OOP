#include "matrix.h"
#include <iomanip>

CMatrix::CMatrix(char *argv[]) :
		m_inputFile(argv[1], std::ifstream::in) {
	CheckCorrectnessArgs();
}

void CMatrix::CheckCorrectnessArgs() {
	if (!m_inputFile) {
		std::cout << "ERROR: Don't opening input or output file." << std::endl;
	}
	else {
		FillingAnArrayOfData();
	}
	
}

void CMatrix::FillingAnArrayOfData() {
	for (unsigned int i = 0; i < MATRIX_SIZE; i++) {
		for (unsigned int j = 0; j < MATRIX_SIZE; j++) {
			m_inputFile >> m_matrix[i][j];
		}
	}
	if (m_matrix) {
		CalculateDeterminant();
	}
	m_inputFile.close();
}

void CMatrix::CalculateDeterminant() {
	//Triangle rule;
	m_determinant = (m_matrix[0][0] * m_matrix[1][1] * m_matrix[2][2]) +
		(m_matrix[1][0] * m_matrix[2][1] * m_matrix[0][2]) +
		(m_matrix[0][1] * m_matrix[1][2] * m_matrix[2][0]) -
		(m_matrix[0][2] * m_matrix[1][1] * m_matrix[2][0]) -
		(m_matrix[0][0] * m_matrix[1][2] * m_matrix[2][1]) -
		(m_matrix[1][0] * m_matrix[0][1] * m_matrix[2][2]);
	if (m_determinant != 0) {
		CalculateMatrixMinors();
	}
	else {
		std::cout << "*_Sorry, but the matrix determinant = 0" << std::endl;
		std::cout << "*_The inverse matrix does not exist." << std::endl;
	}
}

float FindAndCalculateConcreteMinor(int const &iPos, int const &jPos, float const matrix[MATRIX_SIZE][MATRIX_SIZE]) {
	float minor[4];
	int posMinor = 0;
	for (unsigned int i = 0; i < MATRIX_SIZE; i++) {
		for (unsigned int j = 0; j < MATRIX_SIZE; j++) {
			if (((i != iPos) && (j != jPos)) && (posMinor < 4)) {
				minor[posMinor] = matrix[i][j];
				posMinor++;
			}
		}
	}
	return (float(pow((-1), (iPos + jPos))) * (minor[0] * minor[3] - minor[2] * minor[1]));
}

void CMatrix::CalculateMatrixMinors() {
	float matrixMinors[MATRIX_SIZE][MATRIX_SIZE];
	for (unsigned int i = 0; i < MATRIX_SIZE; i++) {
		for (unsigned int j = 0; j < MATRIX_SIZE; j++) {
			matrixMinors[i][j] = FindAndCalculateConcreteMinor(i, j, m_matrix);
		}
	}
	TransposeMatrix(matrixMinors);
}

void CMatrix::TransposeMatrix(float const matrixMinors[MATRIX_SIZE][MATRIX_SIZE]) {
	for (unsigned int i = 0; i < MATRIX_SIZE; i++) {
		for (unsigned int j = 0; j < MATRIX_SIZE; j++) {
			m_matrix[i][j] = matrixMinors[j][i];
		}
	}
	FinalCalculateAndPrintMatrix();
}

void CMatrix::FinalCalculateAndPrintMatrix() {
	 std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	for (unsigned int i = 0; i < MATRIX_SIZE; i++) {
		for (unsigned int j = 0; j < MATRIX_SIZE; j++) {
			std::cout << std::setprecision(3) << m_matrix[i][j] / m_determinant << " ";
		}
		std::cout << std::endl;
	}
}