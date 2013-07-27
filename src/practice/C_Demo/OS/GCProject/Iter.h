#ifndef _Iter_GC
#define _Iter_GC

#include<cstdio>
#include<iostream>
#include<list>

using namespace std;

template<class T>
class Iter {
    T *ptr;
    T *begin;
    T *end;
    unsigned length;
public:
	Iter();
	Iter(T *p,T *s, T *e);
	virtual ~Iter();
	unsigned size();

	/**
	some operator overloading.
	*/
	T &operator*();
    Iter operator++();
    Iter operator--();
    T &operator[](int index);
    bool operator==(Iter<T> &o);
    bool operator!=(Iter<T> &o);
};

#endif
