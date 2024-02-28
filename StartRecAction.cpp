#include "StartRecAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
StartRecAction::StartRecAction(ApplicationManager* pApp) :Action(pApp)
{
	count = 0;
}

void StartRecAction::ReadActionParameters()
{
}

void StartRecAction::Execute(bool readParams)
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	if (pManager->isclear())
	{
		PlaySound(TEXT("Voice-Bouns\\Rec.wav"), NULL, SND_FILENAME | SND_SYNC);
		pOut->PrintMessage("let's record your magnificent art!!!");
		pManager->setrecording(true);
	}
	else
		pOut->PrintMessage("if you want to record your drawings clear the drawing area first ;)");
}

void StartRecAction::recordaction(Action* act)
{
	if (count < 20)
	{
		recordedactions[count++] = act;
	}
	if (count == 20)
	{
		pManager->setrecording(false);
		pManager->GetOutput()->PrintMessage("you are out of moves! go ahead and play your record from up there :D !!");
	}
}

Action** StartRecAction::getreclist()
{
	return recordedactions;
}

int StartRecAction::getcount()
{
	return count;
}
