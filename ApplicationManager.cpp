#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddANDgate3.h"
#include "Actions\AddInvertergate.h"
#include "Actions\AddBuffergate.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddNORgate2.h"
#include "Actions\AddNORgate3.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddXORgate3.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddLED.h"
#include "Actions\AddSWITCH.h"
#include "Actions\Exit.h"
#include"Actions\Save.h"
#include"Actions\Simulate.h"
#include"Actions\AddGateMenu.h"
#include"Actions\BackToDesignbar.h"
#include"Actions\SelectAction.h"
#include"Actions\Delete.h"
#include"Actions\Copy.h"
#include"Actions\Paste.h"
#include"Actions\Cut.h"
#include"Actions\Load.h"
#include"Actions\AddConnection.h"
#include"Actions\AddLable.h"
#include"Actions\ChangeSwitch.h"
#include"Actions\Edit.h"
#include<fstream>


ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();

	clipboard = NULL; //default value
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}


/////////////////////////////////////////////////////////////////////
void ApplicationManager::appSave(ofstream& file)
{
	int gatecount=0;
	//getting gate count
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->GetComponentType() != COMP_CONNECTION) 
		{
			gatecount++;
		}
	}
	file << gatecount << endl;

	for (int i = 0; i < CompCount; i++) {
		//calling the save function for each component (gates first, so the integer data member is not passed and has an initial value of 0)
		CompList[i]->save(file);
	}
	for (int i = 0; i < CompCount; i++) {
		//calling the save function for each connections (the integer is passed as one to indicate that the connections are to be saved)
		CompList[i]->save(file,1);
	}
	file << -1 << endl;
}

/////////////////////////////////////////////////////////////////////

void ApplicationManager::appLoad(ifstream& file)
{
	//clearing the drawing area before loading the new components
	OutputInterface->ClearDrawingArea();
	int NoOfComp;
	int TypeofComp;
	//reading the number of components from file
	file >> NoOfComp;
	Component* comp;
	//in a for loop for each line
	for (int i = 0; i < NoOfComp; i++) {
		file >> TypeofComp;
		switch (TypeofComp) {
		case(COMP_AND2):
			comp = new AND2();
			break;

		case(COMP_AND3):
			comp = new AND3();
			break;

		case(COMP_Buffer):
			comp = new Buffer();
			break;

		case(COMP_Inverter):
			comp = new Inverter;
			break;

		case(COMP_LED):
			comp = new LED();
			break;

		case(COMP_NAND):
			comp = new NAND2();
			break;

		case(COMP_NOR):
			comp = new NOR2();
			break;

		case(COMP_NOR3):
			comp = new NOR3();
			break;

		case(COMP_OR2):
			comp = new OR2();
			break;

		case(COMP_Switch):
			comp = new SWITCH();
			break;

		case(COMP_XNOR):
			comp = new XNOR2();
			break;

		case(COMP_XOR):
			comp = new XOR2();
			break;

		case(COMP_XOR3):
			comp = new XOR3();
			break;
		}
		comp->load(file,NULL,NULL);
		AddComponent(comp);
	}

	//loading connections
	while (!file.eof()) {
		int SrcCmpntID;	
		file >> SrcCmpntID;
		if (SrcCmpntID != -1) {
			int DstCmpntID;
			file >> DstCmpntID;
			comp = new Connection();
			comp->load(file, FindUsingID(SrcCmpntID), FindUsingID(DstCmpntID));
			AddComponent(comp);
		}
	}
}

//////////////////////////////////////////////////////////////////////
//returns the selected component given a point (x,y) ,returns NULL pointer if no component is selected
void ApplicationManager::SelectComponent(int x, int y)
{
	for (int i=0; i < CompCount; i++) {
		if (CompList[i]->InsideArea(x, y)) {
			CompList[i]->SetIsSelected(true);
			break;
		}
	}
	return;
}

///////////////////////////////////////////////////////////////////////
//deselects the selected component ,if any
void ApplicationManager::Deselect() {

	for (int i = 0; i < CompCount; i++) {
		CompList[i]->SetIsSelected(false);
	}

}

////////////////////////////////////////////////////////////////////////
//returns a pointer to the selected item, otherwise returns null
Component* ApplicationManager::GetSelected()
{
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->GetIsSelected()) {
			return CompList[i];
		}
	}
	return NULL;
}


//////////////////////////////////////////////////////////////////////////
//Deleting a component from CompList
void ApplicationManager::DeleteComponent(Component* comp)
{			
	for (int i = 0; i < CompCount; i++) {
		if (comp == CompList[i]) {
//deleting the component from complist
	CompList[i] = NULL;
	CompList[i] = CompList[CompCount - 1];
	CompList[CompCount-1] = NULL;
	CompCount--;
		}
	}
}

