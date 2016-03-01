#pragma once
#include "resources.h"

class CCommandObservable;
class ICommandObserver {
public:
	virtual ~ICommandObserver() = default;
	virtual void Update(CCommandObservable *observable, CommandType command) = 0;
};