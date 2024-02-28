#include "MoveAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "Figures/CRectangle.h"
#include "CSquare.h"
#include "CHexagon.h"
#include "CCircle.h"

MoveAction::MoveAction(ApplicationManager* pApp) : Action(pApp)
{
	p.x = -1;
	p.y = -1;
}
MoveAction::MoveAction(ApplicationManager* pApp, Point pp):Action(pApp)
{
	p.x = pp.x;
	p.y = pp.y;
}
void MoveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	// Check if there is a selected figure or not
	if (pManager->GetSelectedFig())
	{
		pOut->PrintMessage("Click a Point on Screen To Move Selected Figure");
		//Read the point from user
		pIn->GetPointClicked(p.x, p.y);
	}
	else 
		pOut->PrintMessage("Please Select A Figure First!!");
		

}
void MoveAction::Execute(bool readParams)
{
	if(readParams==true)
	PlaySound(TEXT("Voice-Bouns\\Move.wav"), NULL, SND_FILENAME | SND_SYNC);
	if(!pManager->IsPlaying() && (p.x == -1 || p.y == -1))
	ReadActionParameters();
	Output* pOut = pManager->GetOutput(); // to clear status bar 
	Input* pIn = pManager->GetInput();

	
	pOut->ClearStatusBar();
	if (pManager->GetSelectedFig() != NULL)
		pManager->GetSelectedFig()->MoveFigs(p);
	else
		pOut->PrintMessage("Oops! please select a figure to move");
	}