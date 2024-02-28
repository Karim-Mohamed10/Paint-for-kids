#include "Pickandhide.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "AddLoadAction.h"
#include "DeleteAction.h"
#include "To_DrawMode.h"
#include "stdlib.h"
Pickandhide::Pickandhide(ApplicationManager* pApp, pickandhideprop prop):Action(pApp)
{
	type = prop;
}

void Pickandhide::ReadActionParameters()
{
	AddLoadAction l(pManager);
	l.Execute(false);
	pManager->UpdateInterface();
}

void Pickandhide::Execute(bool readParams)
{
	ReadActionParameters();
	Point P;
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	correct = 0;
	wrong = 0;
	bool switched;
	figuretype ftype;
	switch (type)
	{
	case TYPE:
		ftype = figuretype(rand()%5);
		while(!pManager->doestypeexists(ftype,tname))
			ftype = figuretype(rand() % 5);
			pOut->ClearStatusBar();
			pOut->PrintMessage("choose figures of type " + tname);
			switched = false;
		while (pManager->doestypeexists(ftype,tname))
		{
			pIn->GetPointClicked(P.x, P.y);
			playfig = pManager->GetFigure(P.x, P.y);
			if (P.y >= 0 && P.y < UI.ToolBarHeight&& P.x / UI.MenuItemWidth == 3)
			{
				To_DrawMode td(pManager);
				td.Execute();
				switched = true;
				break;
			}
			if (playfig)
			{
				if (playfig->type == ftype)
				{
					playfig->SetSelected(true);
					pManager->SetSelectedFig(playfig);
					pManager->DeletingFigure();
					pManager->UpdateInterface();
					playfig = NULL;
					pOut->ClearStatusBar();
					pOut->PrintMessage("Bravo!!    Correct = " + to_string(++correct) + "  Wrong = " + to_string(wrong));
				}
				else
				{
					pOut->ClearStatusBar();
					pOut->PrintMessage("Try again!!    Correct = " + to_string(correct) + "  Wrong = " + to_string(++wrong));
				}
			}
			else
			{
				pOut->ClearStatusBar();
				pOut->PrintMessage("Try again!!    Correct = " + to_string(correct) + "  Wrong = " + to_string(wrong));
			}
		}
		if (!switched)
		{
			pOut->ClearStatusBar();
			pOut->PrintMessage("Congrats!!    Correct = " + to_string(correct) + "  Wrong = " + to_string(wrong) + " Play again from the different modes above or switch to drawmode !!");
			pOut->ClearDrawArea();
		}
		break;

	case COLOR:
		figurecolors collr;
		collr = figurecolors(rand() % 7);
		while (!pManager->doestypeexists(collr, cname))
			collr = figurecolors(rand() & 7);
		pOut->ClearStatusBar();
		pOut->PrintMessage("choose figures of color " + cname);
		switched = false;
		while (pManager->doestypeexists(collr, cname))
		{
			pIn->GetPointClicked(P.x, P.y);
			playfig = pManager->GetFigure(P.x, P.y);
			if (P.y >= 0 && P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == 3)
			{
				To_DrawMode td(pManager);
				td.Execute();
				switched = true;
				break;
			}
			if (playfig)
			{
				if (playfig->givecolor() == cname)
				{
					playfig->SetSelected(true);
					pManager->SetSelectedFig(playfig);
					pManager->DeletingFigure();
					pManager->UpdateInterface();
					playfig = NULL;
					pOut->ClearStatusBar();
					pOut->PrintMessage("Bravo!!    Correct = " + to_string(++correct) + "  Wrong = " + to_string(wrong));
				}
				else
				{
					pOut->ClearStatusBar();
					pOut->PrintMessage("Try again!!    Correct = " + to_string(correct) + "  Wrong = " + to_string(++wrong));
				}
			}
			else
			{
				pOut->ClearStatusBar();
				pOut->PrintMessage("Try again!!    Correct = " + to_string(correct) + "  Wrong = " + to_string(wrong));
			}
		}
		if (!switched)
		{
			pOut->ClearStatusBar();
			pOut->PrintMessage("Congrats!!    Correct = " + to_string(correct) + "  Wrong = " + to_string(wrong) + " Play again from the different modes above or switch to drawmode !!");
			pOut->ClearDrawArea();
		}
		break;
	case TYPENCOLOR:
		figurecolors colr = figurecolors(rand() % 7);
		ftype = figuretype(rand() % 5);
		while (!pManager->doestypeexists(ftype, colr, tname, cname))
		{
			colr = figurecolors(rand() & 7);
			ftype = figuretype(rand() % 5);
		}
		pOut->ClearStatusBar();
		pOut->PrintMessage("choose " + cname + " " + tname+"s only");
		switched = false;
		while(pManager->doestypeexists(ftype, colr, tname, cname))
		{
			pIn->GetPointClicked(P.x, P.y);
		if (P.y >= 0 && P.y < UI.ToolBarHeight && P.x / UI.MenuItemWidth == 3)
		{
			To_DrawMode td(pManager);
			td.Execute();
			switched = true;
			break;
		}
			playfig = pManager->GetFigure(P.x, P.y);
			if (playfig)
			{
				if (playfig->givecolorasenum() == colr && playfig->type == ftype)
				{
					playfig->SetSelected(true);
					pManager->SetSelectedFig(playfig);
					pManager->DeletingFigure();
					pManager->UpdateInterface();
					playfig = NULL;
					pOut->ClearStatusBar();
					pOut->PrintMessage("Bravo!!    Correct = " + to_string(++correct) + "  Wrong = " + to_string(wrong));
				}
				else
				{
					pOut->ClearStatusBar();
					pOut->PrintMessage("Try again!!    Correct = " + to_string(correct) + "  Wrong = " + to_string(++wrong));
				}
			}
			else
			{
				pOut->ClearStatusBar();
				pOut->PrintMessage("Try again!!    Correct = " + to_string(correct) + "  Wrong = " + to_string(wrong));
			}
		}
		if (!switched)
		{
			pOut->ClearStatusBar();
			pOut->PrintMessage("Congrats!!    Correct = " + to_string(correct) + "  Wrong = " + to_string(wrong) + " Play again from the different modes above or switch to drawmode !!");
			pOut->ClearDrawArea();
		}
		break;
	}
}
