#pragma once
#include "Action.h"

class BackToDesignbar :public Action
{
public:
	BackToDesignbar(ApplicationManager* pApp);
	virtual ~BackToDesignbar(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

