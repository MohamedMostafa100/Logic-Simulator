#include "ChangeSwitch.h"
#include "..\ApplicationManager.h"
#include "Simulate.h"

ChangeSwitch::ChangeSwitch(ApplicationManager* pApp) :Action(pApp)
{
	cswitch = NULL;
}

ChangeSwitch::~ChangeSwitch(void)
{
}

void ChangeSwitch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Click to change switch status");

	//Wait for User Input
		pIn->GetPointClicked(x, y);
		cswitch = dynamic_cast<SWITCH*>(pManager->find(x, y));

}

void ChangeSwitch::Execute()
{
	Output* pOut = pManager->GetOutput();
	Action* pAct = NULL;
	ReadActionParameters();
		if (cswitch != NULL)
		{
			if (cswitch->GetOutPinStatus() == LOW)
			{
				cswitch->setOuputPinStatus(HIGH);
				pOut->PrintMsg("Switch is now closed");
			}
			else
			{
				cswitch->setOuputPinStatus(LOW);
				pOut->PrintMsg("Switch is now open");
			}
		}
		pAct = new Simulate(pManager);
		pAct->Execute();
		delete pAct;
		pAct = NULL;
}

void ChangeSwitch::Undo()
{}

void ChangeSwitch::Redo()
{}

void ChangeSwitch::load()
{

}