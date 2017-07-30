#pragma once
#include <memory>

class MachineControl;
class MsgEvent;
using MsgEventPtr = std::shared_ptr<const MsgEvent>;

// Менеджер Сообщений
class ManagerMessagesControl
{
public:
	virtual ~ManagerMessagesControl();
	virtual void setRootMachine(std::shared_ptr<MachineControl> rootMachine = {}) = 0;
	virtual bool sendMessage(const MsgEventPtr& msg) = 0;
	virtual bool work() = 0;
};
