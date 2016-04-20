#include "stdafx.h"
#include "ShapesControl.h"
#include <sstream> 
#include <boost/algorithm/string.hpp>

using namespace std;

struct SquareSorter : public binary_function<shared_ptr<IShape>, shared_ptr<IShape>, bool>
{
	bool const operator () (shared_ptr<IShape> const &shape1, shared_ptr<IShape> const &shape2)
	{
		return shape1->GetShapesSquare() < shape2->GetShapesSquare();
	}
};

struct PerimeterSorter : public binary_function<shared_ptr<IShape>, shared_ptr<IShape>, bool>
{
	bool const operator () (shared_ptr<IShape> const &shape1, shared_ptr<IShape> const &shape2)
	{
		return shape1->GetShapesPerimeter() > shape2->GetShapesPerimeter();
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

void CShapesControl::PrintInfoAboutShapes(LogicShapesPtrs const &arr)const
{
	for (auto it: arr)
	{
		cout << it->GetShapesPresentation() << endl;
	}
}

void CShapesControl::PrintSortedByPerimeterShapes()const
{
	auto copyArray = m_shapesContainer.GetShapes();
	sort(copyArray.begin(), copyArray.end(), PerimeterSorter());

	PrintInfoAboutShapes(copyArray);
}

void CShapesControl::PrintSortedBySquareShapes()const
{
	auto copyArray = m_shapesContainer.GetShapes();
	sort(copyArray.begin(), copyArray.end(), SquareSorter());

	PrintInfoAboutShapes(copyArray);
}

void CShapesControl::ParsePointArgs(istringstream &strm)
{
	OptionalVector2f pos;
	strm >> pos.x;
	strm >> pos.y;

	if (pos.is_initialized())
	{
		m_shapesContainer.PushPoint(pos.get());
	}
}

void CShapesControl::ParseLineSegmentArgs(istringstream &strm)
{
	OptionalVector2f firstPointPos;
	strm >> firstPointPos.x;
	strm >> firstPointPos.y;

	OptionalVector2f secondPointPos;
	strm >> secondPointPos.x;
	strm >> secondPointPos.y;

	boost::optional<string> lineColor;
	strm >> lineColor;

	if (firstPointPos.is_initialized() && secondPointPos.is_initialized() && lineColor.is_initialized())
	{
		m_shapesContainer.PushLineSegment(firstPointPos.get(), secondPointPos.get(), GetColorInDecimalForm(lineColor.get()));
	}
}

void CShapesControl::ParseCircleArgs(istringstream &strm)
{
	OptionalVector2f pos;
	strm >> pos.x;
	strm >> pos.y;

	boost::optional<float> radius;
	strm >> radius;

	boost::optional<string> lineColor;
	strm >> lineColor;

	boost::optional<string> fillColor;
	strm >> fillColor;

	if (pos.is_initialized() && radius.is_initialized()
		&& lineColor.is_initialized() && fillColor.is_initialized())
	{
		m_shapesContainer.PushCircle(pos.get(), radius.get(),
			GetColorInDecimalForm(lineColor.get()), GetColorInDecimalForm(fillColor.get()));
	}
}

void CShapesControl::ParseRectangleArgs(istringstream &strm)
{
	OptionalVector2f leftPointPos;
	strm >> leftPointPos.x;
	strm >> leftPointPos.y;

	OptionalVector2f rectProportion;
	strm >> rectProportion.x;
	strm >> rectProportion.y;

	boost::optional<string> lineColor;
	strm >> lineColor;

	boost::optional<string> fillColor;
	strm >> fillColor;

	if (leftPointPos.is_initialized() && rectProportion.is_initialized()
		&& lineColor.is_initialized() && fillColor.is_initialized())
	{
		m_shapesContainer.PushRectangle(leftPointPos.get(), rectProportion.get(),
			GetColorInDecimalForm(lineColor.get()), GetColorInDecimalForm(fillColor.get()));
	}

}

void CShapesControl::ParseTriangleArgs(istringstream &strm)
{
	OptionalVector2f topVertexPos;
	strm >> topVertexPos.x;
	strm >> topVertexPos.y;

	OptionalVector2f leftVertexPos;
	strm >> leftVertexPos.x;
	strm >> leftVertexPos.y;

	OptionalVector2f rightVertexPos;
	strm >> rightVertexPos.x;
	strm >> rightVertexPos.y;

	boost::optional<string> lineColor;
	strm >> lineColor;

	boost::optional<string> fillColor;
	strm >> fillColor;

	if (topVertexPos.is_initialized() && leftVertexPos.is_initialized() && rightVertexPos.is_initialized() && lineColor.is_initialized() && fillColor.is_initialized())
	{
		m_shapesContainer.PushTriangle(topVertexPos.get(), leftVertexPos.get(), rightVertexPos.get()
			, GetColorInDecimalForm(lineColor.get()), GetColorInDecimalForm(fillColor.get()));
	}

}


