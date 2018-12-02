/*
 * Message.h
 *
 *  Created on: 2018-3-18
 *      Author: ubuntu
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

template<typename MSG_ALLOCATOR>
struct Message
{
	void* operator new(size_t size) throw()
	{
		void *p = MSG_ALLOCATOR::alloc(size);

		return p;
	}

	void operator delete(void *p)
	{
		MSG_ALLOCATOR::free(p);
	}
	virtual ~Message() {};
};

#endif /* MESSAGE_H_ */
