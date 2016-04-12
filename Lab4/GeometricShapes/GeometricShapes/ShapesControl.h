#pragma once
#include <boost/noncopyable.hpp>
#include <map>
#include <functional>
#include "ShapesContainer.h"
#include <fstream>
#include <iostream>

//запилить класс ShapesContainer, хран€щий массив указателей на конкретные фигуры и имеющий методы PushLine, Triangle ...
//в классе визуализации конкретной фигуры наследовать IDrawable и хранить weak_ptr на конкретный экземпл€р фигуры

class CShapesControl : boost::noncopyable
{
public:
	CShapesControl(CShapesContainer &shapesContainer, std::string &input, std::ostream &output);
	bool HandleCommand();
	void PrintSortedBySquareShapes()const;
	void PrintSortedByPerimeterShapes()const;
private:
	void ParsePointArgs(std::istringstream &strm);
	void ParseLineSegmentArgs(std::istringstream &strm);
	void ParseCircleArgs(std::istringstream &strm);
	void ParseRectangleArgs(std::istringstream &strm);
	void ParseTriangleArgs(std::istringstream &strm);
private:
	typedef std::map<std::string, std::function<void(std::istringstream & args) >> ActionMap;

	std::string &m_input;
	std::ostream &m_output;

	CShapesContainer &m_shapesContainer;
	const ActionMap m_actionMap;
};
