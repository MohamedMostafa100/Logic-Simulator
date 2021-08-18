#include "Component.h"

//initializing the ID static data member
int Component::ID = 1;

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
}


bool Component::GetIsSelected()
{
	return IsSelected;
}

void Component::SetIsSelected(bool selected)
{
	IsSelected = selected;
	return;
}



int Component::GetID()
{
	return thisID;
}

void Component::SetID(int load)
{
	//setting the id either from loading or from creating the component
	if (load == -1) {
		thisID = Component::ID;
		Component::ID++;
		return;
	}
	else {
		thisID = load;
	}
}

GraphicsInfo Component::getGfxInfo()
{
	return m_GfxInfo;
}

void Component::setm_Label(string EnteredLabel)
{
	m_Label = EnteredLabel;

}

void Component::draw_label(Output* pOut)
{
	pOut->PrintString(m_Label, m_GfxInfo.x1, m_GfxInfo.y1 + 50);
}

string Component::getm_Label()
{
	return m_Label;
}

Component::Component()
{}

Component::~Component()
{}

