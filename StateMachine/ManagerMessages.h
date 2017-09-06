#pragma once
#include <queue>
#include "ManagerMessagesControl.h"


// Менеджер Сообщений
class ManagerMessages : public ManagerMessagesControl
{
public:
	explicit ManagerMessages();
	virtual ~ManagerMessages();
	virtual bool pushMessages(const MsgEventPtr& msg) override;
	virtual bool processMessages() override;
	virtual void setMachineRoot(MachineControl* machine) override;

private:
	void _setMachineRoot(MachineControl* machine);

	std::queue<MsgEventPtr> m_msgQueue;
	MachineControl* m_machineRoot;
};
