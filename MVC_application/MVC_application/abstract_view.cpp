#include "abstract_view.h"
#include "controllers.h"

CAbstractView::CAbstractView(CDomainModel *domainModel) {
	CFigureController *controller = new CFigureController(domainModel);
	AddFigureObserver(controller);
};

CAbstractView::~CAbstractView() {
	delete view;
}

void CAbstractView::Update(CFigureObservable *observable, Vector2f const size, Vector2f const pos, unsigned int const index) {
	FloatRect rect = view->UpdateFigure(size, pos, index);
	NotifyUpdate({ rect.width, rect.height }, { rect.left, rect.top }, index);
}