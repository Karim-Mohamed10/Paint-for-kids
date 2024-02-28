#include "CHexagon.h"
CHexagon::CHexagon()
{
	ID = ++count;
	hexcount++;
	type = HEXAGON;
}
CHexagon::CHexagon(Point p1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	p = p1;
	ID = ++count;
	hexcount++;
	type = HEXAGON;
}

void CHexagon::Draw(Output* pOut) const
{
	pOut->Drawhexa(p, FigGfxInfo, Selected);
}
bool CHexagon::ClickedPointinsideFig(int x, int y)
{
	Point p1,p2,p3,p4,p5,p6;

	p1.x = p.x + 100;
	p1.y = p.y + 58;
	p2.x = p.x + 100;
	p2.y = p.y - 58;
	p3.x = p.x;
	p3.y = p.y - 116;
	p4.x = p.x - 100;
	p4.y = p.y - 58;
	p5.x = p.x - 100;
	p5.y = p.y + 58;
	p6.x = p.x ;
	p6.y = p.y + 116;


	double A1 = 0.5 * abs((p2.x * (p4.y - y) + p4.x * (y - p2.y) + x * (p2.y - p4.y)));
	double A2 = 0.5 * abs((p5.x * (p1.y - y) + p1.x * (y - p5.y) + x * (p5.y - p1.y)));
	double A3 = 0.5 * abs((p5.x * (p4.y - y) + p4.x * (y - p5.y) + x * (p5.y - p4.y)));
	double A4 = 0.5 * abs((p1.x * (p2.y - y) + p2.x * (y - p1.y) + x * (p1.y - p2.y)));
	double A = abs((p2.x - p4.x) * (p1.y - p2.y));

	if (A1 + A2 + A3 + A4 == A)
		return true;

	double AT1X = 0.5 * abs(p1.x * (p6.y - y) + p6.x * (y - p1.y) + x * (p1.y - p6.y));
	double AT2X = 0.5 * abs((p6.x * (p5.y - y) + p5.x * (y - p6.y) + x * (p6.y - p5.y)));
	double AT3X = 0.5 * abs((p5.x * (p1.y - y) + p1.x * (y - p5.y) + x * (p5.y - p1.y)));
	double ATX = 0.5 * abs((p1.x * (p5.y - p6.y) + p5.x * (p6.y - p1.y) + p6.x * (p1.y - p5.y)));

	if (AT1X + AT2X + AT3X == ATX)
		return true;

	double AT1Y = 0.5 * abs((p2.x * (p4.y - y) + p4.x * (y - p2.y) + x * (p2.y - p4.y)));
	double AT2Y = 0.5 * abs((p4.x * (p3.y - y) + p3.x * (y - p4.y) + x * (p4.y - p3.y)));
	double AT3Y = 0.5 * abs((p3.x * (p2.y - y) + p2.x * (y - p3.y) + x * (p3.y - p2.y)));
	double ATY = 0.5 * abs((p4.x * (p2.y - p3.y) + p2.x * (p3.y - p4.y) + p3.x * (p4.y - p2.y)));

	if (AT1Y + AT2Y + AT3Y == ATY)
		return true;

	return false;
}
void CHexagon::MoveFigs(Point NewP)
{
	p.x = NewP.x;
	p.y = NewP.y;
}
void CHexagon::Save(ofstream& output)
{
	if (ID == 1) {
		output << count << endl;
	}
	output << "HEXA" << " " << ID << " " << p.x << " " << p.y << " " << GetFigColor(FigGfxInfo.DrawClr) << " ";
	if (FigGfxInfo.isFilled)
		output << GetFigColor(FigGfxInfo.FillClr) << endl;
	else
		output << "NO_FILL" << endl;

}
void CHexagon::Load(ifstream& input)
{

	string a;
	input >> ID;
	input >> p.x >> p.y;
	input >> a;
	setCrntDrawClr(a);
	input >> a;
	setCrntFillClr(a);



}
void CHexagon::PrintInfo(Output* pOut) {
	string ID_H, X, Y;
	ID_H = to_string(ID);
	X = to_string(p.x);
	Y = to_string(p.y);
	pOut->PrintMessage(" Hexagon : ID = " + ID_H + "    " + "X = " + X + "    " + "Y = " + Y + "    width = 200    height = 116 ");


}

int CHexagon::GetId()
{
	return ID;
}

CHexagon::~CHexagon()
{
	hexcount--;
}
