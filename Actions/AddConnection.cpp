#include "AddConnection.h"
#include "../ApplicationManager.h"
#include"../Components/Gate.h"

AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp)
{
	Psrcpin = NULL;
	Pdstpin = NULL;
}

AddConnection::~AddConnection(void)
{
}

void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click to add the connection");

	//Wait for User Input
	pIn->GetPointClicked(x1, y1);
	Gate* getsrcgate = (Gate*)pManager->find(x1, y1);
	if (getsrcgate != NULL)
	{
		getsrcgate->setoutputpincordns(sx1, sy1);
		Psrcpin = getsrcgate->getoutputpin();
	}
	else
	{
		pOut->ClearStatusBar();
		pOut->PrintMsg("Invalid output pin ,operation is cancelled");
	}


	pIn->GetPointClicked(x2, y2);
	Gate* getdstgate = (Gate*)pManager->find(x2, y2);
	if (getdstgate != NULL)
	{
		Pdstpin = getdstgate->getinputpin();
		Pdstpin->getcordns(dx2, dy2);
	}
	else if (getdstgate == NULL)
	{
		pOut->ClearStatusBar();
		pOut->PrintMsg("Invalid input pin ,operation is cancelled");
	}

	else if (getsrcgate == getdstgate)
	{
		Pdstpin = NULL;
	}

	pOut->ClearStatusBar();
}

void AddConnection::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	if (Psrcpin != NULL && Pdstpin != NULL)
	{

		//Calculate the rectangle Corners
		int Len = UI.AND3_Width;
		int Wdth = UI.AND2_Height;

		GraphicsInfo GInfo; //Gfx info to be used to construct the AND3 gate

		GInfo.x1 = sx1;
		GInfo.y1 = sy1;
		GInfo.x2 = dx2;
		GInfo.y2 = dy2;
		Connection* pA = new Connection(GInfo, Psrcpin, Pdstpin);
		Psrcpin->ConnectTo(pA);
		Pdstpin->ConnectTo(pA);
		pManager->AddComponent(pA);
	}
}

void AddConnection::Undo()
{}

void AddConnection::Redo()
{}
