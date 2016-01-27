#pragma once
#include "resources.h"


class AppObjects;

class UndoRedo {
public:
	void ProcessEvent(vector<AppObjects*> objects);
	vector<AppObjects*> GetAppState();
	enum {
		undo,
		redo,
		appointState,
		none
	} state;
private:
	vector<AppObjects*> currentObj;
	vector<vector<AppObjects*>> appStates;
private:
	bool isRedo;
};