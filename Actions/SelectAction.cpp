#include "SelectAction.h"
#include"../ApplicationManager.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{
}

SelectAction::~SelectAction(void)
{
}

void SelectAction::ReadActionParameters()
{	
	//Get a Pointer to the Output & Input Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Select A Component");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void SelectAction::Execute()
{
	//deselects any selected item before the user can select another
	pManager->Deselect();
	//updating interface so that the deselect action can be reflected in the window before the selection of another component
	pManager->UpdateInterface();
	ReadActionParameters();
	pManager->SelectComponent(Cx, Cy);

}

void SelectAction::Undo()
{
}

void SelectAction::Redo()
{
}
