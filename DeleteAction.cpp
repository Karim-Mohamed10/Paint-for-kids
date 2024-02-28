#include "DeleteAction.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp)
{
}

//Reads parameters required for action to execute (code depends on action type)
void DeleteAction::ReadActionParameters()
{
		

}

//Execute action (code depends on action type)
void DeleteAction::Execute(bool readParams)
{
	Output* pOut = pManager->GetOutput(); 
	Input* pIn = pManager->GetInput();
	
	if (pManager->GetSelectedFig() != NULL)
	{
		pOut->PrintMessage("Deleting the selected figure");
		pManager->DeletingFigure(); // Calling Delete seelected Figure
		pOut->PrintMessage("The selected Figure is successfully Deleted");
	}
	else
		pOut->PrintMessage("Please Select a Figure to Delete");


}