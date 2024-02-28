#pragma once
#include "Actions/Action.h"
class AddSaveAction : public Action
{
	string name;
	ofstream output;
	bool x;
public:
	AddSaveAction(ApplicationManager* pApp);

	string GetFigColor(color a);
	virtual void ReadActionParameters();
	


	virtual void Execute(bool readParams = true);
};
