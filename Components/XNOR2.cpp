#include "XNOR2.h"
#include<iostream>
#include<fstream>
#include"Connection.h"

XNOR2::XNOR2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	m_InputPins[0].set(m_GfxInfo.x1, (m_GfxInfo.y1 + 12));
	m_InputPins[1].set(m_GfxInfo.x1, (m_GfxInfo.y2 - 12));
}

XNOR2::XNOR2():Gate(2,XNOR2_FANOUT)
{
}


void XNOR2::Operate()
{
	bool out = 0;
	for (int i = 0; i < m_Inputs; i++)
	{
		out = out ^ (m_InputPins[i].getStatus() == STATUS::HIGH ? 1 : 0);
	}
	m_OutputPin.setStatus(out ? STATUS::LOW : STATUS::HIGH);
	Connection** connection = m_OutputPin.getconnections();
	int m_conn_switch = m_OutputPin.getnumberofconnections();
	for (int i = 0; i < m_conn_switch; i++)
	{
		connection[i]->Operate();
		connection[i]->getDestPin()->getComponent()->Operate();
	}
}


// Function Draw
// Draws 2-input XNOR gate
void XNOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXNOR2(m_GfxInfo, IsSelected);
}

//returns status of outputpin
int XNOR2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}


ComponentType XNOR2::GetComponentType()
{
	return COMP_XNOR;
}


void XNOR2::setoutputpincordns(int& x, int& y)
{
	x = m_GfxInfo.x2;
	y = (m_GfxInfo.y2 + m_GfxInfo.y1) / 2;
}

void XNOR2::SetInputPinCoordinates()
{
	m_InputPins[0].set(m_GfxInfo.x1, (m_GfxInfo.y1 + 12));
	m_InputPins[1].set(m_GfxInfo.x1, (m_GfxInfo.y2 - 12));
}
