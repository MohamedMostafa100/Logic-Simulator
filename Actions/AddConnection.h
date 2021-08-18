#ifndef _ADD_CONNECTION_H
#define _ADD_CONNECTION_H

#include "Action.h"
#include "../Components/Connection.h"

class AddConnection : public Action
{
private:
	int x1, y1, x2, y2;	
	int sx1, sy1, dx2, dy2;
	OutputPin* Psrcpin;
	InputPin* Pdstpin;
public:
	AddConnection(ApplicationManager* pApp);
	virtual ~AddConnection(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
