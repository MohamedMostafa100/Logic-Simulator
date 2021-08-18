#pragma once
#include "Action.h"
#include"../ApplicationManager.h"
class Load :
    public Action
{
private:
	string filename;
public:
	Load(ApplicationManager* pApp);
	virtual ~Load(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

