#ifndef _INPUTPIN_H
#define _INPUTPIN_H

#include "Pin.h"
#include"../Actions/Edit.h"

class Connection;	//Forward class declartion
class Component; //Forward class declaration

class InputPin: public Pin	//inherited from class Pin
{


	Connection* m_Connections;
	Component* pComp; //Component at which this pin is associated
	int x;
	int y;
public:
	InputPin();
	void setComponent(Component* pCmp);	//sets the component of this input pin
	Component* getComponent();	//returns the component of this input pin
	bool ConnectTo(Connection* r_Conn);	//connect to a new connection
	Connection* getconnection();
	void set(int X, int Y);
	void getcordns(int& X, int& Y);

	//Disconnects when the connection is deleted and frees the pin
	void Disconnect();
};

#endif