#include "controllers.h"
#include "model.h"


CBaseController::CBaseController(CModel *model) {
	AddObserver(model);
}

void CBaseController::Update(Observable *observable, String const command) {
	NotifyUpdate(command);
}

CFigureController::CFigureController(CDomainModel *domainModel) {
	AddFigureObserver(domainModel);
}

void CFigureController::Update(CFigureObservable *observable, Vector2f const size, Vector2f const pos, unsigned int const index) {
	NotifyUpdate(size, pos, index);
}