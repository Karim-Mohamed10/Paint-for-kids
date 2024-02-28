#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

class DeleteAction : public Action
{
private:
	CFigure* toDelete;
public:
	DeleteAction(ApplicationManager* pApp);
	DeleteAction(ApplicationManager* pApp, CFigure* todel);

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() ;

	//Execute action (code depends on action type)
	virtual void Execute(bool readPara = true);

};