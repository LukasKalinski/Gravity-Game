///////////////////////////////////////////////////////////
//  InputListener.h
//  Implementation of the Class InputListener
//  Created on:      28-mar-2008 10:27:59
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_9BA149A1_F03F_4737_9DCF_9F09731840BA__INCLUDED_)
#define EA_9BA149A1_F03F_4737_9DCF_9F09731840BA__INCLUDED_

#include <map>

/**
 * Abstract input listener.
 */
class InputListener
{

public:

	InputListener();
	virtual ~InputListener();
	InputListener(const InputListener& il);
	virtual void refresh() = 0;
	void enableListen(unsigned short controlAlias, bool* controlSwitch);

protected:

	void switchOff(unsigned short controlAlias);
	void switchOn(unsigned short controlAlias);

private:

	std::map<unsigned short, bool*> m_switches;

};
#endif // !defined(EA_9BA149A1_F03F_4737_9DCF_9F09731840BA__INCLUDED_)
