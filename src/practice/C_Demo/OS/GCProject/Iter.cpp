
#include "iter.h"


template<class T> Iter<T>::Iter()
{
		//printf("\ninside the iter constructor.");
		ptr=begin=end=NULL;
		length=0;
}

template<class T> Iter<T>::Iter(T *p,T *s, T *e)
{
	    ptr=p;
	    begin=s;
	    end=e;
	    length=end-begin;
}

/*
template<class T> virtual Iter<T>::~Iter()
{
		//printf("\ninside the destructor..\n");
}

*/

template<class T> unsigned Iter<T>::size()
{
       return length;
}


/**
some operator overloading.
*/

template<class T> T& Iter<T>::operator*()
{
    return *ptr;
}

template<class T> Iter<T> Iter<T>::operator++()
{
    ptr++;
    return *this;
}

template<class T> Iter<T> Iter<T>::operator--()
{
       ptr--;
       return *this;
}

template<class T> T& Iter<T>::operator[](int index)
{

       /* if(ptr+index>=end||ptr+index<begin)
        return temp;
        else*/
        return ptr[index];
}

template<class T> bool Iter<T>::operator==(Iter<T> &o)
{
        return (this->ptr==o.ptr);
}

template<class T> bool Iter<T>::operator!=(Iter<T> &o)
{
        return (this->ptr!=o.ptr);
}

