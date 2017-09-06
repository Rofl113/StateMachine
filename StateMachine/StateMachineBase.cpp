#include "StateMachineBase.h"

StateMachineBase::StateMachineBase()
{

}

StateMachineBase::~StateMachineBase()
{

}

MsgEventPtr StateMachineBase::handleBeforeState(const MsgEventPtr& msg)
{
	return msg;
}

MsgEventPtr StateMachineBase::handleAfterState(const MsgEventPtr& msg)
{
	return msg;
}

MsgEventPtr StateMachineBase::_handleBeforeChild(const MsgEventPtr& msg)
{
	return handleBeforeState(msg);
}

MsgEventPtr StateMachineBase::_handleAfterChild(const MsgEventPtr& msg)
{
	if (auto msgSwitch = CAST_EVENT<MsgEventSwitchChild>(msg))
	{
		switchState(msgSwitch->createChild());
		return {};
	}
	return handleAfterState(msg);
}
