#include<cstdio>
#include<list>
#include<iostream>
#include "GCInfo.cpp"
#include "Iter.h"

using namespace std;

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
