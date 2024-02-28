#include "RedoAction.h"
#include "ApplicationManager.h"
RedoAction::RedoAction(ApplicationManager* pApp) : Action(pApp)
{

}
void RedoAction::ReadActionParameters()
{

}
void RedoAction::Execute(bool readParams)
{
	pManager->Redo();
}
