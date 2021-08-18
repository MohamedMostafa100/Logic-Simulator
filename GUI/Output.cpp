#include "Output.h"

Output::Output()
{
	UI.AppMode = DESIGN;	//Design Mode is the startup mode
	UI.DesignToolbar = EDITCIRCT; //the default toolbar 


	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = YELLOW;
	UI.ConnColor = RED;
	UI.MsgColor = BLACK;
	UI.BkGrndColor = WHITE;
	UI.EmptyToolbarColor = LIGHTBLUE;
	UI.LinesColor = LIGHTBLUE;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}

//////////////////////////////////////////////////////////////////////////////////
///NEW FUNCTION

void Output::DeleteSimulationBar() const { //erases the simulation bar
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}


//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.LinesColor, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.EmptyToolbarColor);
	pWind->SetBrush(UI.EmptyToolbarColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(UI.LinesColor, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode
	UI.DesignToolbar = EDITCIRCT; //indicates that the default design mode toolbar is drawn
	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];

	MenuItemImages[ITM_ADD] = "images\\Menu\\Menu_ADD.jpg";
	MenuItemImages[ITM_ADDLABEL] = "images\\Menu\\Menu_AddLabel.jpg";
	MenuItemImages[ITM_EDITLABEL] = "images\\Menu\\MENU_EditLabel.jpg";
	MenuItemImages[ITM_SELECT] = "images\\Menu\\MENU_Select.jpg";
	MenuItemImages[ITM_MOVE] = "images\\Menu\\Menu_Move.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\Menu_load.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\Menu_save.jpg";
	MenuItemImages[ITM_COPY] = "images\\Menu\\Menu_Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\Menu\\Menu_Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Menu\\Menu_Paste.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Menu\\Menu_Delete.jpg";
	MenuItemImages[ITM_SwitchToSimulation] = "images\\Menu\\Menu_switch to simulation.jpg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\Menu_UNDO.jpg";
	MenuItemImages[ITM_REDO] = "images\\Menu\\Menu_REDO.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";



	//TODO: Prepare image for each menu item and add it to the list
	//To make the BG color of the bar Gray
	pWind->SetPen(UI.EmptyToolbarColor, 1);
	pWind->SetBrush(UI.EmptyToolbarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(UI.LinesColor, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

////////////////////////////////////////////////////////////////////////////
// Draws the "add gate" menu
void Output::CreateAddGateToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode
	UI.DesignToolbar = ADDGATE; //indicates that the "add component" toolbar is drawn
	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_ADD_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_OR2] = "images\\Menu\\Menu_OR2.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";
	MenuItemImages[ITM_NAND] = "images\\Menu\\Menu_NAND.jpg";
	MenuItemImages[ITM_NOR] = "images\\Menu\\Menu_NOR.jpg";
	MenuItemImages[ITM_XOR] = "images\\Menu\\Menu_XOR.jpg";
	MenuItemImages[ITM_XNOR] = "images\\Menu\\Menu_XNOR.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\Menu_AND3.jpg";
	MenuItemImages[ITM_NOR3] = "images\\Menu\\Menu_NOR3.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\Menu_XOR3.jpg";
	MenuItemImages[ITM_Switch] = "images\\Menu\\Menu_Switch.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\Menu_LED.jpg";
	MenuItemImages[ITM_CONNECTION] = "images\\Menu\\Menu_CONNECTION.jpg";
	MenuItemImages[ITM_Buffer] = "images\\Menu\\Menu_Buff.jpg";
	MenuItemImages[ITM_INV] = "images\\Menu\\Menu_INV.jpg";
	MenuItemImages[ITM_BACK] = "images\\Menu\\Menu_Back.jpg";

	//TODO: Prepare image for each menu item and add it to the list
	//To make the BG color of the bar Gray
	pWind->SetPen(UI.EmptyToolbarColor, 1);
	pWind->SetBrush(UI.EmptyToolbarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_ADD_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(UI.LinesColor, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}


////////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintString(string text, int x, int y) const
{
	pWind->DrawString(x, y, text);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)

	//Prepare list of images for each menu item
	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[ITM_TRUTH] = "images\\Menu\\Menu_TRUTH.jpg";
	MenuItemImages[ITM_PROBE] = "images\\Menu\\Menu_PROBE.jpg";
	MenuItemImages[ITM_SWTCHTODSGN] = "images\\Menu\\Menu_SWTCHTODSGN.jpg";
	MenuItemImages[ITM_SWTCHTCHANGE] = "images\\Menu\\Menu_Switch.jpg";

	//makes the background color of the toolbar after the last element gray
	pWind->SetPen(UI.EmptyToolbarColor, 1);
	pWind->SetBrush(UI.EmptyToolbarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(UI.LinesColor, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, (UI.ToolItemWidth) * ITM_SIM_CNT, UI.ToolBarHeight);
	//draws a vertical line after the last item of the toolbar
	pWind->DrawLine((UI.ToolItemWidth) * ITM_SIM_CNT, 0, (UI.ToolItemWidth) * ITM_SIM_CNT, UI.ToolBarHeight);
}
//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	GateImage = "Images\\Gates\\selected NAND.jpg";
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\selected NAND.jpg";
	else
		GateImage = "Images\\Gates\\NAND.jpg";

	//Draw NAND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	GateImage = "Images\\Gates\\selected OR.jpg";
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\selected OR.jpg";
	else
		GateImage = "Images\\Gates\\OR.jpg";

	//Draw OR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	GateImage = "Images\\Gates\\selected NOR.jpg";
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\selected NOR.jpg";
	else
		GateImage = "Images\\Gates\\NOR.jpg";

	//Draw NOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	GateImage = "Images\\Gates\\selected XOR.jpg";
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\selected XOR.jpg";
	else
		GateImage = "Images\\Gates\\XOR.jpg";

	//Draw XOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	GateImage = "Images\\Gates\\selected XNOR.jpg";
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\selected XNOR.jpg";
	else
		GateImage = "Images\\Gates\\XNOR.jpg";

	//Draw XNOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawBuffer(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	GateImage = "Images\\Gates\\selected Buffer.jpg";
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\selected Buffer.jpg";
	else
		GateImage = "Images\\Gates\\Buffer.jpg";

	//Draw Buffer Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawInverter(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	GateImage = "Images\\Gates\\selected Inverter.jpg";
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\selected Inverter.jpg";
	else
		GateImage = "Images\\Gates\\Inverter.jpg";

	//Draw Inverter Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	GateImage = "Images\\Gates\\selected AND - 3.jpg";
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\selected AND - 3.jpg";
	else
		GateImage = "Images\\Gates\\AND - 3.jpg";

	//Draw AND3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	GateImage = "Images\\Gates\\selected NOR - 3.jpg";
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\selected NOR - 3.jpg";
	else
		GateImage = "Images\\Gates\\NOR - 3.jpg";

	//Draw NOR3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	GateImage = "Images\\Gates\\selected XOR - 3.jpg";
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\selected XOR - 3.jpg";
	else
		GateImage = "Images\\Gates\\XOR - 3.jpg";

	//Draw XOR3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawSwitch(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	GateImage = "Images\\Gates\\selected Switch.jpg";
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\selected Switch.jpg";
	else
		GateImage = "Images\\Gates\\Switch.jpg";

	//Draw Switch at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	GateImage = "Images\\Gates\\selected led.jpg";
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\selected led.jpg";
	else
		GateImage = "Images\\Gates\\led.jpg";

	//Draw LED at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


//TODO: Add similar functions to draw all components


void Output::DrawConnection(GraphicsInfo& r_GfxInfo, bool selected) const
{
	//TODO: Add code to draw connection
	color  c;
	if (selected)
	{
		c = UI.SelectColor;

	}
	else
	{
		c = UI.ConnColor;
	}
	pWind->SetPen(c, 2);

	int X1, X2, Y1, Y2;
	X1 = r_GfxInfo.x1;
	X2 = r_GfxInfo.x2;
	Y1 = r_GfxInfo.y1;
	Y2 = r_GfxInfo.y1;

	pWind->DrawLine(X1, Y1, X2, Y2);

	X1 = X2;
	Y2 = r_GfxInfo.y2;

	pWind->DrawLine(X1, Y1, X2, Y2);
}


Output::~Output()
{
	delete pWind;
}

