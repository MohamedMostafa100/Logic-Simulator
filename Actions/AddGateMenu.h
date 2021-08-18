#pragma once

#include "action.h"

class AddGateMenu : public Action
{

	public:
		AddGateMenu(ApplicationManager* pApp);
		virtual ~AddGateMenu(void);

		//Reads parameters required for action to execute
		virtual void ReadActionParameters();
		//Execute action (code depends on action type)
		virtual void Execute();

		virtual void Undo();
		virtual void Redo();


	};


