#pragma once
#include "MachineBase.h"

class StateControl
{
protected:
	StateControl();
	virtual ~StateControl();
	virtual MsgEventPtr handleBeforeStateMachine(const MsgEventPtr msgParent) = 0;
	virtual MsgEventPtr handleAfterStateMachine(const MsgEventPtr msgChild)   = 0;
};
