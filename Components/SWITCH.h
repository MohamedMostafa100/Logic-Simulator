#ifndef _switch_H
#define _switch_H

/*
  Class switch
  -----------
  represent the 1-input switch gate
*/

#include "Gate.h"

class SWITCH:public Gate
{
private:
	bool IsClosed;
public:
	SWITCH(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	SWITCH();
	virtual void Operate();	//Calculates the output of the switch 
	virtual void Draw(Output* pOut);	//Draws 1-input switch

	virtual int GetOutPinStatus();	//returns status of outputpin if switch, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if switch, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual ComponentType GetComponentType();
	virtual void setoutputpincordns(int& x, int& y);
	virtual void SetInputPinCoordinates();

	void setOuputPinStatus(STATUS s);



};

#endif