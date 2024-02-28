#pragma once
#include"Actions/Action.h"

class UndoAction : public Action
{
private:

public:
	UndoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readParams = true);
	
};
