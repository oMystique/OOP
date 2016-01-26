#include "app_model.h"
#include "app_view.h"
#include "app_controller.h"


void AppointSpecificObserver(AppObjects *object) {
	AppView *view = new AppView(object);
	AppController *controller = new AppController(object);
	object->AddObserver(view);
	object->AddObserver(controller);
}

void AppointObservers(vector<AppObjects*> &objects, RenderWindow &window) {
	for (auto object : objects) {
		AppointSpecificObserver(object);
	}
}

void AppModel::CreateBackGround() {
	objects.push_back(new ApplicationForm(MAIN_FORM_SIZE,
		MAIN_FORM_DEFAULT_POS, NONE_TYPE_STRING));
	objects.push_back(new ApplicationForm(CENTER_FORM_SIZE,
		CENTER_FORM_DEFAULT_POS, NONE_TYPE_STRING));
	objects.push_back(new ApplicationForm(BORDER_FORM_SIZE,
		BORDER_FORM_DEFAULT_POS, NONE_TYPE_STRING));
	objects.push_back(new ApplicationButton(MENU_BUTTON_SIZE,
		BORDER_FORM_DEFAULT_POS,
		MENU_BUTTON_STRING));
}

void AppModel::CreateBaseButtons() {
	//CREATE TRIANGLE BUTTON;
	objects.push_back(new ApplicationButton(FIGURE_BUTTON_RECT,
		Vector2f(CENTER_FORM_DEFAULT_POS.x,
			CENTER_FORM_DEFAULT_POS.y + RECTANGLE_BUTTON_POS_CORRECTION),
		TRIANGLE_BUTTON_STRING));
	objects.push_back(new TriangleFigure(FIGURE_BUTTON_RECT,
		Vector2f(CENTER_FORM_DEFAULT_POS.x + 18,
			CENTER_FORM_DEFAULT_POS.y + RECTANGLE_BUTTON_POS_CORRECTION + 25),
		TRIANGLE_BUTTON_STRING));
	//CREATE CIRCLE BUTTON;
	objects.push_back(new ApplicationButton(FIGURE_BUTTON_RECT,
		Vector2f(CENTER_FORM_DEFAULT_POS.x + FIGURE_BUTTON_RECT.x,
			CENTER_FORM_DEFAULT_POS.y + RECTANGLE_BUTTON_POS_CORRECTION),
		CIRCLE_BUTTON_STRING));
	objects.push_back(new CircleFigure(FIGURE_BUTTON_RECT,
		Vector2f(CENTER_FORM_DEFAULT_POS.x + FIGURE_BUTTON_RECT.x + 14,
			CENTER_FORM_DEFAULT_POS.y + RECTANGLE_BUTTON_POS_CORRECTION + 22),
		CIRCLE_BUTTON_STRING));
	//CREATE RECTANGLE BUTTON;
	objects.push_back(new ApplicationButton(FIGURE_BUTTON_RECT,
		Vector2f(CENTER_FORM_DEFAULT_POS.x + FIGURE_BUTTON_RECT.x * 2.f,
			CENTER_FORM_DEFAULT_POS.y + RECTANGLE_BUTTON_POS_CORRECTION),
		RECTANGLE_BUTTON_STRING));
	objects.push_back(new RectangleFigure(FIGURE_BUTTON_RECT,
		Vector2f(CENTER_FORM_DEFAULT_POS.x + FIGURE_BUTTON_RECT.x * GET_HALF + 11,
			CENTER_FORM_DEFAULT_POS.y + RECTANGLE_BUTTON_POS_CORRECTION + 25),
		RECTANGLE_BUTTON_STRING));
	AppointObservers(objects, *window);
	//;
}

void AppModel::CreateBaseObjects() {
	CreateBackGround();
	CreateBaseButtons();
}

void AppModel::CreateNewFigure(AppObjects &object) {
	if (object.name == TRIANGLE_BUTTON_STRING) {
		TriangleFigure *newObject = new TriangleFigure(ACT_FIGURE_RECT,
			window->getView().getCenter() - FIGURE_BUTTON_RECT,
			ACTION_FIGURE_STRING);
		AppointSpecificObserver(newObject);
		objects.push_back(newObject);
	}
	else if (object.name == CIRCLE_BUTTON_STRING) {
		CircleFigure *newObject = new CircleFigure(ACT_FIGURE_RECT,
			window->getView().getCenter() - FIGURE_BUTTON_RECT,
			ACTION_FIGURE_STRING);
		AppointSpecificObserver(newObject);
		objects.push_back(newObject);
	}
	else {
		RectangleFigure *newObject = new RectangleFigure(ACT_FIGURE_RECT,
			window->getView().getCenter() - FIGURE_BUTTON_RECT,
			ACTION_FIGURE_STRING);
		AppointSpecificObserver(newObject);
		objects.push_back(newObject);
	}
	object.isSelect = false;
}