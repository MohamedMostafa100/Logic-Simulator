#include "NOR3.h"
#include<iostream>
#include<fstream>
#include"Connection.h"


NOR3::NOR3(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	m_InputPins[0].set(m_GfxInfo.x1, (m_GfxInfo.y1 + 12));
	m_InputPins[1].set(m_GfxInfo.x1, (m_GfxInfo.y2 + m_GfxInfo.y1) / 2);
	m_InputPins[2].set(m_GfxInfo.x1, (m_GfxInfo.y2 - 12));
}

NOR3::NOR3():Gate(3,NOR3_FANOUT)
{
}


void NOR3::Operate()
{
	bool out = 0;
	for (int i = 0; i < m_Inputs; i++)
	{
		out = out || (m_InputPins[i].getStatus() == STATUS::HIGH ? 1 : 0);
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
// Draws 3-input NOR gate
void NOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR3(m_GfxInfo, IsSelected);
}

//returns status of outputpin
int NOR3::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR3::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}


ComponentType NOR3::GetComponentType()
{
	return COMP_NOR3;
}


void NOR3::setoutputpincordns(int& x, int& y)
{
	x = m_GfxInfo.x2;
	y = (m_GfxInfo.y2 + m_GfxInfo.y1) / 2;
}

void NOR3::SetInputPinCoordinates()
{
	m_InputPins[0].set(m_GfxInfo.x1, (m_GfxInfo.y1 + 12));
	m_InputPins[1].set(m_GfxInfo.x1, (m_GfxInfo.y2 + m_GfxInfo.y1) / 2);
	m_InputPins[2].set(m_GfxInfo.x1, (m_GfxInfo.y2 - 12));
}

