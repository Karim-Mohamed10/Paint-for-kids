#pragma once
#include "Actions/Action.h"
#include "StartRecAction.h"
class PlayRecAction : public Action
{
private:
	StartRecAction* recmgr;
public:
	PlayRecAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readPara = true);
};

