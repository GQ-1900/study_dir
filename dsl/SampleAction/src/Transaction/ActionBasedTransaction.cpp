/*
 * ActionBasedTransaction.cpp
 *
 *  Created on: 2014��11��8��
 *      Author: Thoughtworks
 */

#include "../SchedAction/SchedAction.h"
#include "../../include/Transaction/ActionBasedTransaction.h"

Status ActionBasedTransaction::start()
{
	return ROLE(SchedAction).exec();
}

Status ActionBasedTransaction::handleEvent(const Event& event)
{
	return ROLE(SchedAction).handleEvent(event);
}
