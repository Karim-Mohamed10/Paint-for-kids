#include "CSquare.h"
CSquare::CSquare()
{
	ID = ++count;
	sqcount++;
	type = SQUARE;
}

CSquare::CSquare(Point p1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	p = p1;
	ID = ++count;
	sqcount++;
	type = SQUARE;
}

void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSqua(p, FigGfxInfo, Selected);
}
bool CSquare::ClickedPointinsideFig(int x, int y)
{
	int dis = sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
	int Maxdis = sqrt(2 * pow(100, 2));
	if (dis <= Maxdis)
	{
		return true;
	}
	return false;
}
void CSquare::MoveFigs(Point NewP)
{
	p.x = NewP.x;
	p.y = NewP.y;
}
void CSquare::Save(ofstream& output)
{
	if (ID == 1) {
		output << count << endl;
	}
	output << "SQUA" << " " << ID << " " << p.x << " " << p.y << " " << GetFigColor(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled)
		output << GetFigColor(FigGfxInfo.FillClr) << endl;
	else
		output << "NO_FILL" << endl;

}
void CSquare::Load(ifstream& input)
{

	string a;
	input >> ID;
	input >> p.x >> p.y;
	input >> a;
	setCrntDrawClr(a);
	input >> a;
	setCrntFillClr(a);

}
void CSquare::PrintInfo(Output* pOut) {
	string ID_S, X, Y;
	ID_S = to_string(ID);
	X = to_string(p.x);
	Y = to_string(p.y);

	pOut->PrintMessage(" Square : ID = " + ID_S + "    " + "X = " + X + "    " + "Y = " + Y + "    width = 200    Height = 200 ");

}
int CSquare::GetId()
{
	return ID;
}
CSquare::~CSquare()
{
	sqcount--;
}


