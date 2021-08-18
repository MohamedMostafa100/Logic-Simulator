#include "InputPin.h"


InputPin::InputPin()
{
	m_Connections = NULL;
}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}

bool InputPin::ConnectTo(Connection* r_Conn)
{
	if (m_Connections == NULL)
	{
		m_Connections = r_Conn;	//add a new connection the the array of connections
		return true;
	}

	return false;	//can't connect to any more connections
}

Connection* InputPin::getconnection()
{
	return m_Connections;
}

void InputPin::set(int X, int Y)
{
	x = X;
	y = Y;
}

void InputPin::getcordns(int& X, int& Y)
{
	if (this != NULL) {
		X = x;
		Y = y;
	}
}

void InputPin::Disconnect()
{
	m_Connections = NULL;
}
