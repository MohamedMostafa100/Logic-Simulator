#include "AddBuffergate.h"
#include "..\ApplicationManager.h"

AddBuffergate::AddBuffergate(ApplicationManager *pApp):Action(pApp)
{
}

AddBuffergate::~AddBuffergate(void)
{
}

void AddBuffergate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("1-Input Buffer Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void AddBuffergate::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len = UI.Buffer_Width;
	int Wdth = UI.Buffer_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the Buffer gate
	

	if ((Cy > UI.ToolBarHeight + (UI.Buffer_Height / 2)) && (Cy < (UI.height - UI.StatusBarHeight - UI.Buffer_Height / 2)))
	{
		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		Buffer* pA = new Buffer(GInfo, Buffer_FANOUT);
		pManager->AddComponent(pA);
	}
}

void AddBuffergate::Undo()
{}

void AddBuffergate::Redo()
{}

