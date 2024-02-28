#pragma once
#include "Actions/Action.h"
class To_DrawMode: public Action
{
public:
	To_DrawMode(ApplicationManager* pApp);
	virtual void ReadActionParameters() ;

	
	virtual void Execute(bool readPara = true);

};

