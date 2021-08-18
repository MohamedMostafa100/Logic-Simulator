#pragma once
#include "Action.h"
#include"../Components/Component.h"

class Delete :public Action
{
private: bool IsPossible;
public:
	Delete(ApplicationManager* pApp);
	virtual ~Delete(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	
	//responsible for deallocating the clipboard after paste in case of cut
	void DeallocateClipboard();
};

