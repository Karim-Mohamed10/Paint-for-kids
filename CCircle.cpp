#include "CCircle.h"
#define pi 3.14
CCircle::CCircle()
{
	ID = ++count;
	circcount++;
	type = CIRCLE;
}
CCircle::CCircle(Point c1,Point c2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	p1 = c1;
	p2 = c2;
	ID = ++count;
	circcount++;
	type = CIRCLE;
}

void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCirc(p1,p2, FigGfxInfo, Selected);
}
bool CCircle::ClickedPointinsideFig(int x, int y)
{
	int Maxdis = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	int dis = sqrt(pow(p1.x - x, 2) + pow(p1.y - y, 2));
	if (dis <= Maxdis)
	{
		return true;
	}
	return false;
}
double CCircle::GetRadius()
{
	return sqrt(pow(p1.x - p2.x , 2)+pow(p1.y - p2.y , 2));
}
void CCircle::MoveFigs(Point NewP)
{
	double r = GetRadius();
	p1.x = NewP.x; 
	p1.y = NewP.y; 
	p2.x = p1.x + r;
	p2.y = p1.y;
}
void CCircle::Save(ofstream& output)
{
	if (ID == 1) {
		output << count << endl;
	}
	output << "CIRC" << " " << ID << " " << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << " " << GetFigColor(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled)
		output << GetFigColor(FigGfxInfo.FillClr) << endl;
	else
		output << "NO_FILL" << endl;

}
void CCircle::Load(ifstream& input)
{

	string a;
	input >> ID;
	input >> p1.x >> p1.y >> p2.x >> p2.y;
	input >> a;
	setCrntDrawClr(a);
	input >> a;
	setCrntFillClr(a);
}
void CCircle::PrintInfo(Output* pOut) {
	string ID_C, X1, Y1, X2, Y2, Radius;
	ID_C = to_string(ID);
	X1 = to_string(p1.x);
	Y1 = to_string(p1.y);
	X2 = to_string(p2.x);
	Y2 = to_string(p2.y);
	Radius = to_string(sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)));

	pOut->PrintMessage(" Circle : ID = " + ID_C + "    " + "X1 = " + X1 + "    " + "Y1 = " + Y1 + "    Radius = " + Radius);

}
int CCircle::GetId()
{
	return ID;
}
CCircle::~CCircle()
{
	circcount--;
}
