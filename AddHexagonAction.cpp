#include "AddHexagonAction.h"
#include "ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"
#include "CHexagon.h"


AddHexagonAction::AddHexagonAction(ApplicationManager* pApp):Action(pApp)
{
}

void AddHexagonAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at any point");

	pIn->GetPointClicked(p1.x, p1.y);

	HexaGfxInfo.isFilled = false;
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();
	if (HexaGfxInfo.FillClr == LIGHTGOLDENRODYELLOW)
		HexaGfxInfo.isFilled = false;
	else
		HexaGfxInfo.isFilled = true;
	pOut->ClearStatusBar();
}

void AddHexagonAction::Execute(bool readParams)

{
	
	if (readParams == true)
	{
		PlaySound(TEXT("Voice-Bouns\\Hexa.wav"), NULL, SND_FILENAME | SND_SYNC);
		if (!pManager->IsPlaying())
			ReadActionParameters();
	}


    H = new CHexagon(p1, HexaGfxInfo);


	pManager->AddFigure(H);

	pManager->AddActionToUndoList(this);
}
void AddHexagonAction::ActionUndo()
{
	pManager->DeleteFigureById(H->GetId());
}
