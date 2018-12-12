#ifndef ASYNCHELPER_H_
#define ASYNCHELPER_H_

#include "../SchedAction/SchedActionAdpter.h"

template<typename ACTION>
class ASYNC__ : public SchedActionAdapter
{
public:
	Action& getAction(){
		return _action;
	}
private:
	ACTION _action;
};

#endif
