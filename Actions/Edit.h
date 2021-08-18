#pragma once
#include"Action.h"

	class Edit :public Action
	{
	private:
		int x, y;
	public:
		Edit(ApplicationManager* pApp);
		virtual ~Edit(void);

		//Reads parameters required for action to execute
		virtual void ReadActionParameters();
		//Execute action (code depends on action type)
		virtual void Execute();

		virtual void Undo();
		virtual void Redo();

};

