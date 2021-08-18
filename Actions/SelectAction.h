#pragma once
#include"Action.h"

class SelectAction : public Action
{
private:
	int Cx, Cy;	//Clicked point on the window
public:
	SelectAction(ApplicationManager* pApp);
	virtual ~SelectAction(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

