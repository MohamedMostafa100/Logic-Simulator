#include "Save.h"
#include<iostream>
#include<fstream> //library for saving and loading to files
using namespace std;

Save::Save(ApplicationManager* pApp):Action(pApp)
{
}

void Save::ReadActionParameters()
{
	//creating pointer to input & output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string str;
	filename=pIn->GetString(pOut, "Action: Save, Enter File name: ", str);
}

void Save::Execute()
{
	Output* pOut = pManager->GetOutput();
	//creating and opening file
	ofstream file;
	//calling the read action parameters function
	ReadActionParameters();
	pOut->ClearStatusBar();
	file.open(filename+".txt",ios::out);
	//calling the save function of application manager
	pManager->appSave(file);
	file.close();

}

void Save::Undo()
{
	return;
}

void Save::Redo()
{
	return;
}
