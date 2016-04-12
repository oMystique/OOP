#pragma once
#include <boost/noncopyable.hpp>
#include <map>
#include <functional>
#include "ShapesContainer.h"
#include <fstream>
#include <iostream>

//�������� ����� ShapesContainer, �������� ������ ���������� �� ���������� ������ � ������� ������ PushLine, Triangle ...
//� ������ ������������ ���������� ������ ����������� IDrawable � ������� weak_ptr �� ���������� ��������� ������

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
