#ifndef SAVE_H
#define SAVE_H
#include "../Actions/Action.h"
#include"../ApplicationManager.h"

class Save: public Action
{
private:
	string filename;
public:
	Save(ApplicationManager* pApp); //constructor

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();


};

#endif

