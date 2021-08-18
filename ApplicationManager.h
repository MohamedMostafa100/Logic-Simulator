#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Components/SWITCH.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	Component* clipboard; //component pointer used in the copy, paste and cut actions

	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface


public:


public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	////////////////////////////////////////////////////
	//Save function
	void appSave( ofstream& );
	//Load function
	void appLoad(ifstream&);

	///////////////////////////////////////////////////
	//Select Component function , returns a pointer to the selected component given the point clicked as an argument
	void SelectComponent(int, int);

	///////////////////////////////////////////////////
	//Deselects the selected component
	void Deselect();

	///////////////////////////////////////////////////
	//returns a pointer to the selected (highlighted) component
	Component* GetSelected();
	
	///////////////////////////////////////////////////
	//passed a component pointer as an argument and deletes the component it points to from its component list
	void DeleteComponent(Component*);
	//deletes the connections associated with the passed component
	void DeleteConnections(Component*);

	///////////////////////////////////////////////////
	//clipboard setter & getter
	void SetClipboard(Component*); //takes the index of the selected item
	Component* GetClipboard();

	///////////////////////////////////////////////////
	//takes a pointer to component and returns true if the component exists in component list 
	bool IsInCompList(Component*);
	//////////////////////////////////////////////////
	//finds the component whose id is passed as a parameter
	Component* FindUsingID(int);

	///////////////////////////////////////////////////
	Component* find(int x, int y);
	SWITCH** getswitchlist(int& c);

	///////////////////////////////////////////////////
	//destructor
	~ApplicationManager();
};

#endif