#pragma once
#include "Actions/Action.h"

class StartRecAction : public Action
{
public:
	Action *recordedactions[20];
	int count;
public:
	StartRecAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readPara = true);
	void recordaction(Action* act);
	Action** getreclist();
	int getcount();
};