#include "AddInvertergate.h"
#include "..\ApplicationManager.h"

AddInvertergate::AddInvertergate(ApplicationManager *pApp):Action(pApp)
{
}

AddInvertergate::~AddInvertergate(void)
{
}

void AddInvertergate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("1-Input Inverter Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void AddInvertergate::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len = UI.Inverter_Width;
	int Wdth = UI.Inverter_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the Inverter gate
	
	if ((Cy > UI.ToolBarHeight + (UI.Inverter_Height / 2)) && (Cy < (UI.height - UI.StatusBarHeight - UI.Inverter_Height / 2)))
	{
		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		Inverter* pA = new Inverter(GInfo, Inverter_FANOUT);
		pManager->AddComponent(pA);
	}
}

void AddInvertergate::Undo()
{}

void AddInvertergate::Redo()
{}

