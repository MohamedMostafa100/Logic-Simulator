#pragma once

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "UI_Info.h"

class Output;
class Input		//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window

public:
	Input(window*);
	void GetPointClicked(int&, int&);	//Get coordinate where user clicks
	string GetString(Output* pOut, string msg, string str = " ")const;		//Returns a string entered by the user

	ActionType GetUserAction() const; //Reads the user click and maps it to an action

	///////////////
	//store user string (for getting the file name in the save action)
	string StoreString(Output* pOut, string msg, string str = " ");

	~Input();
};

