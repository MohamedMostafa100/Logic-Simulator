#include "Edit.h"
#include "../Actions/AddLable.h"
#include "../ApplicationManager.h"
#include "../Components/Component.h"
#include "../Components/Connection.h"
#include"../Components/Gate.h"


Edit::Edit(ApplicationManager* pApp) :Action(pApp)
{

}
Edit::~Edit(void)
{
}
void Edit::ReadActionParameters()
{

}
void Edit::Execute()
{

	if (pManager->GetSelected()->GetComponentType() != COMP_CONNECTION)
	{
		//edit Label
		AddLabel obj1(pManager);
		obj1.Execute();
		ReadActionParameters();
	}
	else if (pManager->GetSelected()->GetComponentType() == COMP_CONNECTION)
	{
		//edit connection
		//Get a Pointer to the Output / Input Interfaces
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();
		//pOut->PrintMsg("Please Enter 1(to change source pin) or 2(to change distination pin):");
		string str;
		string name;
		name = pIn->GetString(pOut, "Action: Edit A Connection, Enter a number 1 or 2 (1 to change src pin & 2 to change dst pin): ", str);
		pOut->ClearStatusBar();

		if (name == "1")
		{
			// TO CHANGE SOURCE PIN
			pOut->PrintMsg("Choose Gate");
			pIn->GetPointClicked(x, y);
			Component* getsrcgate2 = pManager->find(x, y);
			OutputPin* PsourcePin2 = ((Gate*)getsrcgate2)->getoutputpin();
			((Connection*)pManager->GetSelected())->setSourcePin(PsourcePin2);
			int z, w;
			((Gate*)getsrcgate2)->setoutputpincordns(z, w);
			((Connection*)pManager->GetSelected())->SetSrcPinCrds(z, w);
		}
		else if (name == "2")
		{
			// TO CHANGE DISTINATION PIN
			pOut->PrintMsg("Choose Gate");
			pIn->GetPointClicked(x, y);
			Gate* getsrcgate2 = (Gate*)pManager->find(x, y);
			InputPin* Pdispin2 = getsrcgate2->getinputpin();
			int num = getsrcgate2->GetCurrentPinNum();
			int w, z;
			InputPin* pin = getsrcgate2->m_InputPins;
			pin[num].getcordns(w, z);
			((Connection*)pManager->GetSelected())->setDestPin(Pdispin2);
			((Connection*)pManager->GetSelected())->SetDstPinCrds(w, z);
		}
	}

}
void Edit::Undo()
{}
void Edit::Redo()
{}