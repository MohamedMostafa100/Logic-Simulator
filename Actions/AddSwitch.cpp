#include "Addswitch.h"
#include "..\ApplicationManager.h"

Addswitch::Addswitch(ApplicationManager *pApp):Action(pApp)
{
}

Addswitch::~Addswitch(void)
{
}

void Addswitch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("switch: Click to add the switch");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void Addswitch::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len = UI.switch_Width;
	int Wdth = UI.switch_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the switch
	
	if ((Cy > UI.ToolBarHeight + (UI.switch_Height / 2)) && (Cy < (UI.height - UI.StatusBarHeight - UI.switch_Height / 2)))
	{
		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		SWITCH* pA = new SWITCH(GInfo, switch_FANOUT);
		pManager->AddComponent(pA);
	}
}

void Addswitch::Undo()
{}

void Addswitch::Redo()
{}

