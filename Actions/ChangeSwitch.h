#ifndef _CHANGE_SWITCH_H
#define _CHANGE_SWITCH_H

#include "action.h"
#include "../Components/SWITCH.h"
class ChangeSwitch : public Action
{
private:
	int x, y;
	SWITCH* cswitch;
public:
	ChangeSwitch(ApplicationManager* pApp);
	virtual ~ChangeSwitch(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	void load();

};

#endif