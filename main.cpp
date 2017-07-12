#include <QDebug>
#include <QApplication>
#include "StateMachine/StateMachineBase.h"

class MsgEventHello : public MsgEvent
{

};

class StateMachineHello : public StateMachineBase
{
protected:
	virtual MsgEventPtr handleBeforeState(const MsgEventPtr msgParent) override
	{
		if (CAST_EVENT<MsgEventHello>(msgParent))
		{
			qDebug() << "Hello!";
			return {};
		}
		return msgParent;
	}
};

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	std::shared_ptr<MachineControl> machine {new StateMachineHello};
	machine->sendMessage(std::make_shared<MsgEventHello>());

	return a.exec();
}
