#include "BackToDesignbar.h"
#include"../ApplicationManager.h"

BackToDesignbar::BackToDesignbar(ApplicationManager* pApp) :Action(pApp)
{
}

BackToDesignbar::~BackToDesignbar(void)
{
}

void BackToDesignbar::ReadActionParameters()
{
}

void BackToDesignbar::Execute()
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("Action: Back to circuit editing");
	pOut->CreateDesignToolBar();	
}

void BackToDesignbar::Undo()
{
}

void BackToDesignbar::Redo()
{
}
