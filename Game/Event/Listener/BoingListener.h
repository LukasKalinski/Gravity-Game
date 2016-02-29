#if !defined _BOING_LISTENER_INCLUDED____
#define _BOING_LISTENER_INCLUDED____

#include "BoingEvent.h"

class BoingListener
{
public:
	virtual void notifyEvent(const BoingEvent& ev) = 0;
};

#endif
