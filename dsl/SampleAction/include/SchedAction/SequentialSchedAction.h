#ifndef SEQUENTIALSCHEDACTION_H_
#define SEQUENTIALSCHEDACTION_H_

#include "../Common/CommonDefine.h"
#include "../SchedAction/SchedAction.h"
#include <list>

class Event;
class SchedAction;

class SequentialSchedAction : public SchedAction{
public:
	SequentialSchedAction();
	OVERRIDE Status exec();
	OVERRIDE Status handleEvent(const Event& event);
	void pushBackAction(SchedAction* action);
private:
	Status forword();
	SchedAction* pop_front();
private:
	std::list<SchedAction*> _actions;
	SchedAction* _current;
};
#endif
