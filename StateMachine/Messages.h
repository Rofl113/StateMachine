#pragma once
#include <memory>

class MsgEvent
{
public:
	MsgEvent();
	virtual ~MsgEvent();
};

using MsgEventPtr = std::shared_ptr<const MsgEvent>;

template < class T = MsgEventPtr>
const T* CAST_EVENT(const MsgEventPtr msg)
{
	if (not msg)
	{
		return nullptr;
	}
	return dynamic_cast<const T*>(msg.get());
}

