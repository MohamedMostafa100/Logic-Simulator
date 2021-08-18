#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component

	bool IsSelected; //true if the component is selected,and the component is then drawn highlighted
	int thisID;//ID for each component
public:
	static int ID;
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	
	
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual void save(ofstream&,int=0)=0;
	virtual void load(ifstream&,Component*,Component*)=0;

	//pure virtual function returns an enum that indicates the type of component
	virtual ComponentType GetComponentType()=0;

	//non-virtual getters and setters for IsSelected data member
	bool GetIsSelected();
	void SetIsSelected(bool);

	//pure virtual function InsideArea
	virtual bool InsideArea(int, int)=0;

	//non-virtual function , ID setters and getters
	int GetID();
	void SetID(int=-1);

	//////////////////////////////////////////////////
	virtual GraphicsInfo getGfxInfo();

	string getm_Label();     // get the label of the component
	void setm_Label(string EnteredLabel);   //set the label of the component
	void draw_label(Output*);//draws the label to the window
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
