#include "LED.h"
#include<fstream>
#include"Connection.h"


LED::LED(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	m_InputPins[0].set(m_GfxInfo.x1+32, m_GfxInfo.y2-8);
}


LED::LED():Gate(1,LED_FANOUT)
{
}

void LED::Operate()
{
	return;
}


// Function Draw
// Draws 3-input AND gate
void LED::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if (UI.AppMode == SIMULATION) {
		if (GetInputPinStatus(1) == HIGH) {
			pOut->DrawLED(m_GfxInfo, true);
		}
		else {
			pOut->DrawLED(m_GfxInfo, false);
		}
	}
	else {
		pOut->DrawLED(m_GfxInfo, IsSelected);
	}
}

//returns status of outputpin
int LED::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}


ComponentType LED::GetComponentType()
{
	return COMP_LED;
}

void LED::setoutputpincordns(int& x, int& y)
{
}

void LED::SetInputPinCoordinates()
{
	m_InputPins[0].set(m_GfxInfo.x1, m_GfxInfo.y2);
}


