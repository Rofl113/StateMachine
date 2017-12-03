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
	if (const auto msgSwitch = CAST_EVENT<MsgEventSwitchChild>(msg))
	{
		const auto machineMsg = msgSwitch->getMachineMsg();
		if (machineMsg && (machineMsg == _getChild()))
		{
			switchState(msgSwitch->createChild());
			return {};
		}
	}
	return handleAfterState(msg);
}
