#include "app_model.h"


AppModel::AppModel() {
	window = make_unique<RenderWindow>(VideoMode(DEFAULT_WINDOW_SIZE.x,
											DEFAULT_WINDOW_SIZE.y), 
											APPLICATION_TITLE);
	mouseClicked = false;
	isObjectDelete = false;
	isObjectSelect = false;
	settings.antialiasingLevel = 8;
	CreateBaseObjects();
	Run();
};

void DeleteObject(vector<AppObjects*> &objects, vector<AppObjects*>::iterator &it) {
	(*it)->RemoveObservers();
	AppObjects *b = *it;
	it = objects.erase(it);
	delete b;
}

AppModel::~AppModel() {
	for (it = objects.begin(); it != objects.end();) {
		DeleteObject(objects, it);
	}
	objects.clear();
}

void AppModel::SetObjectEvent(AppObjects &object) {
	if (isObjectSelect) {
		object.mouseClicked = object.isSelect;
	}
	else {
		object.mouseClicked = mouseClicked;
	}
}

int AppModel::ActSelectObject(vector<AppObjects*>::iterator &it, AppObjects *&selectObject) {
	if (((*it)->isSelect) && ((*it)->name == ACTION_FIGURE_STRING)) {
		mouseClicked = false;
		isObjectSelect = true;
		selectObject = *it;
	}
	else if (((*it)->isSelect) && 
			!((*it)->name == ACTION_FIGURE_STRING) &&
			(!((*it)->name == MENU_BUTTON_STRING))) {
		CreateNewFigure(**it);
		return 1;
	}
	if ((isObjectDelete) && (*it == selectObject)) {
		DeleteObject(objects, it);
		return 1;
	}
	return 0;
}

void AppModel::Run() {
	AppObjects *selectObject = nullptr;
	while (window->isOpen()) {
		GetEvent();
		window->clear(DEFAULT_FORM_COLOR);
		for (it = objects.begin(); it != objects.end(); it++) {
			SetObjectEvent(**it);
			(*it)->NotifyUpdate(*window);
			if (ActSelectObject(it, selectObject) == 1) {
				break;
			}
		}
		window->display();
	}
}