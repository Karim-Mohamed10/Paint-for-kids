#include "SelectAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"


SelectAction::SelectAction(ApplicationManager* pApp):Action(pApp)
{
}
void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	

	pOut->PrintMessage("Select Item to Use Amazing features! Click inside any Figure");


	//Read the point from user
	pIn->GetPointClicked(p1.x, p1.y);
	

}
void SelectAction::Execute(bool readParams)
{
	if(readParams==true)
	PlaySound(TEXT("Voice-Bouns\\Sel.wav"), NULL, SND_FILENAME | SND_SYNC);

	
	if (!pManager->IsPlaying())
	ReadActionParameters();

	Output* pOut = pManager->GetOutput(); // to clear status bar 
	//Input* pIn = pManager->GetInput();

	
	CFigure *ptrTOfig = pManager->GetFigure(p1.x, p1.y);
	


	pOut->ClearStatusBar();

	if (ptrTOfig != NULL)
	{
		if (ptrTOfig->IsSelected())
		{
			
			ptrTOfig->SetSelected(false);
			pManager->SetSelectedFig(NULL);
			ptrTOfig->ChngDrawClr(UI.DrawColor);
		}
		else
		{
			ptrTOfig->PrintInfo(pOut);    //print fig informations
			ptrTOfig->SetSelected(true);
			pManager->SetSelectedFig(ptrTOfig);
		}
		pManager->OnlyThisFigIsSelected(ptrTOfig);
	}
	else
	{
		pOut->PrintMessage("OOPs! Please Click inside the shape");
		pManager->OnlyThisFigIsSelected(NULL);       //now we want to unselect all the figures nothing will be selected 
		pManager->SetSelectedFig(NULL);                 // bec. there is nothing is selected 
	}
}