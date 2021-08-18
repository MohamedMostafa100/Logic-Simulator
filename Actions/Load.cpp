#include "Load.h"
#include<iostream>
#include<fstream> //library for saving and loading to files
using namespace std;


Load::Load(ApplicationManager* pApp):Action(pApp)
{
}

Load::~Load(void)
{
}

void Load::ReadActionParameters()
{
	//creating pointer to input & output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string str;
	filename= pIn->GetString(pOut, "Action: Load, Enter File name: ", str);
}

void Load::Execute()
{
	int NoOfComp;
	Output* pOut = pManager->GetOutput();
	//creating and opening file
	ifstream file;
	//calling the ReadActionParameters function
	ReadActionParameters();
	pOut->ClearStatusBar();
	//opening the file to be read from
	file.open(filename+".txt", ios::in);
	//checking if the name is correct and the file has been opened
	if (file.is_open()) {
		//calling the load function in appmanager
		pManager->appLoad(file);
		//closing the file
		file.close();
	}
	else {
		pOut->PrintMsg("Error! File Not Found");
	}

}

void Load::Undo()
{
}


void Load::Redo()
{
}

