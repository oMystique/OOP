#include "triangle.h"

TriangleFigure::TriangleFigure(Vector2f const size,
	Vector2f const pos,
	String const name) :
	AppObjects(size, pos, name) {
	CreateFigure();
}

void TriangleFigure::CreateFigure() {
	figure.setPointCount(3);
	figure.setPoint(0, sf::Vector2f(size.x / 4.2f, 0)); //TODO: REF
	figure.setPoint(1, sf::Vector2f(0, size.y / GET_HALF));
	figure.setPoint(2, sf::Vector2f(size.y / GET_HALF, size.y / GET_HALF));
	figure.setFillColor(Color::Blue);
	figure.setOutlineThickness(GET_HALF);
	figure.setOutlineColor(Color::Black);
	if (name == ACTION_FIGURE_STRING) {
		figure.setOrigin(figure.getGlobalBounds().width / GET_HALF,
						figure.getGlobalBounds().height / GET_HALF);
	}
	SetFigurePosition();
}

void TriangleFigure::SetFigurePosition() {
	figure.setPosition(pos.x, pos.y);
}

