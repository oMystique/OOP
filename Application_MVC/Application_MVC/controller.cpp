#include "controller.h"

void CController::Update(CCommandObservable *observable, CommandType command)
{
	NotifyCommandUpdate(command);
}

void CController::Update(CShapeObservable *observable, Vector2f const &size,
				Vector2f const &pos, unsigned index)
{
	NotifyShapeUpdate(size, pos, index);
}