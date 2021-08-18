#include "Copy.h"
#include"../ApplicationManager.h"

Copy::Copy(ApplicationManager* pApp) :Action(pApp) 
{

}

Copy::~Copy(void)
{
}

void Copy::ReadActionParameters()
{
	//Get a Pointer to the Output & Input Interfaces
	Output* pOut = pManager->GetOutput();

	//Check if there is any selected component to delete
	if (pManager->GetSelected() == NULL) {
		pOut->PrintMsg("Error: Must select a component first");
		IsPossible = false;
	}
	//if the selected component is a connection
	else if (pManager->GetSelected()->GetComponentType() == COMP_CONNECTION ) {
		pOut->PrintMsg("Error :Action Not Available for Connections");
		IsPossible = false;
	}
	else {
		pOut->PrintMsg("Saved to Clipboard");
		IsPossible = true;
	}
}

void Copy::Execute()
{
		ReadActionParameters();
	if (IsPossible) {
	pManager->SetClipboard(pManager->GetSelected());//sets the clipboard with a pointer to the selected item
	}

}

void Copy::Undo()
{
}

void Copy::Redo()
{
}
