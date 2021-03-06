#include <iostream>
#include "StateMachineBase.h"
#include "ManagerMessages.h"

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
	virtual MsgEventPtr handleBeforeState(const MsgEventPtr& msgParent) override
	{
		if (auto msg = CAST_EVENT<MsgEventHello>(msgParent))
		{
            std::cout << msg->m_name << "= Hello!" << std::endl;
			return {};
		}
		return msgParent;
	}
};

int main(int argc, char *argv[])
{
	std::shared_ptr<ManagerMessagesControl> manager;
	{
		auto mana = new ManagerMessages;
		if (!mana)
		{
			return -1;
		}
		manager = std::shared_ptr<ManagerMessagesControl>(mana);
		mana = nullptr;
	}

	std::shared_ptr<MachineControl> machine;
	{
		auto mach = new StateMachineHello;
		if (!mach)
		{
			return -2;
		}
		machine = std::shared_ptr<MachineControl>(mach);
		mach = nullptr;
	}

    std::cout << "Example One" << std::endl;
	manager->setMachineRoot(nullptr);
	machine->sendMessage(std::make_shared<MsgEventHello>("machine->sendMessage (AfterSetRoot)"));
	manager->pushMessages(std::make_shared<MsgEventHello>("manager->sendMessage (AfterSetRoot)"));
	manager->setMachineRoot(machine.get());
	machine->sendMessage(std::make_shared<MsgEventHello>("machine->sendMessage (BeforeSetRoot)"));
	manager->pushMessages(std::make_shared<MsgEventHello>("manager->sendMessage (BeforeSetRoot)"));
	manager->processMessages();

    std::cout << "\nExample Two" << std::endl;
	manager->setMachineRoot(nullptr);
	machine->sendMessage(std::make_shared<MsgEventHello>("machine->sendMessage (AfterSetRoot)"));
	manager->pushMessages(std::make_shared<MsgEventHello>("manager->sendMessage (AfterSetRoot)"));
	manager->processMessages();
	manager->setMachineRoot(machine.get());
	machine->sendMessage(std::make_shared<MsgEventHello>("machine->sendMessage (BeforeSetRoot)"));
	manager->pushMessages(std::make_shared<MsgEventHello>("manager->sendMessage (BeforeSetRoot)"));
	manager->processMessages();

	return 0;
}
