#pragma once
#include"Actions/Action.h"

class RedoAction : public Action
{
private:

public:
	RedoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readParams = false);
};