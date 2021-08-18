#include "OutputPin.h"
#include "Connection.h"
#include"../Components/Component.h"

OutputPin::OutputPin(int r_FanOut)
{
	m_Conn = 0;		//initially Pin is not connected to anything.
	m_FanOut = r_FanOut > MAX_CONNS ? MAX_CONNS: r_FanOut;	//set the fan out of the pin.
}

//Functionn ConnectTo:
//Connects the ouput pin the the passed connection if the fan out permits
//if the no. of connections is already equals to the fan out, no more connections can be created.
bool OutputPin::ConnectTo(Connection *r_Conn)
{
	if(m_Conn < m_FanOut)
	{
		m_Connections[m_Conn++] = r_Conn;	//add a new connection the the array of connections
		return true;
	}
	
	return false;	//can't connect to any more connections
}

bool OutputPin::checknumberofconnections()
{
	if (m_Conn < m_FanOut)
	{
		return true;
	}
	return false;
}

void OutputPin::setComponent(Component* pCmp)
{
	this->pComp = pCmp;
}

Component* OutputPin::getComponent()
{
	return pComp;
}

void OutputPin::Disconnect(Connection* conn)
{
	for (int i = 0; i < m_Conn; i++) {
		if (m_Connections[i] == conn) {
			m_Connections[i] = NULL;
			m_Connections[i] = m_Connections[m_Conn - 1];
			m_Connections[m_Conn - 1] = NULL;
			m_Conn--;
		}
	}
}


Connection** OutputPin::getconnections()
{
	return m_Connections;
}
int OutputPin::getnumberofconnections()
{
	return m_Conn;
}

