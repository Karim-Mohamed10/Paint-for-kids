#include "CRectangle.h"
CRectangle::CRectangle() {
	ID = ++count;
	rectcount++;
	type = RECTANGLE;
}
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	ID = ++count;
	rectcount++;
	type = RECTANGLE;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::ClickedPointinsideFig(int x, int y)
{
	Point p1, p2;
	p1.x = Corner2.x;
	p1.y = Corner1.y;

	p2.x = Corner1.x;
	p2.y = Corner2.y;

	double A1 = 0.5 * abs((p2.x * (Corner2.y - y) + Corner2.x * (y - p2.y) + x * (p2.y - Corner2.y)));
	double A2 = 0.5 * abs((Corner1.x * (p1.y - y) + p1.x * (y - Corner1.y) + x * (Corner1.y - p1.y)));
	double A3 = 0.5 * abs((p1.x * (Corner2.y - y) + Corner2.x * (y - p1.y) + x * (p1.y - Corner2.y)));
	double A4 = 0.5 * abs((Corner1.x * (p2.y - y) + p2.x * (y - Corner1.y) + x * (Corner1.y - p2.y)));
	double A = abs((Corner2.x - p2.x) * (p1.y - Corner2.y));
	if (A == A1+A2+A3+A4)
	{
		return true;
	}
	return false;

}

int CRectangle::Getlen()
{
	return abs(Corner2.x - Corner1.x);
}
int CRectangle::Getwed()
{
	return abs(Corner1.y - Corner2.y);
}
void CRectangle::MoveFigs(Point NewP)
{
	double len = Getlen();
	double wed = Getwed();
	Corner1.x = NewP.x - len / 2;
	Corner1.y = NewP.y + wed / 2;
	Corner2.x = NewP.x + len / 2;
	Corner2.y = NewP.y - wed / 2;

}
void CRectangle::Save(ofstream& output)
{
	if (ID == 1) {
		output << count << endl;
	}
	output << "RECT" << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << GetFigColor(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled)
		output << GetFigColor(FigGfxInfo.FillClr) << endl;
	else
		output << "NO_FILL" << endl;

}
void CRectangle::Load(ifstream& input)
{

	string a;
	input >> ID;
	input >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;

	input >> a;

	setCrntDrawClr(a);
	input >> a;
	setCrntFillClr(a);
}
void CRectangle::PrintInfo(Output* pOut) {
	string ID_R, X1, Y1, X2, Y2;
	string width, height;
	ID_R = to_string(ID);
	X1 = to_string(Corner1.x);
	Y1 = to_string(Corner1.y);
	X2 = to_string(Corner2.x);
	Y2 = to_string(Corner2.y);
	width = to_string(abs(Corner1.x - Corner2.x));
	height = to_string(abs(Corner1.y - Corner2.y));

	pOut->PrintMessage(" Rectangle : ID = " + ID_R + "    " + "X1 = " + X1 + "    " + "Y1 = " + Y1 + "    width = " + width + "    Height = " + height);


}
int CRectangle::GetId()
{
	return ID;
}
CRectangle::~CRectangle()
{
	rectcount--;
}
