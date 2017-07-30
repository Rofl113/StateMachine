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

void MachineBase::_setManager(std::shared_ptr<ManagerMessagesControl> manager)
{
	m_manager = manager;
}

MachineBase::MachineBase()
{

}

MachineBase::~MachineBase()
{

}

void MachineBase::sendMessage(const MsgEventPtr msg)
{
	if (m_root)
	{
		return m_root->sendMessage(msg);
	}
	else if (m_manager)
	{
		return m_manager->sendMessage(msg), void();
	}

	return _handleMessage(msg), void();
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

void MachineBase::_setRoot(std::shared_ptr<MachineControl> root)
{
	m_root = root;
}
