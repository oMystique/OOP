#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

using namespace std;
using namespace sf;

//VECTOR_CONSTS:
static const Vector2i DEFAULT_WINDOW_SIZE = { 640, 580 };
static const Vector2f MAIN_FORM_SIZE = { 630.f, 473.5f };
static const Vector2f MAIN_FORM_DEFAULT_POS = { 5.f, 100.f };
static const Vector2f CENTER_FORM_SIZE = { 636.f, 72.f };
static const Vector2f CENTER_FORM_DEFAULT_POS = { 2.5f, 25.f };
static const Vector2f BORDER_FORM_SIZE = { 636.f, 20.f };
static const Vector2f BORDER_FORM_DEFAULT_POS = { 2.5f, 2.5f };
static const Vector2f MENU_BUTTON_SIZE = { 40, 20 };
static const Vector2f FIGURE_BUTTON_RECT = { 70, 66 };
static const Vector2f ACT_FIGURE_RECT = { FIGURE_BUTTON_RECT.x * 3.f, FIGURE_BUTTON_RECT.y * 3.f };
static const Vector2f RECTANGLE_SIZE_CORRECTION = { 0.7f, 0.4f };

//FLOAT_CONSTS:
static const float RECTANGLE_BUTTON_POS_CORRECTION = 2.5f;
static const float TEXT_SCALE = 0.47f;
static const float FRAME_POINT_RADIUS = 6.f;
static const float GET_HALF = 2.f;
static const float CIRCLE_RADIUS_CORRECTION = 3.5f;
static const float TRIANGLE_SIZE_CORRECTION = 4.2f;

//STRING_CONSTS:
static const String APPLICATION_TITLE = "Application";
static const String TRIANGLE_BUTTON_STRING = "  Triangle";
static const String CIRCLE_BUTTON_STRING = "    Circle";
static const String RECTANGLE_BUTTON_STRING = " Rectangle";
static const String MENU_BUTTON_STRING = "Menu";
static const String TEXT_FONT_PATH = "font.ttf";
static const String NONE_TYPE_STRING = "";
static const String ACTION_FIGURE_STRING = "actFigure";

//COLOR_CONSTS:
static const Color DEFAULT_FORM_COLOR = Color(245, 245, 245, 255);
static const Color SELECT_BUTTON_COLOR = Color(225, 225, 225, 255);
static const Color DEFAULT_FRAME_COLOR = Color(255, 255, 255, 0);
static const Color DEFAULT_FRAME_OUTLINE_COLOR = Color(0, 0, 0, 255);
static const Color DEFAULT_OUTLINE_COLOR = Color(220, 220, 220, 255);

enum CommandType 
{
	CreateShape,
	DeleteShape,
	ExitProgram,
	None
};