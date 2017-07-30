#pragma once
#include "Messages.h"


class MachineControl
{
public:
	MachineControl();
	virtual ~MachineControl();
	virtual void sendMessage(const MsgEventPtr msg) = 0;
};
