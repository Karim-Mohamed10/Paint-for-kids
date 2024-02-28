#pragma once
#include "Actions/Action.h"
#include <fstream>
class AddLoadAction :public Action
{
private:
	string name;
	ifstream input;
	bool x;
public:
	AddLoadAction(ApplicationManager* pApp);

	void setCrntDrawColor(string a);//func to set curr draw clr by sending clr as string
	void setCrntFillColor(string a);// func to set curr fill clr by sending clr as string 
	virtual void ReadActionParameters();


	virtual void Execute(bool readParams = true);
};


