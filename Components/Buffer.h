#ifndef _Buffer_H
#define _Buffer_H

/*
  Class Buffer
  -----------
  represent the 1-input Buffer gate
*/

#include "Gate.h"

class Buffer:public Gate
{
public:
	Buffer(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	//default constructor
	Buffer();
	virtual void Operate();	//Calculates the output of the Buffer gate
	virtual void Draw(Output* pOut);	//Draws 1-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if switch, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual ComponentType GetComponentType();
	virtual void setoutputpincordns(int& x, int& y);
	virtual void SetInputPinCoordinates();

};

#endif