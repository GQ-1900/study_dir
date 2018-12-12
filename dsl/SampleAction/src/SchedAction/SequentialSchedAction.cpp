#include "Action/Event.h"
#include "SchedAction/SequentialSchedAction.h"
#include "Common/ActionStatus.h"

using namespace std;

SequentialSchedAction::SequentialSchedAction() :
		_current(0) {
}

Status SequentialSchedAction::exec() {
	return forword();
}

//ActionStatus��������
#define CHECK_DONE(operation) do{\
	ActionStatus status = operation;\
	if (not status.isDone()){\
		return status;\
	}\
}while(0)


Status SequentialSchedAction::forword() {
	while(nullptr != (_current = pop_front())){
		CHECK_DONE(_current->exec());
	}
	return SUCCESS;
}

Status SequentialSchedAction::handleEvent(const Event& event) {
	if (nullptr == _current){
		return UNKNOWN_EVENT;
	}
	CHECK_DONE(_current->handleEvent(event));
	return forword();
}

void SequentialSchedAction::pushBackAction(SchedAction* action) {
	_actions.push_back(action);
}

SchedAction* SequentialSchedAction::pop_front() {
	if (_actions.empty()){
		return nullptr;
	}
	SchedAction* action = _actions.front();
	_actions.pop_front();
	return action;
}
