#pragma once
#include "Actions/Action.h"
class StopRecAction : public Action
{
public:
	StopRecAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readPara = true);
};

