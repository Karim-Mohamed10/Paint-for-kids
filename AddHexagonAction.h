#pragma once
#include "Actions/Action.h"
#include "CHexagon.h"
class AddHexagonAction : public Action
{
private:
	Point p1;
	GfxInfo HexaGfxInfo;
	CHexagon* H;
public:
	AddHexagonAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readParams = true);
	virtual void ActionUndo();

};

