#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,
	DRAW_SQUARE,
	DRAW_TRIANGLE,
	DRAW_HEXAGON,	//Draw Rectangle
	DRAW_CIRC,//Draw Circle
	DRAW_SELECT_ONE,

	DRAW_DRAWING_COLOR, //black, yellow, orange, red, green, and blue.
	DRAW_FILLING_COLOR, //black, yellow, orange, red, green, and blue.

	DRAW_DELETE,
	DRAW_MOVE,
	DRAW_UNDO,
	DRAW_REDO,
	DRAW_CLEAR_ALL,

	DRAW_START_REC,
	DRAW_STOP_REC,
	DRAW_PLAY_RECORDING,

	DRAW_SAVE_GRAPH,
	DRAW_LOAD_GRAPH,

	COLOR_BLACK,
	COLOR_YELLOW,
	COLOR_ORANGE,
	COLOR_RED,
	COLOR_GREEN,
	COLOR_BLUE,


	TO_PLAYMODE,  //Switch interface to Play mode
	EXIT,  //Exit
	PICK_WTYPE,
	PICK_WCOLOR,
	PICK_WTYP_WCOL,
	TO_DRAW,		//Switch interface to Draw mode		
	EMPTYDRAW,
	EMPTYPLAY,//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};
enum pickandhideprop
{
	TYPE,
	COLOR,
	TYPENCOLOR
};
enum figuretype
{
	RECTANGLE,
	SQUARE,
	TRIANGLE,
	CIRCLE,
	HEXAGON
};
enum figurecolors
{
	NOFILL,
	BBLACK,
	YYELLOW,
	OORANGE,
	RRED,
	GGREEN,
	BBLUE
};
#endif