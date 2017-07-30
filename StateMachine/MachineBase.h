#pragma once
#include "MachineControl.h"

class ManagerMessagesControl;


class MachineBase : public MachineControl
{
public:
	void _setManager(std::shared_ptr<ManagerMessagesControl> manager);
	MsgEventPtr _handleMessage(const MsgEventPtr msg);

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
		if (auto ch = dynamic_cast<MachineBase*>(child))
		{
			ch->_setRoot(m_root);
		}
		m_child.reset(child);
	}

private:
	virtual void sendMessage(const MsgEventPtr msg) override;
	virtual void _setRoot(std::shared_ptr<MachineControl> root);

	std::shared_ptr<ManagerMessagesControl> m_manager;
	std::shared_ptr<MachineControl> m_root;
	std::shared_ptr<MachineControl> m_child;
};