//////////////////////////////////////////////////////////////////////////
//Deleting connection associated with a component
void ApplicationManager::DeleteConnections(Component*comp)
{
	int j = 0;
	//finding number of connections associated with the component
	Component** arr;
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->GetComponentType() == COMP_CONNECTION) {
			//if the connection is associated with the gate either at the input pin or the output pin it is deleted
			if (((Connection*)CompList[i])->GetDstCmpnt() == comp || ((Connection*)CompList[i])->GetSrcCmpnt() == comp)
			{
				j++;
			}
		}
	}
	//allocating then deleting an array of the connections associated to the component
	arr = new Component * [j];

	int k = 0;
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->GetComponentType() == COMP_CONNECTION) {
				//if the connection is associated with the gate either at the input pin or the output pin it is deleted
			if (((Connection*)CompList[i])->GetDstCmpnt() == comp || ((Connection*)CompList[i])->GetSrcCmpnt() == comp)
				{
					arr[k] = CompList[i];
					k++;
				}
			}
		}

	for (int i = 0; i < j; i++) {
		((Connection*)arr[i])->DeleteConnection();
		DeleteComponent(arr[i]);
		delete arr[i];
	}
	delete arr;
}


//////////////////////////////////////////////////////////////////////////
//clipboard setter, to be used when the copy / cut actions are invoked
void ApplicationManager::SetClipboard(Component* comp)
{
	clipboard = comp;
}


//////////////////////////////////////////////////////////////////////////
//clipboard getter, to be used when the paste action is invoked
Component* ApplicationManager::GetClipboard()
{
	return clipboard;
}

//////////////////////////////////////////////////////////////////////////
bool ApplicationManager::IsInCompList(Component*comp)
{
	bool IsInCompList=false;
	for (int i = 0; i < CompCount; i++) {
		if (comp == CompList[i]) {
			IsInCompList = true;
			break;
		}
	}
	return IsInCompList;
}

//////////////////////////////////////////////////////////////////////////
Component* ApplicationManager::FindUsingID(int id)
{
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->GetID() == id) {
			return CompList[i];
		}
	}
	return nullptr;
}


Component* ApplicationManager::find(int x, int y)
{
	for (int i = 0; i < CompCount; i++)
	{
		GraphicsInfo gfxinfo = CompList[i]->getGfxInfo();
		if ((CompList[i])->GetComponentType() != COMP_CONNECTION)
		{
			if (gfxinfo.x1<x && gfxinfo.x2>x && gfxinfo.y1<y && gfxinfo.y2>y)
				return CompList[i];
		}
	}
	return NULL;
}

////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;

		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;

		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(this);
			break;

		case ADD_INV:
			pAct = new AddInvertergate(this);
			break;

		case ADD_Buff:
			pAct = new AddBuffergate(this);
			break;

		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;

		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;

		case ADD_NOR_GATE_3:
			pAct = new AddNORgate3(this);
			break;

		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			break;

		case ADD_XOR_GATE_3:
			pAct = new AddXORgate3(this);
			break;

		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			break;

		case ADD_LED:
			pAct = new AddLED(this);
			break;

		case ADD_Switch:
			pAct = new Addswitch(this);
			break;

		case SAVE:
			pAct = new Save(this);
			break;

		case SIM_MODE:
			pAct = new Simulate(this);
			break;

		case ADDGATE_Menu:
			pAct = new AddGateMenu(this);
			break;
		
		case BACK:
			pAct = new BackToDesignbar(this);
			break;

		case DSN_MODE:
			pAct = new BackToDesignbar(this);
			break;

		case SELECT_ICON:
			pAct = new SelectAction(this);
			break;

		case DEL:
			pAct = new Delete(this);
			break;

		case COPY:
			pAct = new Copy(this);
			break;

		case PASTE:
			pAct = new Paste(this);
			break;

		case CUT:
			pAct = new Cut(this);
			break;

		case LOAD:
			pAct = new Load(this);
			break;

		case ADD_CONNECTION:
			pAct = new AddConnection(this);
			break;

		case ADD_Label:
			pAct = new AddLabel(this);
			break;

		case Change_Switch:
			pAct = new ChangeSwitch(this);
			break;

		case EDIT_Label:
			pAct = new Edit(this);
			break;

		case EXIT:
			pAct = new Exit(this);
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	//clear the previous drawing area before redrawing on top of it (eliminates the problem with the delete function)
		OutputInterface->ClearDrawingArea();
		for (int i = 0; i < CompCount; i++) {
			CompList[i]->Draw(OutputInterface);
			CompList[i]->draw_label(OutputInterface);
		}

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}

SWITCH** ApplicationManager::getswitchlist(int& c)
{
	SWITCH** listofswitches;
	int count = 0;
	for (int i = 0; i < CompCount; i++)
	{
		if (dynamic_cast<SWITCH*>(CompList[i]))
		{
			count++;
		}
	}
	c = count;
	int j = 0;
	listofswitches = new SWITCH * [count];
	for (int i = 0; i < CompCount; i++)
	{
		if (dynamic_cast<SWITCH*>(CompList[i]))
		{
			listofswitches[j] = (SWITCH*)CompList[i];
			j++;
		}
	}
	return listofswitches;
}