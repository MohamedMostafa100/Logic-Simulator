#pragma once
#include"../Actions/Action.h"
#include"../ApplicationManager.h"
#include "../Components/SWITCH.h"

class Simulate : public Action
{
private:
	SWITCH** cswitch;
	int numberofswitches;
public:
	Simulate(ApplicationManager* pApp);	//constructor

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
};

