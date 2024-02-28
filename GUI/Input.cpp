#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

void Input::getlastpoint(Point &p)
{
	pWind->GetMouseCoord(p.x,p.y);
}

bool Input::isclicked(Point &p)
{
	
	if (pWind->GetButtonState(LEFT_BUTTON, p.x, p.y) == BUTTON_DOWN)
		return true;
	else
		return false;
}

void Input::flushmouse()
{
	pWind->FlushMouseQueue();
	pWind->UpdateBuffer();
}

void Input::getmouseclick(Point& p)
{
	pWind->GetMouseClick(p.x, p.y);
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQUARE:return DRAW_SQUARE;

			case ITM_TRIANGLE: return DRAW_TRIANGLE;
			case ITM_HEXAGON: return DRAW_HEXAGON;

			case ITM_CIRCLE: return DRAW_CIRC;
			case ITM_SELECT_ONE: return DRAW_SELECT_ONE;

			case ITM_DRAWING_COLOR: return DRAW_DRAWING_COLOR;
			case ITM_FILLING_COLOR: return DRAW_FILLING_COLOR;
			case ITM_DELETE: return DRAW_DELETE;
			case ITM_MOVE: return DRAW_MOVE;
			case ITM_UNDO: return DRAW_UNDO;
			case ITM_REDO: return DRAW_REDO;
			case ITM_CLEAR_ALL: return DRAW_CLEAR_ALL;
			case ITM_START_REC: return DRAW_START_REC;

			case ITM_STOP_REC: return DRAW_STOP_REC;
			case ITM_PLAY_RECORDING: return DRAW_PLAY_RECORDING;
			case ITM_SAVE_GRAPH: return DRAW_SAVE_GRAPH;
			case ITM_LOAD_GRAPH: return DRAW_LOAD_GRAPH;

			case ITM_BLACK: return COLOR_BLACK;
			case ITM_YELLOW: return COLOR_YELLOW;
			case ITM_ORANGE: return COLOR_ORANGE;
			case ITM_RED: return COLOR_RED;
			case ITM_GREEN: return COLOR_GREEN;
			case ITM_BLUE: return COLOR_BLUE;

			case ITM_SWITCH_TO_PLAYMODE: return TO_PLAYMODE;

			case ITM_EXIT: return EXIT;

			default: return EMPTYDRAW;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case PICK_HIDE_TYPE: return PICK_WTYPE;
			case PICK_HIDE_COLOR: return PICK_WCOLOR;
			case PICK_HIDE_TYPE_COLOR: return PICK_WTYP_WCOL;
			case SWITCH_TO_DRAW: return TO_DRAW;
			default: return EMPTYPLAY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return STATUS;
	}

}
/////////////////////////////////

Input::~Input()
{
}
