#pragma once
#include <boost/noncopyable.hpp>
#include <map>
#include <functional>
#include "ShapesContainer.h"
#include <fstream>
#include <iostream>
#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>

struct OptionalVector2f
{
	explicit operator bool()const
	{
		return x && y;
	}

	Vector2f get()const
	{
		return Vector2f(x.get(), y.get());
	}

	boost::optional<float> x;
	boost::optional<float> y;
};

std::istringstream &operator >> (std::istringstream &strm, OptionalVector2f &vec);


class CShapesControl : boost::noncopyable
{
	typedef std::map<std::string, std::function<void(std::istringstream & args) >> ActionMap;
public:
	CShapesControl(CShapesContainer &shapesContainer, std::string &input, std::ostream &output);
	bool HandleCommand();
	void PrintSortedBySquareShapes()const;
	void PrintSortedByPerimeterShapes()const;
private:
	void PrintInfoAboutShapes(LogicShapesPtrs const &arr)const;

	void ParsePointArgs(std::istringstream &strm);
	void ParseLineSegmentArgs(std::istringstream &strm);
	void ParseCircleArgs(std::istringstream &strm);
	void ParseRectangleArgs(std::istringstream &strm);
	void ParseTriangleArgs(std::istringstream &strm);
private:
	std::string &m_input;
	std::ostream &m_output;

	CShapesContainer &m_shapesContainer;
	const ActionMap m_actionMap;
};
