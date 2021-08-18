#include "SWITCH.h"
#include<fstream>
#include"Connection.h"

SWITCH::SWITCH(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(0, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

SWITCH::SWITCH():Gate(1,switch_FANOUT)
{
}


void SWITCH::Operate()
{
	Connection** connection = m_OutputPin.getconnections();
	int m_conn_switch = m_OutputPin.getnumberofconnections();
	for (int i = 0; i < m_conn_switch; i++)
	{
		connection[i]->Operate();
		connection[i]->getDestPin()->getComponent()->Operate();
	}
}


// Function Draw
// Draws 1-output SWITCH gate
void SWITCH::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if (UI.AppMode == SIMULATION) {
		if (GetOutPinStatus() == HIGH) {
			pOut->DrawSwitch(m_GfxInfo, true);
		}
		else {
			pOut->DrawSwitch(m_GfxInfo, false);
		}
	}
	else {
		pOut->DrawSwitch(m_GfxInfo, IsSelected);
	}
}



//returns status of outputpin
int SWITCH::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int SWITCH::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void SWITCH::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}



ComponentType SWITCH::GetComponentType()
{
	return COMP_Switch;
}

void SWITCH::setoutputpincordns(int& x, int& y)
{
	x = m_GfxInfo.x2;
	y = (m_GfxInfo.y2 + m_GfxInfo.y1) / 2;
}

void SWITCH::SetInputPinCoordinates()
{
}

void SWITCH::setOuputPinStatus(STATUS s)
{
	m_OutputPin.setStatus(s);
}
