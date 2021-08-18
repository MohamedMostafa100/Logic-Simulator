//#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetString(Output* pOut, string msg, string str)
const {
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar
	const int escape = 27, enter = 13, backspace = 8; //using ascii code
	char c;
	string s = str;
	pWind->FlushKeyQueue();
	do
	{
		pOut->PrintMsg(msg + " " + s);
		pWind->WaitKeyPress(c);
		switch (c)
		{
		case escape:
			s.clear(); //return empty string
			break;
		case enter:
			break; //end of input and reflect string
		case backspace:
			if (!s.empty())
			{
				s.pop_back(); //erase 1 step
			}
			break;
		default:
			s.push_back(c); //keep the char
			break;
		}
	} while (c != escape && c != enter); //while not escape nor enter reflect the char on the screen
	/*int x;
	int y;
	pWind->WaitMouseClick(x, y);
	pWind->DrawString(x, y, s);*/
	return s;
}


//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			if (UI.DesignToolbar == EDITCIRCT) // if the user is clicking on the default design toolbar
			{
				//Check whick Menu item was clicked
				//==> This assumes that menu items are lined up horizontally <==
				int ClickedItemOrder = (x / UI.ToolItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				switch (ClickedItemOrder)
				{
				case ITM_ADD: return ADDGATE_Menu;
				case ITM_ADDLABEL: return ADD_Label;
				case ITM_EDITLABEL: return EDIT_Label;
				case ITM_SELECT: return SELECT_ICON;
				case ITM_MOVE: return MOVE;
				case ITM_LOAD: return LOAD;
				case ITM_SAVE: return SAVE;
				case ITM_SwitchToSimulation: return SIM_MODE;
				case ITM_UNDO: return UNDO;
				case ITM_REDO: return REDO;
				case ITM_EXIT: return EXIT;
				case ITM_COPY: return COPY;
				case ITM_CUT: return CUT;
				case ITM_PASTE: return PASTE;
				case ITM_DELETE: return DEL;

				default: return DSN_TOOL;	//A click on empty place in desgin toolbar
				}
			}
			else if (UI.DesignToolbar == ADDGATE) //if the user is clicking on the addgate toolbar
			{

				int ClickedItemOrder = (x / UI.ToolItemWidth);

				switch (ClickedItemOrder)
				{

				case ITM_AND2: return ADD_AND_GATE_2;
				case ITM_OR2: return ADD_OR_GATE_2;
				case ITM_Buffer: return ADD_Buff;
				case ITM_INV: return ADD_INV;
				case ITM_NAND: return ADD_NAND_GATE_2;
				case ITM_NOR: return ADD_NOR_GATE_2;
				case ITM_XOR: return ADD_XOR_GATE_2;
				case ITM_XNOR: return ADD_XNOR_GATE_2;
				case ITM_AND3: return ADD_AND_GATE_3;
				case ITM_NOR3: return ADD_NOR_GATE_3;
				case ITM_XOR3: return ADD_XOR_GATE_3;
				case ITM_Switch: return ADD_Switch;
				case ITM_LED: return ADD_LED;
				case ITM_CONNECTION: return ADD_CONNECTION;
				case ITM_BACK: return BACK;

				default: return DSN_TOOL;	//A click on empty place in desgin toolbar
				}
			}
		}


		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		if (y >= 0 && y < UI.ToolBarHeight) {
			//checking order of th clicked item
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//switch case for simulation bar
			switch (ClickedItemOrder)
			{
			case ITM_TRUTH: return Create_TruthTable;
			case ITM_PROBE: return CIRCT_PROBE;
			case ITM_SWTCHTODSGN: return DSN_MODE;
			case ITM_SWTCHTCHANGE: return Change_Switch;

			default: return SIM_TOOL;	//A click on empty place in simulation toolbar
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		return STATUS_BAR;
		//return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}


Input::~Input()
{
}
