#include "StopRecAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
StopRecAction::StopRecAction(ApplicationManager* pApp):Action(pApp)
{
}

void StopRecAction::ReadActionParameters()
{
}

void StopRecAction::Execute(bool readParams)
{
	Output* pOut = pManager->GetOutput();
	pManager->setrecording(false);
	pOut->PrintMessage("recording completed you can play it from up there!! B ");
}
