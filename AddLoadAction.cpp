#include "AddLoadAction.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "Figures/CFigure.h"
#include "Figures/CRectangle.h"
#include "CHexagon.h"
#include "CSquare.h"
#include "CTriangle.h"
#include "CCircle.h"

using namespace std;
AddLoadAction::AddLoadAction(ApplicationManager* pApp) :Action(pApp)
{
	x = true;
}

void AddLoadAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("please enter the file name ");

	name = pIn->GetSrting(pOut);


}
void AddLoadAction::setCrntDrawColor(string a)
{
	if (a == "BLUE") {
		UI.DrawColor = BLUE;
	}
	if (a == "ORANGE")
		UI.DrawColor = ORANGE;
	if (a == "RED")
		UI.DrawColor = RED;
	if (a == "BLACK")
		UI.DrawColor = BLACK;
	if (a == "YELLOW")
		UI.DrawColor = YELLOW;
	if (a == "GREEN")
		UI.DrawColor = GREEN;


}
void AddLoadAction::setCrntFillColor(string a)
{
	if (a == "BLUE") {
		UI.FillColor = BLUE;
	}
	if (a == "ORANGE")
		UI.FillColor = ORANGE;
	if (a == "RED")
		UI.FillColor = RED;
	if (a == "BLACK")
		UI.FillColor = BLACK;
	if (a == "YELLOW")
		UI.FillColor = YELLOW;
	if (a == "GREEN")
		UI.FillColor = GREEN;
	if (a == "NO_FILL")
		UI.FillColor = LIGHTGOLDENRODYELLOW;

}




void AddLoadAction::Execute(bool readParams)
{

	Output* pOut = pManager->GetOutput();
	if (readParams) {
		PlaySound(TEXT("Voice-Bouns\\File.wav"), NULL, SND_FILENAME | SND_SYNC);
		ReadActionParameters();
	}
	else
	{
		name = "youssef";
	}
	
	input.open(name + ".txt");
	if (input.is_open()) {

		pManager->clearall();

		string a;
		int b;
		input >> a;
		setCrntDrawColor(a);

		input >> a;
		setCrntFillColor(a);

		input >> b;





		CFigure* fig = NULL;
		for (int i = 0; i < b; i++) {

			input >> a;
			if (a == "RECT")
				fig = new CRectangle;
			if (a == "SQUA")
				fig = new CSquare;
			if (a == "TRIA")
				fig = new CTriangle;
			if (a == "CIRC")
				fig = new CCircle;
			if (a == "HEXA")
				fig = new CHexagon;
			fig->Load(input);
			pManager->AddFigure(fig);

		}
		if (readParams)
		pOut->PrintMessage(name + " file is loaded :)");
	}
	else
		pOut->PrintMessage("this file doesn't exist");

	input.close();
}
