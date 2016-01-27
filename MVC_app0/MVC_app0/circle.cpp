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

void CircleFigure::ResetFrame(Vector2f const tSize, Vector2f const tPos) {
	size = tSize;
	pos = { tPos.x + figure.getGlobalBounds().width / 1.8f, tPos.y + figure.getGlobalBounds().height / 1.8f }; //TODO: REF
	figure.setRadius(size.x / 2.2f); //TODO: REF;
	figure.setOrigin(figure.getGlobalBounds().width / GET_HALF, figure.getGlobalBounds().height / GET_HALF);
	SetFigurePosition();
}

Vector2f CircleFigure::GetSize() {
	return { figure.getGlobalBounds().width, figure.getGlobalBounds().height };
}

Vector2f CircleFigure::GetPos() {
	return { figure.getGlobalBounds().left, figure.getGlobalBounds().top };
}