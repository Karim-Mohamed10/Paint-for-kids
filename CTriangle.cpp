#include "CTriangle.h"
CTriangle::CTriangle()
{
	ID = ++count;
	tricount++;
	type = TRIANGLE;
}

CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	corner1 = p1;
	corner2 = p2;
	corner3 = p3;
	ID = ++count;
	tricount++;
	type = TRIANGLE;
}

void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTria(corner1, corner2, corner3, FigGfxInfo, Selected);
}
bool CTriangle::ClickedPointinsideFig(int x, int y)
{
	double A1 = 0.5 * abs((corner1.x * (corner2.y - y) + corner2.x * (y - corner1.y) + x * (corner1.y - corner2.y)));
	double A2 = 0.5 * abs((corner1.x * (corner3.y - y) + corner3.x * (y - corner1.y) + x * (corner1.y - corner3.y)));
	double A3 = 0.5 * abs((corner3.x * (corner2.y - y) + corner2.x * (y - corner3.y) + x * (corner3.y - corner2.y)));
	double A = 0.5 * abs((corner1.x * (corner2.y - corner3.y) + corner2.x * (corner3.y - corner1.y) + corner3.x * (corner1.y - corner2.y)));

	if (A == A1 + A2 + A3)
	{
		return true;
	}
	return false;
}

void CTriangle::MoveFigs(Point NewP)
{
	Point cen;
	cen.x = (corner1.x + corner2.x + corner3.x) / 3;
	cen.y = (corner1.y + corner2.y + corner3.y) / 3;

	double Difx = cen.x - NewP.x;
	double Dify = cen.y - NewP.y;

	corner1.x -= Difx;
	corner1.y -= Dify;
	corner2.x -= Difx;
	corner2.y -= Dify;
	corner3.x -= Difx;
	corner3.y -= Dify;
}
void CTriangle::Save(ofstream& output)
{
	if (ID == 1) {
		output << count << endl;
	}
	output << "TRIA" << " " << ID << " " << corner1.x << " " << corner1.y << " " << corner2.x << " " << corner2.y << " " << corner3.x << " " << corner3.y << " " << GetFigColor(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled)
		output << GetFigColor(FigGfxInfo.FillClr) << endl;
	else
		output << "NO_FILL" << endl;

}
void CTriangle::Load(ifstream& input)
{

	string a;
	input >> ID;
	input >> corner1.x >> corner1.y >> corner2.x >> corner2.y >> corner3.x >> corner3.y;
	input >> a;
	setCrntDrawClr(a);
	input >> a;
	setCrntFillClr(a);
}
void CTriangle::PrintInfo(Output* pOut) {
	string ID_T, X1, Y1, X2, Y2, X3, Y3;
	ID_T = to_string(ID);
	X1 = to_string(corner1.x);
	Y1 = to_string(corner1.y);
	X2 = to_string(corner2.x);
	Y2 = to_string(corner2.y);
	X3 = to_string(corner3.x);
	Y3 = to_string(corner3.y);
	pOut->PrintMessage(" Triangle : ID = " + ID_T + "    " + "X1 = " + X1 + "    " + "Y1 = " + Y1 + "    " + "X2 = " + X2 + "    " + "Y2 = " + Y2 + "    " + "X3= " + X3 + "    " + "Y3 = " + Y3);


}
int CTriangle::GetId()
{
	return ID;
}
CTriangle::~CTriangle()
{
	tricount--;
}
