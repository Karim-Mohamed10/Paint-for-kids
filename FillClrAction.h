#pragma once
#include"Actions/Action.h"
class FillClrAction : public Action
{
private:
	Point p1;
	GfxInfo newgfx;
	ActionType coloract;
public:
	FillClrAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readPara = true);

};