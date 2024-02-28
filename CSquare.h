#pragma once
#include "Figures/CFigure.h"
class CSquare:public CFigure
{
private:
	Point p;
public:
	
	CSquare();
	CSquare(Point p1,  GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool ClickedPointinsideFig(int x, int y);
	virtual void MoveFigs(Point NewP);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& iutput);
	virtual void PrintInfo(Output* pOut);
	virtual int GetId();
	~CSquare();
};

