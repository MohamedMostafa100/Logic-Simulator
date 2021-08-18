#include "AddLable.h"
#include "../ApplicationManager.h"
#include "../Components/Component.h"

AddLabel::AddLabel(ApplicationManager* pApp) :Action(pApp)
{
}
AddLabel::~AddLabel(void)
{}
void AddLabel::ReadActionParameters()
{
	//Get a Pointer to the Output / Input Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string str;
	string name;

	if (pManager->GetSelected() != NULL)
	{
		name=pIn->GetString(pOut, "Action: Add A Label, Enter component name: ", str);
		pManager->GetSelected()->setm_Label(name);
		pOut->ClearStatusBar();
		
	}
	else
	{
		//Print Action Message
		pOut->PrintMsg("ERROR: please,select a component");
	}
}
void AddLabel::Execute()
{
	ReadActionParameters();
}
void AddLabel::Undo()
{}

void AddLabel::Redo()
{}