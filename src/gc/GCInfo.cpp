/*
 * GCInfo.cpp
 *
 *  Created on: Jun 16, 2013
 *      Author: pandit
 */

#include "stdio.h"
#include "cstdio"

template<class T> class GCInfo {

public:
	T *memberPtr;
	unsigned  referenceCount;
	bool isArray;
	unsigned  arraySize;

	GCInfo(T *ptr,unsigned size=0)
	{
		printf("\ninside the overloaded constructor of GCinfo\n");
		referenceCount=1;
		memberPtr=ptr;
		isArray=false;
		if(size>0)
		isArray=true;
		arraySize=size;
	}

	bool operator==(GCInfo<T> &gcInfo)
	{
		return (this->memberPtr==gcInfo.memberPtr);
	}

	GCInfo()
	{
		printf("\ninside the default constructor of GCinfo\n");
	}
	virtual ~GCInfo()
	{
		printf("\ninside the default deconstructor of GCinfo\n");
		if(isArray){
			delete[]  memberPtr;
		    printf("\nArray's pointer are deleted..\n");
		}
		else{
			delete memberPtr;
		    printf("\nsimple variable is deleted\n");
		}
	}
};


