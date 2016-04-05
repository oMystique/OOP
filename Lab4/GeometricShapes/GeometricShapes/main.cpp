// GeometricShapes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Triangle.h"
#include <iostream>

using namespace std;

int main()
{
	CTriangle triangle({ 10, 0 }, { 0, 10 }, { 10, 10 }, "#ff0000", "#00ff00");
	cout << triangle.GetShapesSquare() << endl;
	cout << triangle.GetShapesPerimeter() << endl;
	cout << triangle.GetShapesName() << endl;
	cout << triangle.GetLineColor() << endl;
	cout << triangle.GetFillColor() << endl;
    return 0;
}

