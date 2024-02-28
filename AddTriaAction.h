#pragma once
#include "Actions/Action.h"
#include "CTriangle.h"
class AddTriaAction : public Action
{
private:
	Point p1, p2, p3;
	GfxInfo TriaGfxInfo;
	CTriangle* T;
public:
	AddTriaAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readParams = true);
	virtual void ActionUndo();
};

