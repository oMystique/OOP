#pragma once
#include "domain_model.h"

class CView;
class CModel : public Observer, Observable {
public:
	CModel();
	void Update(Observable *observable, String const command);
private:
	void Run();
private:
	String m_state;
	bool m_isNotExit;
};