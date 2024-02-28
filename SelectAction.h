#pragma once
#include "Actions/Action.h"

class SelectAction : public Action
{
private:
	Point p1;
	GfxInfo SelectGfxInfo;
public:
	SelectAction(ApplicationManager* pApp);

	//read the parameters of the selected figure
	virtual void ReadActionParameters();

	//select objects
	virtual void Execute(bool readPara = true);

};

