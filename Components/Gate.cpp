#include "Gate.h"
#include<fstream>
#include<iostream>


//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	
	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
	
	//Associate output pin to the gate
	m_OutputPin.setComponent(this);

	IsSelected = false; //default

	//setting the ID of the gates
	SetID();
	//initializing the m_label with a blank space
	setm_Label(" ") ;

	//initializing current pin number
	CurrentPinNum = 0;
}



bool Gate::InsideArea(int x, int y)
{
	if (x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2 && y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2) {
		return true;
	}

	return false;
}

InputPin* Gate::getinputpin()
{
	for (int i = 0; i < m_Inputs; i++)
	{
		if (m_InputPins[i].getconnection() == NULL)
		{
			CurrentPinNum = i + 1;
			return &m_InputPins[i];
		}

	}
	return NULL;
}


InputPin* Gate::getinputpin(int num)
{
	return &m_InputPins[num];
}


OutputPin* Gate::getoutputpin()
{
	if (m_OutputPin.checknumberofconnections())
	{
		return &m_OutputPin;
	}
	return false;
}

void Gate::save(ofstream& file, int Isconnection)
{
	if (Isconnection != 1) {
		if (getm_Label() != " ") {
			//component type - component ID -label - rectangular area corners
			file << GetComponentType() << " " << thisID << " " << getm_Label() << " " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << endl;
		}
		else {
			file << GetComponentType() << " " << thisID << " " << "$" << " " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << endl;
		}
	}
}

void Gate::load(ifstream& file,Component* dummy, Component* dummy2)
{
	//reading the gate 
	int readid;
	string label;
	int rectarea1;
	int rectarea2;
	file >> readid >> label >> rectarea1 >> rectarea2;
	//setting the ID and label for the gate
	SetID(readid);
	if (label != "$")
	{
		setm_Label(label);
	}
	//setting the graphics info
	m_GfxInfo.x1 = rectarea1;
	m_GfxInfo.y1 = rectarea2;
	m_GfxInfo.x2 = rectarea1 + UI.AND2_Width;
	m_GfxInfo.y2 = rectarea2 + UI.AND2_Height;

	//setting the input pin coordinates
	SetInputPinCoordinates();
}

int Gate::GetCurrentPinNum()
{
	return CurrentPinNum;
}


