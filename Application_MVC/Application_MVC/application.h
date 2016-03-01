#pragma once
#include "controller.h"

class CApplication
{
public:
	CApplication();
private:
	void SetObservers();
	void Run();
private:
	shared_ptr<CModel> m_model;
	shared_ptr<CView> m_view;
	shared_ptr<CController> m_controller;
};