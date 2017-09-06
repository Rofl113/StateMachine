#include "ManagerMessagesControl.h"
#include "MachineBase.h"

MachineBase::MsgEventSwitchChild::MsgEventSwitchChild()
{

}

MachineBase::MsgEventSwitchChild::~MsgEventSwitchChild()
{

}

MachineControl* MachineBase::MsgEventSwitchChild::createChild() const
{
	return {};
}

MachineBase::MachineBase()
	: m_manager(nullptr)
{

}

MachineBase::~MachineBase()
{

}

void MachineBase::sendMessage(const MsgEventPtr msg)
{
	return _handleMessage(msg), void();
}

void MachineBase::setManager(ManagerMessagesControl* manager)
{
	if (manager == m_manager)
	{
		return;
	}
	_setManager(manager);
}

void MachineBase::_setManager(ManagerMessagesControl* manager)
{
	m_manager = manager;
	if (m_manager)
	{
		m_manager->setMachineRoot(this);
	}
}

MsgEventPtr MachineBase::_handleMessage(const MsgEventPtr msg)
{
	const auto msgOut = _handleBeforeChild(msg);
	if (!m_child || !msgOut)
	{
		return msgOut;
	}

	auto child = dynamic_cast<MachineBase*>(m_child.get());
	const auto msgOutChild = child->_handleMessage(msgOut);

	return msgOutChild ? _handleAfterChild(msgOutChild) : MsgEventPtr{};
}
