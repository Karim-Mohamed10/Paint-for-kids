#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"


class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool ClickedPointinsideFig(int x, int y);
	int Getlen();
	int Getwed();
	virtual void MoveFigs(Point NewP);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& iutput);
	virtual void PrintInfo(Output* pOut);
	virtual int GetId();
	~CRectangle();
};

#endif