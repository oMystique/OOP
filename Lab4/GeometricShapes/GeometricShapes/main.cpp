// GeometricShapes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ShapesControl.h"
#include "Rectangle.h"
#include "ShapeViewer.h"

using namespace std;

void DialogWithUser(CShapesControl &shapesControl, string &inputStr)
{
	while ((!cin.eof()) && (!cin.fail()))
	{
		cout << ">: ";
		getline(cin, inputStr);

		if (!shapesControl.HandleCommand())
		{
			cout << "Unknown command: " << inputStr << endl;
		}
	}
}

void WorkWithFile(CShapesControl &shapesControl, string &inputStr, string const &fileName)
{
	ifstream inputFile(fileName);

	while (getline(inputFile, inputStr))
	{
		if (!shapesControl.HandleCommand())
		{
			cout << "Unknown command: " << inputStr << endl;
		}
	}
}

int main(int argc, char *argv[])
{
	string inputStr;

	CShapesContainer shapesContainer;
	CShapesControl shapesControl(shapesContainer, inputStr, cout);

	if (argc < 0)
	{
		DialogWithUser(shapesControl, inputStr);
	}
	else
	{
		WorkWithFile(shapesControl, inputStr, argv[1]);
	}

	cout << "=== Squares ===" << endl;
	shapesControl.PrintSortedBySquareShapes();
	cout << "===============" << endl << endl;

	cout << "=== Perimeters ===" << endl;
	shapesControl.PrintSortedByPerimeterShapes();
	cout << "==================" << endl;

	CShapeViewer shapeViewer;
	shapeViewer.Exec(shapesContainer.GetViewShapes());

    return 0;
}

