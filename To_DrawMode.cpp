#include "To_DrawMode.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "ApplicationManager.h"
#include "AddLoadAction.h"

To_DrawMode::To_DrawMode(ApplicationManager* pApp):Action(pApp)
{
}

void To_DrawMode::ReadActionParameters()
{
}

void To_DrawMode::Execute(bool readParams)
{
	
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pOut->ClearToolBar();

	pOut->CreateDrawToolBar();
	AddLoadAction l(pManager);
	l.Execute(false);
	pOut->PrintMessage("Now you are back to the draw mode :) ");

}
