/*
 * Transaction.h
 *
 *  Created on: 2014��11��7��
 *      Author: Thoughtworks
 */

#ifndef ACTION_BASED_TRANSACTION_H
#define ACTION_BASED_TRANSACTION_H

#include "../Common/CommonDefine.h"
#include "../Common/Role.h"
#include "Transaction.h"

class SchedAction;
class ActionBasedTransaction : public Transaction{
public:
	OVERRIDE Status start();
	OVERRIDE Status handleEvent(const Event& event);
private:
	USE_ROLE(SchedAction);
};


#endif /* TRANSACTION_H_ */
