#include "figures_graphic.h"

CShapeGraphic::CShapeGraphic() : 
	isDeleted(false)
{
};

bool GetIntersects(Vector2f const &mousePos, FloatRect const &rect)
{
	return ((MAIN_FORM_DEFAULT_POS.y + rect.height / GET_HALF < mousePos.y) &&
		(mousePos.y < MAIN_FORM_SIZE.y + MAIN_FORM_DEFAULT_POS.y - rect.height / GET_HALF) &&
		(MAIN_FORM_DEFAULT_POS.x + rect.width / GET_HALF < mousePos.x) &&
		(mousePos.x < MAIN_FORM_SIZE.x + MAIN_FORM_DEFAULT_POS.x - rect.width / GET_HALF));
}