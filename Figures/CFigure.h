#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

#include <fstream>

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	static int count;
	/// Add more parameters if needed.

public:
	figuretype type;
	color Colour;
	static int circcount;
	static int hexcount;
	static int rectcount;
	static int sqcount;
	static int tricount;
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	
	virtual bool ClickedPointinsideFig(int x, int y) = 0; // check if clicked point is inside a figure or not

	void setCount(int a);//func to set count

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure

	void CFigure::setCrntFillClr(string a);// set fig draw  color by sending the color as  a string
	void CFigure::setCrntDrawClr(string a);// set fig fill color by sending the color as a string
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	virtual void MoveFigs(Point NewP) = 0;
	string GetFigColor(color a);// func to get the fig draw /fill clr as a string

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	string givecolor();
	figurecolors givecolorasenum();

	virtual int GetId() = 0;
};

#endif