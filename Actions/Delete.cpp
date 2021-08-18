#include "Delete.h"
#include"../ApplicationManager.h"
#include"../Components/Connection.h"

Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{
}

Delete::~Delete(void)
{
}

void Delete::ReadActionParameters()
{
	//Get a Pointer to the Output & Input Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Check if there is any selected component to delete
	if (pManager->GetSelected()==NULL) {
		pOut->PrintMsg("Error: Must select a component first");
		IsPossible = false;
	}
	else {
		IsPossible = true;
	}

}

void Delete::Execute()
{
	ReadActionParameters();
	if (IsPossible) {

		//deleting the connections associated with the gate
		if (pManager->GetSelected()->GetComponentType() != COMP_CONNECTION) {
			pManager->DeleteConnections(pManager->GetSelected());

		}
		//freeing the input and output pins if the deleted component is a connection
		if (pManager->GetSelected()->GetComponentType() == COMP_CONNECTION) {
			((Connection*)pManager->GetSelected())->DeleteConnection();
		}

		//deleting the component from application manager's component list
		pManager->DeleteComponent(pManager->GetSelected());

		//this line deallocates the component iff it is not copied/cut (exists in clipboard), if it is cut then it is deallocated after the pasting
		if (pManager->GetClipboard()!=pManager->GetSelected()) {
				delete pManager->GetSelected();
		}
	}
}

void Delete::Undo()
{
}

void Delete::Redo()
{
}

void Delete::DeallocateClipboard()
{
	bool stillexist = pManager->IsInCompList(pManager->GetClipboard());
	if (!stillexist) {
		delete pManager->GetClipboard();
		pManager->SetClipboard(NULL);
	}
}
