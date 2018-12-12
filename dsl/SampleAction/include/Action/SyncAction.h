#ifndef SYNCACTION_H_
#define SYNCACTION_H_
#include "Event.h"
#include "../Common/Role.h"
#include "../Common/CommonDefine.h"

DEF_ROLE(SyncAction)
{
public:
	ABSTRACT(Status exec());
};

#endif
