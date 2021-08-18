#include "Exit.h"
#include<iostream>
#include"../ApplicationManager.h"
using namespace std;

Exit::Exit(ApplicationManager* pApp) : Action(pApp)
{

}

void Exit::ReadActionParameters()
{
}

void Exit::Execute()
{
	//creating pointer to input & output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Action: Exit , Click Anywhere to exit");
	int x, y;
	pIn->GetPointClicked(x,y);


}

void Exit::Undo()
{
	return;
}

void Exit::Redo()
{
	return;
}
