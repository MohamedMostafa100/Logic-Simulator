#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType
{
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_AND_GATE_3,		//Add 3-input AND gate
	ADD_NOR_GATE_3,		//Add 3-input NOR gate
	ADD_XOR_GATE_3,		//Add 3-input XOR gate
	ADD_Switch,			//Add Switch
	ADD_LED,			//Add LED
	ADD_CONNECTION,		//Add Wire Connection

	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection

	Create_TruthTable,	//Create Truth Table of the Circuit

	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT_ICON, //the select icon in design menu

	SELECT,		//Select a Component, a Connection
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	COPY,       //copy a component
	PASTE,      //paste a component
	CUT,        //cut a component

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode
	ADDGATE_Menu,  //draws the addgate menu
	BACK,			//switch to design bar from addgate bar

	EXIT,		//Exit the application

	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar



	//*simulation toolbar actions
	CIRCT_PROBE, //select circuit probe
	SIM_TOOL, //A click on an empty place in the simulation tool bar

};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

enum DSGNMODE //to specify which bar is used during design mode
{
	ADDGATE, //when the "add component" toolbar is displayed
	EDITCIRCT //when the original design toolbar is displayed (default)
};



enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_ADD,		  //add gates icon in menu
	ITM_SAVE,         //save item in menu
	ITM_LOAD,         // load item from menu
	ITM_ADDLABEL,     //add label to a component
	ITM_EDITLABEL,    //edit a component's label
	ITM_SELECT,       //select a component
	ITM_MOVE,         //Move a component
	ITM_COPY,		  //Copy a component
	ITM_PASTE,        //Paste a component
	ITM_CUT,		  //Cut a component
	ITM_DELETE,       //Delete a component
	ITM_UNDO, //undo last action
	ITM_REDO, //redo last action
	ITM_SwitchToSimulation, //SwitchToSimulation item in menu
	ITM_EXIT,		//Exit item
	//TODO: Add more items names here

	ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum

};

enum GatesMenuItem //items in the Add gate menu 
{
	ITM_AND2,		//AND gate item in menu
	ITM_OR2,		//OR gate item in menu
	ITM_NAND,       //NAND gate item in menu
	ITM_NOR,        //NOR gate item in menu
	ITM_XOR,        //XOR gate item in menu
	ITM_XNOR,       //XNOR gate item in menu
	ITM_AND3,       //AND3 gate item in menu
	ITM_NOR3,       //NOR3 gate item in menu
	ITM_XOR3,       //XOR3 gate item in menu
	ITM_Switch,     //Switch   item in menu
	ITM_LED,        //LED  item in menu
	ITM_CONNECTION,  //CONNECTION  item in menu
	ITM_Buffer,        //Buffer gate item in menu
	ITM_INV,          //INV  gate item in menu
	ITM_BACK,          //switch back to design bar


	ITM_ADD_CNT       //no. of add gate menu items
};


enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	ITM_TRUTH,	//Truth table menu item
	ITM_PROBE, //Circuit probing menu item
	ITM_SWTCHTODSGN, //Switch to design mode menu item
	ITM_SWTCHTCHANGE, //Change the switch state (open->close/close->open)



	//TODO:Add more items names here

	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum

};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT = 5,	//Default fan out of 2-input AND gate
	OR2_FANOUT = 5,
	AND3_FANOUT = 5,
	Inverter_FANOUT = 5,
	Buffer_FANOUT = 5,
	NAND2_FANOUT = 5,
	NAND3_FANOUT = 5,
	NOR2_FANOUT = 5,
	NOR3_FANOUT = 5,
	XOR2_FANOUT = 5,
	XOR3_FANOUT = 5,
	XNOR2_FANOUT = 5,
	XNOR3_FANOUT = 5,
	LED_FANOUT = 0,
	switch_FANOUT = 5
};

//A structure to contain drawing parameters for each component
//Each component occupies a rectangluar area so it needs 2 points to represent that area
//this structure can be extended if desired
struct GraphicsInfo
{
	int x1, y1, x2, y2;
};



//Component type enum for save, load and paste actions
enum ComponentType 
{
	COMP_CONNECTION,  //CONNECTION component
	COMP_AND2,		//AND gate component
	COMP_OR2,		//OR gate component
	COMP_NAND,       //NAND gate component
	COMP_NOR,        //NOR gate component
	COMP_XOR,        //XOR gate component
	COMP_XNOR,       //XNOR gate component
	COMP_AND3,       //AND3 gate component
	COMP_NOR3,       //NOR3 gate component
	COMP_XOR3,       //XOR3 gate component
	COMP_Switch,     //Switch component
	COMP_LED,        //LED component
	COMP_Buffer,        //Buffer gate component
	COMP_Inverter,       //inverter gate component
};

#ifndef NULL
#define NULL 0
#endif

#endif