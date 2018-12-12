/*
 * Transaction.h
 *
 *  Created on: 2014��11��8��
 *      Author: Thoughtworks
 */

#ifndef TRANSACTION_H_
#define TRANSACTION_H_
#include "../Common/CommonDefine.h"
class Event;

DEF_ROLE(Transaction)
{
	ABSTRACT(Status start());
	ABSTRACT(Status handleEvent(const Event& event));
};
#endif /* TRANSACTION_H_ */
