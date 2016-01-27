#include "UndoRedo.h"
#include "app_model.h"

void UndoRedo::ProcessEvent(vector<AppObjects*> objects) {
	int number = distance(appStates.begin(), find(appStates.begin(), appStates.end(), currentObj));
	currentObj = objects;
	switch (state) {
		case appointState:
			if (isRedo) {
				appStates.clear();
				isRedo = false;
			}
			appStates.push_back(objects);
			break;
		case undo:
			if (number > 0) {
				currentObj = appStates[number - 1];
			}
			break;
		case redo:
			if (number < (appStates.size() - 1)) {
				currentObj = appStates[number + 1];
				isRedo = true;
			}
			break;
		case none:
			break;
	}
}


vector<AppObjects*> UndoRedo::GetAppState() {
	return currentObj;
}