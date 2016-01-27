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

void DeleteObject(vector<AppObjects*> &objects, vector<AppObjects*>::iterator &it, UndoRedo &appState, Frame &frame) {
	appState.state = appState.appointState;
	appState.ProcessEvent(objects);
	it = objects.erase(it);
	frame.ResetFrame({ 0,0 }, { -10, -10 });
}

AppModel::~AppModel() {
	for (it = objects.begin(); it != objects.end();) {
		(*it)->RemoveObservers();
		AppObjects *b = *it;
		it = objects.erase(it);
		delete b;
	}
	objects.clear();
	delete frame;
	delete appState;
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
	frame->mouseClicked = mouseClicked;
	if (((*it)->isSelect) && ((*it)->name == ACTION_FIGURE_STRING)) {
		mouseClicked = false;
		isObjectSelect = true;
		selectObject = *it;
		frame->ResetFrame((*it)->GetSize(), (*it)->GetPos());
		frame->SetEditObject(*it);
	}
	else if (((*it)->isSelect) && 
			!((*it)->name == ACTION_FIGURE_STRING) &&
			(!((*it)->name == MENU_BUTTON_STRING))) {
		CreateNewFigure(**it);
		return 1;
	}
	if ((isObjectDelete) && (*it == selectObject)) {
		DeleteObject(objects, it, *appState, *frame);
		return 1;
	}
	return 0;
}


void AppModel::AppStateEvent(int const countElements) {
	if (objects.size() != countElements) {
		appState->state = appState->appointState;
	}
	appState->ProcessEvent(objects);
	objects = appState->GetAppState();
}

void AppModel::Run() {
	AppObjects *selectObject = nullptr;
	frame = new Frame({ 0,0 }, { -10, -10 }, "frame");
	AppointSpecificObserver(frame);
	InitUndoRedo();
	int countElements = objects.size();
	while (window->isOpen()) {
		appState->state = appState->none;
		GetEvent();
		countElements = objects.size();
		window->clear(DEFAULT_FORM_COLOR);
		for (it = objects.begin(); it != objects.end(); it++) {
			SetObjectEvent(**it);
			(*it)->NotifyUpdate(*window);
			if (ActSelectObject(it, selectObject) == 1) {
				break;
			}
		}
		frame->NotifyUpdate(*window);
		window->display();
		AppStateEvent(countElements);
	}
}