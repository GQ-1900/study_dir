#ifndef ASYNCACTION_H_
#define ASYNCACTION_H_
#include "SyncAction.h"

class Action : public SyncAction, public Role<Action>
{
public:
	ABSTRACT(Status handleEvent(const Event& event));
};
#endif
