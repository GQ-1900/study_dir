/*
 * StaticObjectAllocator.h
 *
 *  Created on: 2018-3-18
 *      Author: ubuntu
 */

#ifndef STATICOBJECTALLOCATOR_H_
#define STATICOBJECTALLOCATOR_H_

#include <string.h>

typedef unsigned short WORD16;
typedef unsigned int WORD32;
typedef unsigned long long WORD64;

#define __F_INDEX(index)		((index) >> 3)
#define __F_MASK(index)		(unsigned char) (1 << ((index)%8))

template<typename T, WORD16 MAX_NUM>
struct StaticObjectAllocator
{
public:
	StaticObjectAllocator(bool freeCheck = false) : needFreeCheck(freeCheck), freeHead(NULL), freeTail(NULL), freeCounter(0)
	{
		memset(flags, 0, NUM_OF_BYTE);
		for(WORD16 i = 0; i<MAX_NUM; i++)
		{
			freeEntity(entities[i]);
		}
	}

	WORD16 getFreeSloatNum() const
	{
		if (freeCounter > MAX_NUM)
		{
			return 0;
		}
		return freeCounter;
	}

	WORD16 getBusyNum() const
	{
		return(MAX_NUM - getFreeSloatNum());
	}

	bool hasFreeSlot() const
	{
		return freeHead != NULL;
	}

	void* alloc()
	{
		if (!hasFreeSlot())
		{
			return NULL;
		}
		return doAlloc();
	}

	void free(void *p)
	{
		if (p == NULL) return;

		if (needFreeCheck)
		{
			const WORD32 index = getIndex(p);
			const unsigned char mask = __F_MASK(index);
			const WORD32 n = __F_INDEX(index);

			if ((flags[n] & mask) == 0)
			{
				return;
			}
			flags[n] &= ~mask;
		}
		freeEntity(*(Entity*)p);
	}

	bool within(void* p) const
	{
		return p >= (void*)entities && p < (void*)&(entities[MAX_NUM]);
	}

private:
	union Entity
	{
		char obj[sizeof(T)];
		Entity* next;
	};

	void freeEntity(Entity& entity)
	{
		if (freeHead == 0)
		{
			freeHead = &entity;
		}else
		{
			freeTail->next =  &entity;
		}
		freeTail = &entity;
		freeTail->next = NULL;
		freeCounter++;
	}

	WORD32 getIndex(void *p) const
	{
		return ((Entity*)p) - entities;
	}

	void* doAlloc()
	{
		void* p = (void*)freeHead;
		freeHead = freeHead->next;

		if(freeHead == NULL)
		{
			freeTail =NULL;
		}
		freeCounter--;
		if (needFreeCheck)
		{
			WORD32 index = getIndex(p);
			flags[__F_INDEX(index)] |= __F_MASK(index);
		}

		return p;
	}

private:
	bool needFreeCheck;
	enum {NUM_OF_BYTE = (MAX_NUM >> 3) + ((MAX_NUM % 8)? 1:0)};
	Entity entities[MAX_NUM];
	unsigned char flags[NUM_OF_BYTE];
	Entity* freeHead;
	Entity* freeTail;
	WORD16 freeCounter;
};


#endif
