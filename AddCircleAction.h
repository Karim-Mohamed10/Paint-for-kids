#pragma once
#include "Actions/Action.h"
#include "CCircle.h"
class AddCircleAction:public Action
{
private:
	Point c1;
	Point c2;
	GfxInfo CircGfxInfo;
	CCircle* C;
public:
	AddCircleAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparams = true);
	virtual void ActionUndo();

};

