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
{

}

MachineBase::~MachineBase()
{

}

MsgEventPtr MachineBase::sendMessage(const MsgEventPtr msg)
{
	auto msgOut = _handleBeforeChild(msg);
	if (m_child && msgOut)
	{
		const auto msgOutChild = m_child->sendMessage(msgOut);
		msgOut = _handleAfterChild(msgOutChild);
	}
	return msgOut;
}

MsgEventPtr MachineBase::_pushMsgChild(MsgEventPtr msg)
{
	return m_child->sendMessage(msg);
}
