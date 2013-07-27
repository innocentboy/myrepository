/*
 * GCPtr.cpp
 *
 *  Created on: Jun 16, 2013
 *      Author: pandit
 */

#include "GCInfo.cpp"
#include <cstdio>
#include <iostream>
#include <list>
using namespace std;

template<class T,int size=0>
class GCPtr {

public:
	static list< GCInfo<T> > listPtr;
	static bool firstTime;
	T *memberPointer;


	GCPtr(T *ptr)
	{
		printf("\ninside the onerloaded constructor of GCptr class.\n");
		memberPointer=ptr;
		GCInfo<T> gcInfo(ptr,size);
		//listPtr.push_front(gcInfo);
	}

	GCPtr()
	{
		printf("\ninside the default constructor of GCptr class.\n");
	}
	virtual ~GCPtr()
	{
		//printf("\ninside the destructor of GCptr class. list count:%d\n",listPtr.size());

	}

//	GCInfo<T> containsPtr(T *ptr)
//	{
//		list<GCInfo<T> >::iterator itr;
//		itr=listPtr.begin();
//		for(;itr!=listPtr.end();itr++)
//		{
//			GCInfo gcInfo=*itr;
////			if(gcInfo.memberPtr==ptr)
////				return gcInfo;
//		}
//		return NULL;
//	}
//
//	GCInfo<T> clearReferenceCount()
//		{
//			list<GCInfo<T> >::iterator itr;
//			itr=listPtr.begin();
//			for(;itr!=listPtr.end();itr++)
//			{
//				GCInfo gcInfo=*itr;
//				//gcInfo.referenceCount=0;
//			}
//		}
};

