#pragma once
#include "Messages.h"

class ManagerMessagesControl;

class MachineControl
{
public:
	MachineControl();
	virtual ~MachineControl();
	virtual void sendMessage(const MsgEventPtr msg) = 0;
	virtual void setManager(ManagerMessagesControl* manager) = 0;
};
