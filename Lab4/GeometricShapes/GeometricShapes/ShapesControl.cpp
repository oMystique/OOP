#include "stdafx.h"
#include "ShapesControl.h"
#include <sstream> 
#include <boost/algorithm/string.hpp>

using namespace std;

istringstream &operator >> (istringstream &strm, OptionalVector2f &vec)
{
	strm >> vec.x;
	strm >> vec.y;
	return strm;
}

bool IsNotAlphaSpace(char symbol)
{
	return (!isalpha(symbol) && !isspace(symbol) && !isalnum(symbol));
}

Color GetColorInDecimalForm(std::string const &color)
{
	istringstream strm(color);
	int dec;
	strm >> std::hex >> dec;

	Color rgbColor;
	rgbColor.r = dec / 0x10000;
	rgbColor.g = (dec / 0x100) % 0x100;
	rgbColor.b = dec % 0x100;

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

void CShapesControl::PrintInfoAboutShapes(LogicShapesPtrs const &arr)const
{
	for (auto it: arr)
	{
		cout << it->ToString() << endl;
	}
}

void CShapesControl::PrintSortedByPerimeterShapes()const
{
	auto copyArray = m_shapesContainer.GetShapes();
	sort(copyArray.begin(), copyArray.end(), [](shared_ptr<IShape> const &shape1, shared_ptr<IShape> const &shape2)
	{
		return shape1->GetShapesPerimeter() > shape2->GetShapesPerimeter();
	});

	PrintInfoAboutShapes(copyArray);
}

void CShapesControl::PrintSortedBySquareShapes()const
{
	auto copyArray = m_shapesContainer.GetShapes();
	sort(copyArray.begin(), copyArray.end(), [](shared_ptr<IShape> const &shape1, shared_ptr<IShape> const &shape2)
	{
		return shape1->GetShapesSquare() < shape2->GetShapesSquare();
	});

	PrintInfoAboutShapes(copyArray);
}

void CShapesControl::ParsePointArgs(istringstream &strm)
{
	OptionalVector2f pos;
	strm >> pos;

	if (pos)
	{
		m_shapesContainer.PushPoint(pos.get());
	}
}

void CShapesControl::ParseLineSegmentArgs(istringstream &strm)
{
	OptionalVector2f firstPointPos;
	strm >> firstPointPos;;

	OptionalVector2f secondPointPos;
	strm >> secondPointPos;

	boost::optional<string> lineColor;
	strm >> lineColor;

	if (firstPointPos && secondPointPos && lineColor)
	{
		m_shapesContainer.PushLineSegment(firstPointPos.get(), secondPointPos.get(), GetColorInDecimalForm(lineColor.get()));
	}
}

void CShapesControl::ParseCircleArgs(istringstream &strm)
{
	OptionalVector2f pos;
	strm >> pos;

	boost::optional<float> radius;
	strm >> radius;

	boost::optional<string> lineColor;
	strm >> lineColor;

	boost::optional<string> fillColor;
	strm >> fillColor;

	if (pos && radius && lineColor && fillColor)
	{
		m_shapesContainer.PushCircle(pos.get(), radius.get(),
			GetColorInDecimalForm(lineColor.get()), GetColorInDecimalForm(fillColor.get()));
	}
}

void CShapesControl::ParseRectangleArgs(istringstream &strm)
{
	OptionalVector2f leftPointPos;
	strm >> leftPointPos;

	OptionalVector2f rectProportions;
	strm >> rectProportions;

	boost::optional<string> lineColor;
	strm >> lineColor;

	boost::optional<string> fillColor;
	strm >> fillColor;

	if (leftPointPos && rectProportions && lineColor && fillColor)
	{
		m_shapesContainer.PushRectangle(leftPointPos.get(), rectProportions.get(),
			GetColorInDecimalForm(lineColor.get()), GetColorInDecimalForm(fillColor.get()));
	}

}

void CShapesControl::ParseTriangleArgs(istringstream &strm)
{
	OptionalVector2f topVertexPos;
	strm >> topVertexPos;

	OptionalVector2f leftVertexPos;
	strm >> leftVertexPos;

	OptionalVector2f rightVertexPos;
	strm >> rightVertexPos;

	boost::optional<string> lineColor;
	strm >> lineColor;

	boost::optional<string> fillColor;
	strm >> fillColor;

	if (topVertexPos && leftVertexPos && rightVertexPos && lineColor && fillColor)
	{
		m_shapesContainer.PushTriangle(topVertexPos.get(), leftVertexPos.get(), rightVertexPos.get()
			, GetColorInDecimalForm(lineColor.get()), GetColorInDecimalForm(fillColor.get()));
	}

}


