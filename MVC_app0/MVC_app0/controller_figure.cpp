#include "app_controller.h"
#include "frame.h"
#include <math.h>

void FigureEvent(Shape &figure, AppObjects &object, Vector2f const mousePos) {
	if (object.name == ACTION_FIGURE_STRING) {
		if (figure.getGlobalBounds().contains(mousePos) &&
			(object.mouseClicked && GetIntersects(mousePos, figure.getGlobalBounds()))) {
			figure.setPosition(mousePos);
			object.isSelect = true;
		}
		else {
			object.isSelect = false;
		}
	}
}


void TriangleFigure::ProcessEvent(Vector2f const mousePos) {
	FigureEvent(figure, *this, mousePos);
}
void CircleFigure::ProcessEvent(Vector2f const mousePos) {
	FigureEvent(figure, *this, mousePos);
}
void RectangleFigure::ProcessEvent(Vector2f const mousePos) {
	FigureEvent(figure, *this, mousePos);
}

float GetDistance(Vector2f mousePos, Vector2f subjectPos) {
	return sqrt((subjectPos.x - mousePos.x)*(subjectPos.x - mousePos.x) -
		(subjectPos.y - mousePos.y) * (subjectPos.y - mousePos.y));
}

void Frame::ProcessEvent(Vector2f const mousePos) {
	if ((mouseClicked) && ((topLeftPoint.getGlobalBounds().contains(mousePos)) ||
			(topRightPoint.getGlobalBounds().contains(mousePos)) ||
			(botRightPoint.getGlobalBounds().contains(mousePos)) ||
			(botLeftPoint.getGlobalBounds().contains(mousePos)))) {
		size = { frameRect.getGlobalBounds().width, frameRect.getGlobalBounds().height };
		frameRect.setSize(size);
		SetFrameOrigin(mousePos);
		frameRect.setPosition(mousePos + temp);
		SetPointsPosition();
		appObj->ResetFrame(size, { frameRect.getGlobalBounds().left, frameRect.getGlobalBounds().top});
	}
}