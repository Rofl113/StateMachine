#pragma once
#include <queue>
#include "ManagerMessagesControl.h"


// Менеджер Сообщений
class ManagerMessages : public ManagerMessagesControl
{
public:
	explicit ManagerMessages(std::shared_ptr<MachineControl> rootMachine = {});
	virtual ~ManagerMessages();
	virtual void setRootMachine(std::shared_ptr<MachineControl> rootMachine = {}) override;
	virtual bool sendMessage(const MsgEventPtr& msg) override;
	virtual bool work();


private:
	std::queue<MsgEventPtr> m_msgQueue;
	std::shared_ptr<MachineControl> m_rootMachine;
};
