#include "MachineBase.h"
#include "ManagerMessages.h"

ManagerMessages::ManagerMessages(std::shared_ptr<MachineControl> rootMachine)
{
	setRootMachine(rootMachine);
}

ManagerMessages::~ManagerMessages()
{

}

void ManagerMessages::setRootMachine(std::shared_ptr<MachineControl> rootMachine)
{
	m_rootMachine = rootMachine;
	if (m_rootMachine)
	{
		if (auto base = dynamic_cast<MachineBase*>(m_rootMachine.get()))
		{
			base->_setManager(std::shared_ptr<ManagerMessages>(this));
		}
	}
}

bool ManagerMessages::sendMessage(const MsgEventPtr& msg)
{
	if (!msg || !m_rootMachine)
	{
		return false;
	}
	m_msgQueue.push(msg);
	return true;
}

bool ManagerMessages::work()
{
	if (!m_rootMachine)
	{
		return false;
	}
	auto base = dynamic_cast<MachineBase*>(m_rootMachine.get());
	if (!base)
	{
		return false;
	}

	while (not m_msgQueue.empty())
	{
		const auto msg = m_msgQueue.front();
		m_msgQueue.pop();
		base->_handleMessage(msg);
	}
}
