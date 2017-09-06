#pragma once
#include "StateControl.h"
#include "StateMachineControl.h"

class StateBase : public MachineBase, public StateControl
{
private:
	template < class T = StateBase>
	class MsgEventSwitchState: private MsgEventSwitchChild
	{
	public:
		MsgEventSwitchState() {}
		~MsgEventSwitchState() {}
	private:
		virtual MachineControl* createChild() const override
		{
			return new T();
		}
	};
protected:
	virtual MsgEventPtr handleBeforeStateMachine(const MsgEventPtr& msgParent) override;
	virtual MsgEventPtr handleAfterStateMachine(const MsgEventPtr& msgChild) override;

protected:
	StateBase();
	virtual ~StateBase();
	template < class T = StateMachineControl>
	void switchStateMachine(std::shared_ptr<T> stateMachine)
	{
		switchChild(std::move(stateMachine));
	}
	template < class T = StateBase>
	MsgEventPtr CREATE_MSG_SWITCH_STATE()
	{
		return std::make_shared<MsgEventSwitchState<T>>();
	}

private:
	virtual MsgEventPtr _handleBeforeChild(const MsgEventPtr& msgParent) override;
	virtual MsgEventPtr _handleAfterChild(const MsgEventPtr& msgChild) override;
};
