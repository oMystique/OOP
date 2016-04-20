// GeometricShapesTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../GeometricShapes/LineSegment.h"
#include "../GeometricShapes/Triangle.h"

//can create a point

struct PointFixture
{
	CPoint point;
	PointFixture()
		: point({ 15, 30 })
	{};
};	

BOOST_FIXTURE_TEST_SUITE(point_test, PointFixture)

	BOOST_AUTO_TEST_CASE(point_has_predetermined_position)
	{
		BOOST_CHECK_EQUAL(point.GetPointPosition().x, 15);
		BOOST_CHECK_EQUAL(point.GetPointPosition().y, 30);
	}

	BOOST_AUTO_TEST_CASE(a_point_is_black_by_default)
	{
		Color blackColor(0, 0, 0);
		BOOST_CHECK_EQUAL(point.GetLineColor().RR, blackColor.RR);
		BOOST_CHECK_EQUAL(point.GetLineColor().GG, blackColor.GG);
		BOOST_CHECK_EQUAL(point.GetLineColor().BB, blackColor.BB);
	}

	BOOST_AUTO_TEST_CASE(a_point_has_zero_area)
	{
		BOOST_CHECK_EQUAL(point.GetShapesSquare(), 0);
	}

	BOOST_AUTO_TEST_CASE(a_point_has_zero_perimeter)
	{
		BOOST_CHECK_EQUAL(point.GetShapesPerimeter(), 0);
	}

	BOOST_AUTO_TEST_CASE(point_has_a_string_representation)
	{
		auto str = "Point: Pos <15.00,30.00>; P = 0.00; S = 0.00";
		BOOST_CHECK_EQUAL(point.GetShapesPresentation(), str);
	}

BOOST_AUTO_TEST_SUITE_END()

//can create a line segment

struct LineFixture
{
	CLineSegment line;
	LineFixture()
		: line({ 10, 10 }, { 20, 20 }, Color(138, 138, 138))
	{};
};

BOOST_FIXTURE_TEST_SUITE(line_tests, LineFixture)

	BOOST_AUTO_TEST_CASE(first_point_of_line_has_predetermined_position)
	{
		BOOST_CHECK_EQUAL(line.GetPosOfFirstPoint().x, 10);
		BOOST_CHECK_EQUAL(line.GetPosOfFirstPoint().y, 10);
	}

	BOOST_AUTO_TEST_CASE(second_point_of_line_has_predetermined_position)
	{
		BOOST_CHECK_EQUAL(line.GetPosOfSecondPoint().x, 20);
		BOOST_CHECK_EQUAL(line.GetPosOfSecondPoint().y, 20);
	}

	BOOST_AUTO_TEST_CASE(line_has_color_set_in_the_constructor)
	{
		Color color(138, 138, 138);
		BOOST_CHECK_EQUAL(line.GetLineColor().RR, color.RR);
		BOOST_CHECK_EQUAL(line.GetLineColor().GG, color.GG);
		BOOST_CHECK_EQUAL(line.GetLineColor().BB, color.BB);
	}

	BOOST_AUTO_TEST_CASE(line_has_zero_area)
	{
		BOOST_CHECK_EQUAL(line.GetShapesSquare(), 0);
	}

	BOOST_AUTO_TEST_CASE(perimeter_is_equal_length_of_segment)
	{
		Vector2f firstPoint = line.GetPosOfFirstPoint();
		Vector2f secondPoint = line.GetPosOfSecondPoint();
		float length = sqrtf(pow((firstPoint.x - secondPoint.x), 2) + pow((firstPoint.y - secondPoint.y), 2));

		BOOST_CHECK_EQUAL(line.GetShapesPerimeter(), length);
	}

	BOOST_AUTO_TEST_CASE(line_has_string_representation)
	{
		auto str = "LineSegment: First point pos <10.00,10.00>, Second point pos <20.00,20.00>; P = 14.14; S = 0.00";
		BOOST_CHECK_EQUAL(line.GetShapesPresentation(), str);
	}

BOOST_AUTO_TEST_SUITE_END()

//can create a circle

struct CircleFixture
{
	CCircle circle;
	CircleFixture()
		: circle({ 20, 20 }, 10, Color(135, 135, 135), Color(204, 204, 204))
	{};
};

BOOST_FIXTURE_TEST_SUITE(circle_tests, CircleFixture)

	BOOST_AUTO_TEST_CASE(circle_has_a_position)
	{
		BOOST_CHECK_EQUAL(circle.GetPosition().x, 20);
		BOOST_CHECK_EQUAL(circle.GetPosition().y, 20);
	}

	BOOST_AUTO_TEST_CASE(circle_has_a_radius)
	{
		BOOST_CHECK_EQUAL(circle.GetRadius(), 10);
	}

	BOOST_AUTO_TEST_CASE(circle_has_a_line_color)
	{
		BOOST_CHECK_EQUAL(circle.GetLineColor().RR, 135);
		BOOST_CHECK_EQUAL(circle.GetLineColor().GG, 135);
		BOOST_CHECK_EQUAL(circle.GetLineColor().BB, 135);
	}

	BOOST_AUTO_TEST_CASE(circle_has_a_fill_color)
	{
		BOOST_CHECK_EQUAL(circle.GetFillColor().RR, 204);
		BOOST_CHECK_EQUAL(circle.GetFillColor().GG, 204);
		BOOST_CHECK_EQUAL(circle.GetFillColor().BB, 204);
	}

	BOOST_AUTO_TEST_CASE(can_find_area)
	{
		BOOST_CHECK_EQUAL(int(circle.GetShapesSquare()), 314);
	}

	BOOST_AUTO_TEST_CASE(can_find_perimeter)
	{
		BOOST_CHECK_EQUAL(int(circle.GetShapesPerimeter()), 62);
	}

