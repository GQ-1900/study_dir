#ifndef SCHEDACTIONADPTER_H_
#define SCHEDACTIONADPTER_H_

#include "SchedAction.h"
#include "../Action/Action.h"

class SchedActionAdapter : public SchedAction
{
public:
	OVERRIDE Status exec();
	OVERRIDE Status handleEvent(const Event& event);
private:
	USE_ROLE(Action);
};
#endif
