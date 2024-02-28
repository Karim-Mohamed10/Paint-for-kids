#include "AddSquaAction.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "CSquare.h"


AddSquaAction::AddSquaAction(ApplicationManager* pApp):Action(pApp)
{
}

void AddSquaAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at any point");

	pIn->GetPointClicked(P1.x, P1.y);

	SquaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquaGfxInfo.FillClr = pOut->getCrntFillColor();
	if(SquaGfxInfo.FillClr==LIGHTGOLDENRODYELLOW)
		SquaGfxInfo.isFilled = false;
	else
		SquaGfxInfo.isFilled = true;

	pOut->ClearStatusBar();

}
void AddSquaAction::Execute(bool readParams)

{
	
	
	if (readParams == true)
	{
		PlaySound(TEXT("Voice-Bouns\\Squa.wav"), NULL, SND_FILENAME | SND_SYNC);
		if (!pManager->IsPlaying())
			ReadActionParameters();
	}

	
	 S = new CSquare(P1, SquaGfxInfo);

	
	pManager->AddFigure(S);

	//Add Action to undo list
	pManager->AddActionToUndoList(this);
}
void AddSquaAction::ActionUndo()
{
	pManager->DeleteFigureById(S->GetId());
}