BOOST_AUTO_TEST_SUITE_END()

//can create a rectangle

struct RectangleFixture
{
	CRectangle rect;
	RectangleFixture()
		: rect({ 60, 60 }, { 100, 30 }, Color(175, 125, 115), Color(214, 224, 234))
	{};
};


BOOST_FIXTURE_TEST_SUITE(rectangle_tests, RectangleFixture)

	BOOST_AUTO_TEST_CASE(rect_has_a_position)
	{
		BOOST_CHECK_EQUAL(rect.GetPosition().x, 60);
		BOOST_CHECK_EQUAL(rect.GetPosition().y, 60);
	}

	BOOST_AUTO_TEST_CASE(rect_has_a_proportion)
	{
		BOOST_CHECK_EQUAL(rect.GetProportion().x, 100);
		BOOST_CHECK_EQUAL(rect.GetProportion().y, 30);
	}

	BOOST_AUTO_TEST_CASE(rect_has_a_line_color)
	{
		BOOST_CHECK_EQUAL(rect.GetLineColor().RR, 175);
		BOOST_CHECK_EQUAL(rect.GetLineColor().GG, 125);
		BOOST_CHECK_EQUAL(rect.GetLineColor().BB, 115);
	}

	BOOST_AUTO_TEST_CASE(circle_has_a_fill_color)
	{
		BOOST_CHECK_EQUAL(rect.GetFillColor().RR, 214);
		BOOST_CHECK_EQUAL(rect.GetFillColor().GG, 224);
		BOOST_CHECK_EQUAL(rect.GetFillColor().BB, 234);
	}

	BOOST_AUTO_TEST_CASE(can_find_area)
	{
		BOOST_CHECK_EQUAL(int(rect.GetShapesSquare()), 3000);
	}

	BOOST_AUTO_TEST_CASE(can_find_perimeter)
	{
		BOOST_CHECK_EQUAL(int(rect.GetShapesPerimeter()), 260);
	}

BOOST_AUTO_TEST_SUITE_END()

//can create a triangle

struct TriangleFixture
{
	CTriangle triangle;
	TriangleFixture()
		: triangle({ 20, 0 }, { 0, 20 }, { 20, 20 }, Color(123, 125, 255), Color(12, 4, 234))
	{};
};


BOOST_FIXTURE_TEST_SUITE(triangle_tests, TriangleFixture)

	BOOST_AUTO_TEST_CASE(top_vertex_of_triangle_has_a_position)
	{
		BOOST_CHECK_EQUAL(triangle.GetTopVertexPos().x, 20);
		BOOST_CHECK_EQUAL(triangle.GetTopVertexPos().y, 0);
	}

	BOOST_AUTO_TEST_CASE(left_vertex_of_triangle_has_a_position)
	{
		BOOST_CHECK_EQUAL(triangle.GetLeftVertexPos().x, 0);
		BOOST_CHECK_EQUAL(triangle.GetLeftVertexPos().y, 20);
	}

	BOOST_AUTO_TEST_CASE(right_vertex_of_triangle_has_a_position)
	{
		BOOST_CHECK_EQUAL(triangle.GetRightVertexPos().x, 20);
		BOOST_CHECK_EQUAL(triangle.GetRightVertexPos().y, 20);
	}

	BOOST_AUTO_TEST_CASE(triangle_has_a_line_color)
	{
		BOOST_CHECK_EQUAL(triangle.GetLineColor().RR, 123);
		BOOST_CHECK_EQUAL(triangle.GetLineColor().GG, 125);
		BOOST_CHECK_EQUAL(triangle.GetLineColor().BB, 255);
	}

	BOOST_AUTO_TEST_CASE(triangle_has_a_fill_color)
	{
		BOOST_CHECK_EQUAL(triangle.GetFillColor().RR, 12);
		BOOST_CHECK_EQUAL(triangle.GetFillColor().GG, 4);
		BOOST_CHECK_EQUAL(triangle.GetFillColor().BB, 234);
	}

	BOOST_AUTO_TEST_CASE(can_find_area)
	{
		BOOST_CHECK_EQUAL(int(triangle.GetShapesSquare()), 200);
	}

	BOOST_AUTO_TEST_CASE(can_find_perimeter)
	{
		BOOST_CHECK_EQUAL(int(triangle.GetShapesPerimeter()), 68);
	}

BOOST_AUTO_TEST_SUITE_END()