/*
 * autoMsg.h
 *
 *  Created on: 2018-3-18
 *      Author: ubuntu
 */

#ifndef AUTOMSG_H_
#define AUTOMSG_H_

#include "Message.h"
#include "StaticObjectAllocator.h"
#include "MsgAllocator.h"

template <typename MSG, typename MSG_ALLOCATOR>
struct GenericMsg : MSG, Message<MSG_ALLOCATOR>
{
};

template <typename MSG, typename MSG_ALLOCATOR = MsgAllocator>
struct AutoMsg
{
	AutoMsg()
	{
		msg = new GenericMsg<MSG, MSG_ALLOCATOR>;
	}

	~AutoMsg()
	{
		if(msg != 0)
		{
			msg->operator delete((void*)msg);
			msg = 0;
		}
	}

	MSG* operator->()
	{
		return msg ? msg : &getDefault();
	}

	const MSG* getPointer() const
	{
		return msg ? msg : &getDefault();
	}

	const MSG& getRef() const
	{
		return msg? *msg : getDefault();
	}

private:
	MSG& getDefault() const
	{
		static GenericMsg<MSG, MSG_ALLOCATOR> defaultMsg;
		return defaultMsg;
	}

private:
	GenericMsg<MSG, MSG_ALLOCATOR>* msg;

};

#endif
