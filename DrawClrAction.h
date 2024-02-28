#pragma once
#include"Actions/Action.h"
class DrawClrAction :public Action
{
private:
	Point p1;
	ActionType coloract;
public:
	DrawClrAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readPara = true);
};