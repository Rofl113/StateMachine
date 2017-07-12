#pragma once
#include "StateMachineControl.h"
#include "StateControl.h"

class StateMachineBase : public MachineBase, public StateMachineControl
{
protected:
	virtual MsgEventPtr handleBeforeState(const MsgEventPtr msgParent) override;
	virtual MsgEventPtr handleAfterState(const MsgEventPtr msgChild) override;
protected:
	StateMachineBase();
	virtual ~StateMachineBase();
	template < class T = StateControl>
	void switchState(T* state)
	{
		_switchChild(std::move(state));
	}
	MsgEventPtr pushMsgState(MsgEventPtr);

private:
	virtual MsgEventPtr _handleBeforeChild(const MsgEventPtr msgParent) override;
	virtual MsgEventPtr _handleAfterChild(const MsgEventPtr msgChild) override;
};
