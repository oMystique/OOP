// GeometricShapes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ShapesControl.h"
#include "Rectangle.h"
#include "ShapeViewer.h"

using namespace std;

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

void DialogWithUser(CShapesControl &shapesControl, string &inputStr)
{
	cout << "Input file name or write \"None\" to continue..." << endl;
	cin >> inputStr;

	if (inputStr == "None")
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
	else
	{
		WorkWithFile(shapesControl, inputStr, move(inputStr));
	}
}

void PrintInfoAboutShapes(CShapesControl const &shapesControl)
{
	cout << "=== Squares ===" << endl;
	shapesControl.PrintSortedBySquareShapes();
	cout << "===============" << endl << endl;

	cout << "=== Perimeters ===" << endl;
	shapesControl.PrintSortedByPerimeterShapes();
	cout << "==================" << endl;
}

void DrawShapes(CShapesContainer const &shapesContainer)
{
	CShapeViewer shapeViewer;
	shapeViewer.Exec(shapesContainer.GetViewShapes());
}

int main(int argc, char *argv[])
{
	string inputStr;

	CShapesContainer shapesContainer;
	CShapesControl shapesControl(shapesContainer, inputStr, cout);

	if (argc < 2)
	{
		DialogWithUser(shapesControl, inputStr);
	}
	else
	{
		WorkWithFile(shapesControl, inputStr, argv[1]);
	}

	PrintInfoAboutShapes(shapesControl);

	if (argc < 2)
	{
		DrawShapes(shapesContainer);
	}

    return 0;
}

