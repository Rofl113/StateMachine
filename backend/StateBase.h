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
		MsgEventSwitchState(const MachineControl* machine) : m_machine(machine) {}
		~MsgEventSwitchState() {}
	private:
		virtual MachineControl* createChild() const override
		{
			return new T();
		}
		virtual const MachineControl* getMachineMsg() const override
		{
			return m_machine;
		}

		const MachineControl* m_machine;
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
		return std::make_shared<MsgEventSwitchState<T>>(this);
	}

private:
	virtual MsgEventPtr _handleBeforeChild(const MsgEventPtr& msgParent) override;
	virtual MsgEventPtr _handleAfterChild(const MsgEventPtr& msgChild) override;
};
