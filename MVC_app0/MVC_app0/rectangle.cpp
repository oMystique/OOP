#include "rectangle.h"

RectangleFigure::RectangleFigure(Vector2f const size,
	Vector2f const pos,
	String const name) :
	AppObjects(size, pos, name) {
	CreateFigure();
}

void RectangleFigure::CreateFigure() {
	figure.setSize(Vector2f(size.x * 0.7f, size.y * 0.4f)); //TODO: REF
	figure.setFillColor(Color::Blue);
	figure.setOutlineThickness(2);
	figure.setOutlineColor(Color::Black);
	if (name == ACTION_FIGURE_STRING) {
		figure.setOrigin(figure.getGlobalBounds().width / GET_HALF,
						figure.getGlobalBounds().height / GET_HALF);
	}
	SetFigurePosition();
}

void RectangleFigure::SetFigurePosition() {
	figure.setPosition(pos.x, pos.y);
}


