#include "app_view.h"
#include "frame.h"

AppView::AppView(AppObjects *cObject) : object(cObject) {
};

void AppView::Update(Observable *observable, RenderWindow &window) {
	DrawElements(observable, window);
}

void ApplicationButton::Draw(RenderWindow &window) {
	window.draw(formRect);
	window.draw(text);
}

void ApplicationForm::Draw(RenderWindow &window) {
	window.draw(formRect);
}

void AppView::DrawElements(Observable *observable, RenderWindow &window) {
	object->Draw(window);
}

void Frame::Draw(RenderWindow &window) {
	window.draw(frameRect);
	window.draw(topLeftPoint);
	window.draw(topRightPoint);
	window.draw(botLeftPoint);
	window.draw(botRightPoint);
}

void TriangleFigure::Draw(RenderWindow &window) {
	window.draw(figure);
}

void RectangleFigure::Draw(RenderWindow &window) {
	window.draw(figure);
}

void CircleFigure::Draw(RenderWindow &window) {
	window.draw(figure);
}