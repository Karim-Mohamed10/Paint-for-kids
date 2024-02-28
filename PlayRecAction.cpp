#include "PlayRecAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include <windows.h>
PlayRecAction::PlayRecAction(ApplicationManager* pApp):Action(pApp)
{

}

void PlayRecAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearStatusBar();
	pOut->PrintMessage("now playing your record click anywhere !");
	Point p;
	pIn->GetPointClicked(p.x, p.y);
	pManager->clearall();
	recmgr = pManager->getrecmgr();
	pManager->setPlaying(true);
}

void PlayRecAction::Execute(bool readParams)
{
	PlaySound(TEXT("Voice-Bouns\\Play.wav"), NULL, SND_FILENAME | SND_SYNC);
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	Action** reclist = recmgr->getreclist();
	int actcount = recmgr->getcount();
	pOut->ClearStatusBar();
	pOut->PrintMessage("playing record");
	for (int i = 0; i < actcount; i++)
	{
		pManager->UpdateInterface();
		Sleep(1000);
		reclist[i]->Execute(false);
		delete reclist[i];
	}
	pManager->setPlaying(false);
	delete recmgr;
	Sleep(1000);
	pOut->ClearStatusBar();
	pOut->PrintMessage("recording over");
}
