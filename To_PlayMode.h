#pragma once
#include "Actions/Action.h"
class To_PlayMode: public Action
{
public:
	To_PlayMode(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	
	virtual void Execute(bool readPara = true);
};

