#include "app_controller.h"
#include "frame.h"

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


void Frame::ProcessEvent(Vector2f const mousePos) {
	//TODO: DEV PROCESS EVENTS FOR FRAME RECT;
}