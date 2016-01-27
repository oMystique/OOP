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

Vector2f RectangleFigure::GetSize() {
	return { figure.getGlobalBounds().width, figure.getGlobalBounds().height };
}

Vector2f RectangleFigure::GetPos() {
	return { figure.getGlobalBounds().left, figure.getGlobalBounds().top };
}

void RectangleFigure::ResetFrame(Vector2f const tSize, Vector2f const tPos) {
	size = tSize;
	pos = { tPos.x + figure.getGlobalBounds().width / 1.75f, tPos.y + figure.getGlobalBounds().height / 1.15f }; //TODO: REF
	figure.setSize(Vector2f(size.x * 0.9f, size.y * 0.6f)); //TODO: REF
	figure.setOrigin(figure.getGlobalBounds().width / GET_HALF, figure.getGlobalBounds().height / GET_HALF);
	SetFigurePosition();
}

