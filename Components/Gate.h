#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Gate:public Component
{
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.
	int CurrentPinNum;  //the number of the current pin
public:
	friend void Edit::Execute();
	Gate(int r_Inputs, int r_FanOut);

	InputPin* getinputpin();
	//overloading the getinputpin function that takes the pin number and returns a pointer to the corresponding pin
	InputPin* getinputpin(int);
	OutputPin* getoutputpin();
	
	virtual void save(ofstream&, int = 0) ;
	virtual void load(ifstream&, Component*, Component*);

	//getter for the pin number
	int GetCurrentPinNum();

	virtual void setoutputpincordns(int& x, int& y) = 0;

	//setting input pins coordinates after loading
	virtual void SetInputPinCoordinates()=0;


	bool InsideArea(int, int);
};

#endif
