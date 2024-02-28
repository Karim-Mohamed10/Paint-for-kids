#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"


class MoveAction : public Action
{
private:
	CFigure* FigToMove;
	Point p;
public:
	MoveAction(ApplicationManager* pApp);
	MoveAction(ApplicationManager* pApp, Point pp);//another constructor for moving a figure by dragging it
	
	// Reads info of the selected figure to move it 
	virtual void ReadActionParameters();

	
	// moves the selected fig 
	virtual void Execute(bool readPara = true);
};
