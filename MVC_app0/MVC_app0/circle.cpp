#include "circle.h"

CircleFigure::CircleFigure(Vector2f const size,
	Vector2f const pos,
	String const name) :
	AppObjects(size, pos, name) {
	CreateFigure();
}

void CircleFigure::CreateFigure() {
	figure.setRadius(size.x / 3.5f); //TODO: REF
	figure.setFillColor(Color::Blue);
	figure.setOutlineThickness(GET_HALF);
	figure.setOutlineColor(Color::Black);
	if (name == ACTION_FIGURE_STRING) {
		figure.setOrigin(figure.getGlobalBounds().width / GET_HALF,
						figure.getGlobalBounds().height / GET_HALF);
	}
	SetFigurePosition();
}

void CircleFigure::SetFigurePosition() {
	figure.setPosition(pos.x, pos.y);
}
