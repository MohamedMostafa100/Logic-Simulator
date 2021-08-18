#pragma once
#include "..\Defs.h"
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output(); // Performs the Window Initialization
	Input* CreateInput() const; //creates a pointer to the Input object
	void ChangeTitle(string Title) const;

	void CreateDesignToolBar() const;	//Tool bar of the design mode
	void CreateSimulationToolBar() const;//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar

	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area

	//NEW FUNCTIONS
	void DeleteSimulationBar() const;
	void CreateAddGateToolBar() const; //Toolbar of Add Gate
	void PrintString(string, int, int) const; //to print a string onto the window

	window* CreateWind(int wd, int h, int x, int y) const; //Creates user interface window


	// Draws 2-input AND gate
	void DrawAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	// Draws 2-input NAND gate
	void DrawNAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	// Draws 2-input OR gate
	void DrawOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	// Draws 2-input NOR gate
	void DrawNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	// Draws 2-input XOR gate
	void DrawXOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	// Draws 2-input XNOR gate
	void DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	// Draws Buffer gate
	void DrawBuffer(GraphicsInfo r_GfxInfo, bool selected = false) const;
	// Draws Inverter gate
	void DrawInverter(GraphicsInfo r_GfxInfo, bool selected = false) const;
	// Draws 3-input AND gate
	void DrawAND3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	// Draws 3-input OR gate
	void DrawNOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	// Draws 3-input XOR gate
	void DrawXOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	// Draws Switch
	void DrawSwitch(GraphicsInfo r_GfxInfo, bool selected = false) const;
	// Draws LED
	void DrawLED(GraphicsInfo r_GfxInfo, bool selected = false) const;

	///TODO: Make similar functions for drawing all other gates, switch, and LED, .. etc

	// Draws Connection
	void DrawConnection(GraphicsInfo& r_GfxInfo, bool selected = false) const;

	void PrintMsg(string msg) const;	//Print a message on Status bar


	~Output();
};
