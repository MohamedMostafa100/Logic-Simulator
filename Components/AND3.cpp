#include "AND3.h"
#include<iostream>
#include<fstream>
#include"Connection.h"


AND3::AND3(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	m_InputPins[0].set(m_GfxInfo.x1, (m_GfxInfo.y1 + 12));
	m_InputPins[1].set(m_GfxInfo.x1, (m_GfxInfo.y2 + m_GfxInfo.y1) / 2);
	m_InputPins[2].set(m_GfxInfo.x1, (m_GfxInfo.y2 - 12));
}


AND3::AND3():Gate(3,AND3_FANOUT)
{
}

void AND3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	//Add you code here

	bool out = 1;
	for (int i = 0; i < m_Inputs; i++)
	{
		out = out && (m_InputPins[i].getStatus() == STATUS::HIGH ? 1 : 0);
	}
	m_OutputPin.setStatus(out ? STATUS::HIGH : STATUS::LOW);
	Connection** connection = m_OutputPin.getconnections();
	int m_conn_switch = m_OutputPin.getnumberofconnections();
	for (int i = 0; i < m_conn_switch; i++)
	{
		connection[i]->Operate();
		connection[i]->getDestPin()->getComponent()->Operate();
	}
}


// Function Draw
// Draws 3-input AND gate
void AND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND3(m_GfxInfo, IsSelected);
}

//returns status of outputpin
int AND3::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND3::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

ComponentType AND3::GetComponentType()
{
	return COMP_AND3;
}

void AND3::setoutputpincordns(int& x, int& y)
{
	x = m_GfxInfo.x2;
	y = (m_GfxInfo.y2 + m_GfxInfo.y1) / 2;
}

void AND3::SetInputPinCoordinates()
{
	m_InputPins[0].set(m_GfxInfo.x1, (m_GfxInfo.y1 + 12));
	m_InputPins[1].set(m_GfxInfo.x1, (m_GfxInfo.y2 + m_GfxInfo.y1) / 2);
	m_InputPins[2].set(m_GfxInfo.x1, (m_GfxInfo.y2 - 12));
}

