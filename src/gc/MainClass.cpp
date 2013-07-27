/*
 * MainClass.cpp
 *
 *  Created on: Jun 16, 2013
 *      Author: pandit
 */

#include "MainClass.h"
#include <list>
#include <iostream>
#include <cstdio>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


/**
START OF Iter CLASS.
*/
template<class T>
class Iter {
    T *ptr;
    T *begin;
    T *end;
    unsigned length;
public:
	Iter()
	{
		//printf("\ninside the iter constructor.");
		ptr=begin=end=NULL;
		length=0;
	}
	Iter(T *p,T *s, T *e)
	{
	    ptr=p;
	    begin=s;
	    end=e;
	    length=end-begin;
    }
	virtual ~Iter()
	{
		//printf("\ninside the destructor..\n");
	}

	unsigned size()
	{
       return length;
    }

	/**
	some operator overloading.
	*/
	T &operator*()
	{

	   return *ptr;
    }
    Iter operator++()
    {
       ptr++;
       return *this;
    }

    Iter operator--()
    {
       ptr--;
       return *this;
    }
    T &operator[](int index)
    {

       /* if(ptr+index>=end||ptr+index<begin)
        return temp;
        else*/
        return ptr[index];
    }
    bool operator==(Iter<T> &o)
    {
        return (this->ptr==o.ptr);
    }
    bool operator!=(Iter<T> &o)
    {
        return (this->ptr!=o.ptr);
    }
};

/**
END OF Iter CLASS.
*/


/**
START OF GCInfo CLASS
*/
template<class T> class GCInfo {

public:
	T *memberPtr;
	unsigned  referenceCount;
	bool isArray;
	unsigned  arraySize;

	GCInfo(T *ptr,unsigned size=0)
	{

		referenceCount=1;
		memberPtr=ptr;
		isArray=false;
		if(size>0)
		isArray=true;
		arraySize=size;
	}


	virtual ~GCInfo()
	{
	}

	bool operator==(const GCInfo &obj)
	{
	    return (this->memberPtr==obj.memberPtr);
    }
};

/**
END OF GCInfo CLASS.
*/


/**
START OF GCPtr CLASS.
*/
template<class T,int size=0>
class GCPtr {

public:
    static list< GCInfo<T> > listPtr;
	static bool firstTime;
	T *memberPointer;
    bool isArray;
    unsigned arraySize;
    typedef Iter<T> GCIterator;
	GCPtr(T *ptr=NULL)
	{

		if(firstTime==true) atexit(shutdown);
        firstTime = false;
		typename list< GCInfo<T> >::iterator itr;
        itr=containsPtr(ptr);
        if(itr!=listPtr.end())
        {

            (itr)->referenceCount++;
        }
        else{
		GCInfo<T> gcInfo(ptr,size);
		listPtr.push_front(gcInfo);
        }
        memberPointer=ptr;

        if(size>0)
           isArray=true;
        else
           isArray=false;
        arraySize=size;

	}

	virtual ~GCPtr()
	{
		printf("\ninside the destructor of GCptr class Before collect: list count:%d\n",listPtr.size());
        typename list< GCInfo<T> >::iterator itr;
        itr=containsPtr(memberPointer);
        itr->referenceCount--;
        if(collect())
           printf("\nsome item is removed from the list.\n");
        else
           printf("\nno items deleted from the list..\n");
        printf("\ninside the destructor of GCptr class after collect: list count:%d\n",listPtr.size());
	}


	typename list<GCInfo<T> >::iterator containsPtr(T *ptr)
	{
		typename list<GCInfo<T> >::iterator itr;
		itr=listPtr.begin();
		for(;itr!=listPtr.end();itr++)
		{
			if(itr->memberPtr==ptr)
            return itr;
		}
		return itr;
	}



    /**
    Overloaded operators of the class.
    */
    T &operator*()
    {
        return *memberPointer;
    }

    operator T*()
    {
      return memberPointer;
    }


/**
some confustion in this function.
*/
    T* operator =(T *p)
    {
        typename list< GCInfo<T> >::iterator itr;
        itr=containsPtr(memberPointer);
        itr->referenceCount--;
        itr=containsPtr(p);
        if(itr!=listPtr.end())
        {
            itr->referenceCount++;
        }
        else{
		GCInfo<T> gcInfo(p,size);
		listPtr.push_front(gcInfo);
        }
        memberPointer=p;
        if(size>0)
           isArray=true;
        else
           isArray=false;
        arraySize=size;
        return p;
    }


    GCPtr operator =(GCPtr &rv)
    {
        typename list< GCInfo<T> >::iterator itr;
        itr=containsPtr(memberPointer);
        itr->referenceCount--;
        itr=containsPtr(rv.memberPointer);
        itr->referenceCount++;
        memberPointer=rv.memberPointer;
        isArray=rv.isArray;
        arraySize=rv.arraySize;
        return *this;
    }


    /**
    collect function.
    */
    static bool collect()
    {
        bool findRemoved=false;
        typename list< GCInfo<T> >::iterator itr;
        do{
        for(itr=listPtr.begin();itr!=listPtr.end();itr++)
        {

          if(itr->referenceCount>0)
          continue;
          findRemoved=true;
          listPtr.remove(*itr);
          if(itr->memberPtr){
          if(itr->isArray)
          {
            delete[] itr->memberPtr;
          }
          else
            delete itr->memberPtr;
          }
          break;
        }
        }while(itr!=listPtr.end());
        return findRemoved;
    }

    /**
    shut down function ..
    */
    static void shutdown(void)
    {
      printf("\nshut down function is called\n");
      typename list< GCInfo<T> >::iterator itr;
      if(listPtr.size()==0)
      {
          printf("\nno items present to be deleted in the list..\n");
          return;
      }
      itr=listPtr.begin();
      for(;itr!=listPtr.end();itr++)
      {
          itr->referenceCount=0;
      }
      collect();
    }

    Iter<T> begin()
    {
       return Iter<T>(memberPointer,memberPointer,memberPointer+arraySize);
    }

    Iter<T> end()
    {
       return Iter<T>(memberPointer+arraySize,memberPointer,memberPointer+arraySize);
    }

};

/**
END OF GCPtr CLASS.
*/




void createSimplePointer()
{

    int *a=new int(100);
	//GCPtr<int> ptr(a);
	GCPtr<float,5> arr=new float[5];
/*	GCPtr<int> ptr1;
	GCPtr<int> ptr2;
    GCPtr<int> ptr3(new int(500));
	ptr1=new int(2000);
*/

	/**
	this is very important statement. It is calling the destructor for ptr1 class without going out of scope of
	this  variable.
	*/
	//ptr2=ptr1;
    //printf("\nvalue 1:%d\n",*ptr);

    /**
    Traversing the array through iterator.
    */
    GCPtr<float>::GCIterator iter=arr.begin();
    GCPtr<float>::GCIterator end=arr.end();

    int i=0;
    for(i=0;i<iter.size();i++)
    {
        iter[i]=i;
    }
    printf("\nprint the value..\n");
    iter=arr.begin();

    /**
    some confution regarding the way this iter opertaor (!=) overloading is working.
    */
    for(;end!=iter;++iter)
    {
       printf("%f ",*iter);
    }


}

template<class T,int size> list< GCInfo<T> >  GCPtr<T,size>::listPtr;
template<class T,int size> bool  GCPtr<T,size>::firstTime=true;

int main()
{
	createSimplePointer();
	return 0;
}
