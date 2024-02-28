#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"
#include <fstream>
#include <windows.h>
#include <mmsystem.h>
/*#include "../ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"*/

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
private:
	bool isRecorded;
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job

public:

	Action(ApplicationManager* pApp);
	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute(bool readPara = true) = 0;

	//Undo Function
	virtual void ActionUndo() {};


	bool GetisRecorded() { return isRecorded; };

};

#endif