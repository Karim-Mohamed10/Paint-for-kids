#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"
class Pickandhide :public Action
{
private:
	CFigure *playfig;
	pickandhideprop type;
	string tname;
	string cname;
	int correct;
	int wrong;
public:
	Pickandhide(ApplicationManager* pApp, pickandhideprop prop);
	virtual void ReadActionParameters();
	virtual void Execute(bool readPara = true);
};

