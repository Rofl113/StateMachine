#pragma once
#include "MachineBase.h"

class StateMachineControl
{
protected:
	StateMachineControl();
	virtual ~StateMachineControl();
	virtual MsgEventPtr handleBeforeState(const MsgEventPtr msgParent) = 0;
	virtual MsgEventPtr handleAfterState(const MsgEventPtr msgChild) = 0;

};
