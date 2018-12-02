/*
 * MsgAllocator.h
 *
 *  Created on: 2018-3-18
 *      Author: ubuntu
 */

#ifndef MSGALLOCATOR_H_
#define MSGALLOCATOR_H_

#include <stddef.h>
struct MsgAllocator
{
	static void* alloc(size_t size);
	static void free(void* p);
};

#endif
