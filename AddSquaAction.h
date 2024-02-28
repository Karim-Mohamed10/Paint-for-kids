#pragma once
#include "Actions/Action.h"
#include "CSquare.h"
class AddSquaAction : public Action
{
private:
	Point P1; 
	GfxInfo SquaGfxInfo;
	CSquare* S;
public:
	AddSquaAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute(bool readParams = true);


	virtual void ActionUndo();

};


