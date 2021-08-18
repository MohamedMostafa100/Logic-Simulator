#include "Simulate.h"



Simulate::Simulate(ApplicationManager* pApp) :Action(pApp) {

}

void Simulate::ReadActionParameters()
{
}

void Simulate::Execute()
{
	//creating pointer to input & output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Action: Simulation Mode");
	//drawing simualtion toolbar
	pOut->CreateSimulationToolBar();
	cswitch = pManager->getswitchlist(numberofswitches);
	for (int i = 0; i < numberofswitches; i++)
	{
		cswitch[i]->Operate();
	}
}

void Simulate::Undo()
{
}

void Simulate::Redo()
{
}