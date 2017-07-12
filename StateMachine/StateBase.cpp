#include "StateBase.h"

StateBase::StateBase()
{

}

StateBase::~StateBase()
{

}

MsgEventPtr StateBase::pushMsgStateMachine(MsgEventPtr msg)
{
	return _pushMsgChild(msg);
}

MsgEventPtr StateBase::handleBeforeStateMachine(const MsgEventPtr msg)
{
	return msg;
}

MsgEventPtr StateBase::handleAfterStateMachine(const MsgEventPtr msg)
{
	return msg;
}

MsgEventPtr StateBase::_handleBeforeChild(const MsgEventPtr msg)
{
	return handleBeforeStateMachine(msg);
}

MsgEventPtr StateBase::_handleAfterChild(const MsgEventPtr msg)
{
	return handleAfterStateMachine(msg);
}
