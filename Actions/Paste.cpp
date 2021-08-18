#include "Paste.h"
#include"../ApplicationManager.h"
#include "../Actions/AddANDgate2.h"
#include "../Actions/AddORgate2.h"
#include "../Actions/AddANDgate3.h"
#include "../Actions/AddInvertergate.h"
#include "../Actions/AddBuffergate.h"
#include "../Actions/AddNANDgate2.h"
#include "../Actions/AddNORgate2.h"
#include "../Actions/AddNORgate3.h"
#include "../Actions/AddXORgate2.h"
#include "../Actions/AddXORgate3.h"
#include "../Actions/AddXNORgate2.h"
#include "../Actions/AddLED.h"
#include "../Actions/AddSWITCH.h"
#include"../Actions/Delete.h"

Paste::Paste(ApplicationManager* pApp): Action(pApp)
{
}

Paste::~Paste(void)
{
}

void Paste::ReadActionParameters()
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();

	//Check if there is any selected component to delete
	if (pManager->GetClipboard() == NULL) {
		pOut->PrintMsg("Error: Must copy/cut a component first");
		IsPossible = false;
	}
	else {
		IsPossible = true;
	}
}

void Paste::Execute()
{
	ReadActionParameters();
	Action* action = NULL;
	//creating a new object according to the object type of the item pointed to by clipboard, and adding the new object to the component list.
	//new object is placed at the point clicked by the user
	if (IsPossible) {
		switch (pManager->GetClipboard()->GetComponentType())
		{
		case(COMP_AND2):
			action = new AddANDgate2(pManager);
			break;

		case(COMP_AND3):
			action = new AddANDgate3(pManager);
			break;

		case(COMP_Buffer):
			action = new AddBuffergate(pManager);
			break;

		case(COMP_Inverter):
			action = new AddInvertergate(pManager);
			break;

		case(COMP_LED):
			action = new AddLED(pManager);
			break;

		case(COMP_NAND):
			action = new AddNANDgate2(pManager);
			break;

		case(COMP_NOR):
			action = new AddNORgate2(pManager);
			break;

		case(COMP_NOR3):
			action = new AddNORgate3(pManager);
			break;

		case(COMP_OR2):
			action = new AddORgate2(pManager);
			break;

		case(COMP_Switch):
			action = new Addswitch(pManager);
			break;

		case(COMP_XNOR):
			action = new AddXNORgate2(pManager);
			break;

		case(COMP_XOR):
			action = new AddXORgate2(pManager);
			break;

		case(COMP_XOR3):
			action = new AddXORgate3(pManager);
			break;
		}	
	action->Execute();
	Delete del(pManager);
	//setting the label of the old component to the new component

	//deallocating clipboard item after paste in case of cut
	del.DeallocateClipboard();
	delete action;
	}

	
}

void Paste::Undo()
{
}

void Paste::Redo()
{
}
