#include "AddORgate2.h"
#include "..\ApplicationManager.h"

AddORgate2::AddORgate2(ApplicationManager *pApp):Action(pApp)
{
}

AddORgate2::~AddORgate2(void)
{
}

void AddORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input OR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void AddORgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len = UI.OR2_Width;
	int Wdth = UI.OR2_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the OR2 gate
	
	if ((Cy > UI.ToolBarHeight + (UI.OR2_Height / 2)) && (Cy < (UI.height - UI.StatusBarHeight - UI.OR2_Height / 2)))
	{
		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		OR2* pA = new OR2(GInfo, OR2_FANOUT);
		pManager->AddComponent(pA);
	}
}

void AddORgate2::Undo()
{}

void AddORgate2::Redo()
{}
