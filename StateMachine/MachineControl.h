#pragma once
#include "Messages.h"


class MachineControl
{
public:
	MachineControl();
	virtual ~MachineControl();
	virtual MsgEventPtr sendMessage(const MsgEventPtr msg) = 0;
};
