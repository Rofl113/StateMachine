#pragma once
#include "StateMachineControl.h"
#include "StateControl.h"

class StateMachineBase : public MachineBase, public StateMachineControl
{
protected:
	StateMachineBase();
	virtual ~StateMachineBase();
	virtual MsgEventPtr handleBeforeState(const MsgEventPtr msg) override;
	virtual MsgEventPtr handleAfterState(const MsgEventPtr msg) override;

	template < class T = StateControl>
	void switchState(T* state)
	{
		_switchChild(std::move(state));
	}
	MsgEventPtr pushMsgState(MsgEventPtr);

private:
	virtual MsgEventPtr _handleBeforeChild(const MsgEventPtr msg) override;
	virtual MsgEventPtr _handleAfterChild(const MsgEventPtr msgChild) override;
};
