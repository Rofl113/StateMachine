#include "MachineBase.h"
#include "ManagerMessages.h"

ManagerMessages::ManagerMessages()
	: m_machineRoot(nullptr)
{

}
ManagerMessages::~ManagerMessages() {}

bool ManagerMessages::pushMessages(const MsgEventPtr msg)
{
	if (nullptr == msg)
	{
		return false;
	}
	m_msgQueue.push(msg);
	return true;
}

bool ManagerMessages::processMessages()
{
	std::queue<MsgEventPtr> empty;
	std::swap(m_msgQueue, empty);

	if (nullptr == m_machineRoot)
	{
		return false;
	}

	while (not empty.empty())
	{
		auto msg = empty.front();
		empty.pop();
		m_machineRoot->sendMessage(msg);
	}

	return true;
}

void ManagerMessages::setMachineRoot(MachineControl* machine)
{
	if (machine == m_machineRoot)
	{
		return;
	}
	_setMachineRoot(machine);
}

void ManagerMessages::_setMachineRoot(MachineControl* machine)
{
	m_machineRoot = machine;
	if (m_machineRoot)
	{
		m_machineRoot->setManager(this);
	}
}
