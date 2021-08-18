#include "AddGateMenu.h"
#include"../ApplicationManager.h"

AddGateMenu::AddGateMenu(ApplicationManager* pApp):Action(pApp)
{
}

AddGateMenu::~AddGateMenu(void)
{
}

void AddGateMenu::ReadActionParameters()
{
}

void AddGateMenu::Execute()
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("Action: Add Component");
	pOut->CreateAddGateToolBar();

}

void AddGateMenu::Undo()
{
}

void AddGateMenu::Redo()
{
}
