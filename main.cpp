#include <QDebug>
#include <QApplication>
#include "StateMachine/StateMachineBase.h"
#include "StateMachine/ManagerMessages.h"

class MsgEventHello : public MsgEvent
{
public:
	MsgEventHello(std::string name)
		: m_name(name)
	{

	}

	const std::string m_name;
};

class StateMachineHello : public StateMachineBase
{
protected:
	virtual MsgEventPtr handleBeforeState(const MsgEventPtr msgParent) override
	{
		if (auto msg = CAST_EVENT<MsgEventHello>(msgParent))
		{
			qDebug() << QString(msg->m_name.c_str()) << "= Hello!";
			return {};
		}
		return msgParent;
	}
};

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	std::shared_ptr<ManagerMessagesControl> manager;
	{
		auto mana = new ManagerMessages;
		if (!mana)
		{
			return -1;
		}
		manager = std::shared_ptr<ManagerMessagesControl>{mana};
		mana = nullptr;
	}
	std::shared_ptr<MachineControl> machine;
	{
		auto mach = new StateMachineHello;
		if (!mach)
		{
			return -2;
		}
		machine = std::shared_ptr<MachineControl>{mach};
		mach = nullptr;
	}
	machine->sendMessage(std::make_shared<MsgEventHello>("machine->sendMessage (AfterSetRoot)"));
	manager->sendMessage(std::make_shared<MsgEventHello>("manager->sendMessage (AfterSetRoot)"));
	manager->setRootMachine(machine);
	machine->sendMessage(std::make_shared<MsgEventHello>("machine->sendMessage (BeforeSetRoot)"));
	manager->sendMessage(std::make_shared<MsgEventHello>("manager->sendMessage (BeforeSetRoot)"));
	manager->work();

	return 0;
}
