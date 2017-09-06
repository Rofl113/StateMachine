#pragma once
#include "Messages.h"

class MachineControl;

// Менеджер Сообщений
class ManagerMessagesControl
{
public:
	ManagerMessagesControl();
	virtual ~ManagerMessagesControl();
	virtual bool pushMessages(const MsgEventPtr msg) = 0;
	virtual bool processMessages() = 0;
	virtual void setMachineRoot(MachineControl* machine) = 0;
};
