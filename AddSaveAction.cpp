
#include "AddSaveAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"


AddSaveAction::AddSaveAction(ApplicationManager* pApp) :Action(pApp)
{
	x = true;
}



void AddSaveAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("please enter the file name ");

	name = pIn->GetSrting(pOut);

	pOut->PrintMessage("the file has been saved ");


}

string AddSaveAction::GetFigColor(color a)
{
	// get the curren draw/fill color as string so i can save it in a file.txt
	if (a == BLUE) {
		return "BLUE";
	}
	if (a == ORANGE)
		return "ORANGE";
	if (a == RED)
		return "RED";
	if (a == BLACK)
		return "BLACK";
	if (a == YELLOW)
		return "YELLOW";
	if (a == GREEN)
		return"GREEN";

	return "NO_FILL";

}
void AddSaveAction::Execute(bool readParams)
{
	if (readParams) {
		PlaySound(TEXT("Voice-Bouns\\File.wav"), NULL, SND_FILENAME | SND_SYNC);
		ReadActionParameters();
	}
	else
	{
		name = "youssef";
	}

	output.open(name + ".txt");
	Output* pOut = pManager->GetOutput();
	output << GetFigColor(pOut->getCrntDrawColor()) << " " << GetFigColor(pOut->getCrntFillColor()) << endl;

	pManager->SaveAll(output);
	output.close();
}
