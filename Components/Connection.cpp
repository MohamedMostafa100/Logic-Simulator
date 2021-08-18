#include "Connection.h"
#include<fstream>
#include"Gate.h"

Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)	
	
{
	//SrcPin = pSrcPin;
	//DstPin = pDstPin;
	setSourcePin(pSrcPin);
	setDestPin(pDstPin);
	IsSelected = false;
	SetDstPinNum(((Gate*)DstCmpnt)->GetCurrentPinNum());
}
Connection::Connection()
{
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;
	//setting the source component
	SrcCmpnt = SrcPin->getComponent();
}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	
	DstPin = pDstPin;
	//setting the destination component
	DstCmpnt = DstPin->getComponent();
}

InputPin* Connection::getDestPin()
{	return DstPin;	}


//must be initialized at constructor
void Connection::SetDstPinNum(int num)
{
	DstPinNum = num;
}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if (UI.AppMode == SIMULATION) {
		if (GetInputPinStatus(1) == HIGH) {
			pOut->DrawConnection(m_GfxInfo, true);
		}
		else {
			pOut->DrawConnection(m_GfxInfo, false);
		}
	}
	else {
		pOut->DrawConnection(m_GfxInfo, IsSelected);
	}
}


Component* Connection::GetDstCmpnt()
{
	return DstCmpnt;
}


Component* Connection::GetSrcCmpnt()
{
	return SrcCmpnt;
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

void Connection::save(ofstream& file, int Isconnection)
{
	if (Isconnection == 1) {
		//first component ID-second component ID-pin number of second component
		file << SrcCmpnt->GetID() << " " << DstCmpnt->GetID() << " " << DstPinNum << endl;
	}
}

void Connection::load(ifstream&file, Component* SourceComponent, Component* DestComponent)
{
	//connection is initially not selected
	IsSelected = false;
	//loading the connection information from file
	int DstPinNumber;
	file >> DstPinNumber;
	//setting the connection source component & destination component
	DstCmpnt = DestComponent;
	SrcCmpnt = SourceComponent;
	//setting the connections data members
	SetDstPinNum(DstPinNumber);
	SrcPin = ((Gate*)SrcCmpnt)->getoutputpin();
	DstPin = ((Gate*)DstCmpnt)->getinputpin(DstPinNumber-1);

	int x1, y1, x2, y2;
    ((Gate*)SrcCmpnt)->setoutputpincordns(x1, y1);
	m_GfxInfo.x1 = x1;
	m_GfxInfo.y1 = y1;
	SrcPin->ConnectTo(this);

	DstPin->getcordns(x2, y2);
	m_GfxInfo.x2 = x2;
	m_GfxInfo.y2 = y2;
	DstPin->ConnectTo(this);
}

ComponentType Connection::GetComponentType()
{
	return COMP_CONNECTION;
}

bool Connection::InsideArea(int x, int y)
{
	if ((((x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2) || (x <= m_GfxInfo.x1 && x >= m_GfxInfo.x2)) && (y < m_GfxInfo.y1 + 10 && y>m_GfxInfo.y1 - 10)) || (((y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2) || (y <= m_GfxInfo.y1 && y >= m_GfxInfo.y2)) && (x < m_GfxInfo.x2 + 10 && x>m_GfxInfo.x2 - 10)))
	{
		return true;
	}
	return false;
}

void Connection::SetSrcPinCrds(int x, int y)
{
	m_GfxInfo.x1 = x;
	m_GfxInfo.y1 = y;
}

void Connection::SetDstPinCrds(int x, int y)
{
	m_GfxInfo.x2 = x;
	m_GfxInfo.y2 = y;
}


void Connection::DeleteConnection()
{
	SrcPin->Disconnect(this);
	DstPin->Disconnect();
}
