#include "stdafx.h"
#include "ShapesControl.h"
#include <sstream> 
#include <boost/algorithm/string.hpp>

using namespace std;

struct SquareSorter : public binary_function<shared_ptr<IShape>, shared_ptr<IShape>, bool>
{
	bool const operator () (shared_ptr<IShape> shape1, shared_ptr<IShape> shape2)
	{
		return shape1->GetShapesPerimeter() <= shape2->GetShapesPerimeter();
	}
};

struct PerimeterSorter : public binary_function<shared_ptr<IShape>, shared_ptr<IShape>, bool>
{
	bool const operator () (shared_ptr<IShape> shape1, shared_ptr<IShape> shape2)
	{
		return shape1->GetShapesPerimeter() >= shape2->GetShapesPerimeter();
	}
};

bool IsNotAlphaSpace(char symbol)
{
	return (!isalpha(symbol) && !isspace(symbol) && !isalnum(symbol));
}

Color GetColorInDecimalForm(std::string const &color)
{
	Color rgbColor;
	std::istringstream strm(color);
	int dec;
	strm >> std::hex >> dec;

	rgbColor.RR = dec / 0x10000;
	rgbColor.GG = (dec / 0x100) % 0x100;
	rgbColor.BB = dec % 0x100;

	return rgbColor;
}

CShapesControl::CShapesControl(CShapesContainer &shapesContainer, string &input, ostream &output)
	: m_shapesContainer(shapesContainer)
	, m_input(input)
	, m_output(output)
	, m_actionMap
	({
		{"Point", bind(&CShapesControl::ParsePointArgs, this, placeholders::_1) },
		{"Line", bind(&CShapesControl::ParseLineSegmentArgs, this, placeholders::_1) },
		{"Circle", bind(&CShapesControl::ParseCircleArgs, this, placeholders::_1) },
		{"Rectangle", bind(&CShapesControl::ParseRectangleArgs, this, placeholders::_1) },
		{"Triangle", bind(&CShapesControl::ParseTriangleArgs, this, placeholders::_1) }
	})
{
}

bool CShapesControl::HandleCommand()
{
	replace_if(m_input.begin(), m_input.end(), IsNotAlphaSpace, ' ');
	istringstream strm(m_input);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it->second(strm);
		return true;
	}

	return false;
}

void CShapesControl::PrintSortedByPerimeterShapes()const
{
	auto copyArray = m_shapesContainer.GetShapes();
	sort(copyArray.begin(), copyArray.end(), PerimeterSorter());

	for (auto &it : copyArray)
	{
		cout << it->GetShapesPresentation() << endl;
	}
}

void CShapesControl::PrintSortedBySquareShapes()const
{
	auto copyArray = m_shapesContainer.GetShapes();
	sort(copyArray.begin(), copyArray.end(), SquareSorter());

	for (auto &it : copyArray)
	{
		cout << it->GetShapesPresentation() << endl;
	}
}

void CShapesControl::ParsePointArgs(istringstream &strm)
{
	Vector2f pos;
	strm >> pos.x;
	strm >> pos.y;
	string lineColor;
	strm >> lineColor;

	m_shapesContainer.PushPoint(pos, GetColorInDecimalForm(lineColor));
}

void CShapesControl::ParseLineSegmentArgs(istringstream &strm)
{
	Vector2f firstPointPos;
	strm >> firstPointPos.x;
	strm >> firstPointPos.y;

	Vector2f secondPointPos;
	strm >> secondPointPos.x;
	strm >> secondPointPos.y;

	string lineColor;
	strm >> lineColor;

	m_shapesContainer.PushLineSegment(firstPointPos, secondPointPos, GetColorInDecimalForm(lineColor));
}

void CShapesControl::ParseCircleArgs(istringstream &strm)
{
	Vector2f pos;
	strm >> pos.x;
	strm >> pos.y;

	float radius;
	strm >> radius;

	string lineColor;
	strm >> lineColor;

	string fillColor;
	strm >> fillColor;

	m_shapesContainer.PushCircle(pos, radius, GetColorInDecimalForm(lineColor), GetColorInDecimalForm(fillColor));
}

void CShapesControl::ParseRectangleArgs(istringstream &strm)
{
	Vector2f leftPointPos;
	strm >> leftPointPos.x;
	strm >> leftPointPos.y;

	Vector2f rectProportion;
	strm >> rectProportion.x;
	strm >> rectProportion.y;

	string lineColor;
	strm >> lineColor;

	string fillColor;
	strm >> fillColor;

	m_shapesContainer.PushRectangle(leftPointPos, rectProportion, GetColorInDecimalForm(lineColor), GetColorInDecimalForm(fillColor));

}

void CShapesControl::ParseTriangleArgs(istringstream &strm)
{
	Vector2f topVertexPos;
	strm >> topVertexPos.x;
	strm >> topVertexPos.y;

	Vector2f leftVertexPos;
	strm >> leftVertexPos.x;
	strm >> leftVertexPos.y;

	Vector2f rightVertexPos;
	strm >> rightVertexPos.x;
	strm >> rightVertexPos.y;

	string lineColor;
	strm >> lineColor;

	string fillColor;
	strm >> fillColor;

	m_shapesContainer.PushTriangle(topVertexPos, leftVertexPos, rightVertexPos
		, GetColorInDecimalForm(lineColor), GetColorInDecimalForm(fillColor));

}


