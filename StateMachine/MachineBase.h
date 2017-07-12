#pragma once
#include "MachineControl.h"

class MachineBase : public MachineControl
{
protected:
	class MsgEventSwitchChild : public MsgEvent
	{
		friend class StateMachineBase;
	protected:
		MsgEventSwitchChild();
		virtual ~MsgEventSwitchChild();
		virtual MachineControl* createChild() const;
	};

protected:
	MachineBase();
	virtual ~MachineBase();

protected:
	virtual MsgEventPtr _handleBeforeChild(const MsgEventPtr msgParent) = 0;
	virtual MsgEventPtr _handleAfterChild(const MsgEventPtr msgChild) = 0;
	template < class T = MachineBase>
	void _switchChild(T* child)
	{
		m_child.reset(child);
	}
	MsgEventPtr _pushMsgChild(MsgEventPtr);

private:
	virtual MsgEventPtr sendMessage(const MsgEventPtr msg) override;
	std::shared_ptr<MachineControl> m_child = nullptr;
};
