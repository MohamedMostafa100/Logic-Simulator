#pragma once
#include "Action.h"
class Cut : public Action
{
private:
	bool IsPossible;
public:
	Cut(ApplicationManager* pApp);
	virtual ~Cut(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

