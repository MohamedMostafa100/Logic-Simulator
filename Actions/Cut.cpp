#include "Cut.h"
#include"Delete.h"
#include"Copy.h"
#include"../ApplicationManager.h"

Cut::Cut(ApplicationManager* pApp):Action(pApp)
{
}

Cut::~Cut(void)
{
}

void Cut::ReadActionParameters()
{
	//Get a Pointer to the Output & Input Interfaces
	Output* pOut = pManager->GetOutput();

	if (pManager->GetSelected() == NULL) {
		pOut->PrintMsg("Error :Must select component first");
		IsPossible = false;
	}
	else if (pManager->GetSelected()->GetComponentType() != COMP_CONNECTION) {
		IsPossible = true;
	}
	else if (pManager->GetSelected()->GetComponentType() == COMP_CONNECTION) {
		pOut->PrintMsg("Error :Action Not Available for Connections");
		IsPossible = false;
	}
}

//the execution of cut is the execution of copy followed by delete
void Cut::Execute()
{
	ReadActionParameters();
	if (IsPossible) {
		Delete delselected(pManager);
		Copy cpyselected(pManager);
		cpyselected.Execute();
		delselected.Execute();
	}
}



void Cut::Undo()
{
}

void Cut::Redo()
{
}
