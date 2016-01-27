#pragma once
#include "frame.h"
#include "UndoRedo.h"

class AppModel {
public:
	AppModel();
	~AppModel();
private:
	void Run();
	void CreateBaseObjects();
	void CreateBackGround();
	void CreateBaseButtons();
	void GetEvent();
	void CreateNewFigure(AppObjects &object);
	void SetObjectEvent(AppObjects &object);
	int ActSelectObject(vector<AppObjects*>::iterator &it, AppObjects *&selectObject);
	void InitUndoRedo();
	void AppStateEvent(int const countElements);
private:
	unique_ptr<RenderWindow> window;
	vector<AppObjects*> objects;
	ContextSettings settings;
	vector<AppObjects*>::iterator it;
	Frame *frame = nullptr;
	UndoRedo *appState = nullptr;
	bool mouseClicked;
	bool isObjectSelect;
	bool isObjectDelete;
};


void AppointObservers(vector<AppObjects*> &objects, RenderWindow &window);
void AppointSpecificObserver(AppObjects *object);