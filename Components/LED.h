#ifndef _LED_H
#define _LED_H

/*
  Class LED
  -----------
  represent the 1-input LED gate
*/

#include "Gate.h"

class LED:public Gate
{
public:
	LED(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	//default constructor
	LED();
	virtual void Operate();	//Calculates the output of the LED 
	virtual void Draw(Output* pOut);	//Draws 1-input LED

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if switch, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual ComponentType GetComponentType();
	virtual void setoutputpincordns(int& x, int& y);
	virtual void SetInputPinCoordinates();


};

#endif