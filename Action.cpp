#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

Action::Action(ApplicationManager* pApp)
{
	{
		pManager = pApp;
		isRecorded = pApp->GetisRecorded();
	}	//constructor
}