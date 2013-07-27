#include <iostream>
#include "GCPtr.cpp"

using namespace std;


void createSimplePointer()
{

    int *a=new int(100);
	//GCPtr<int> ptr(a);
	GCPtr<float,5> arr=new float[5];
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
    printf("\nGC Demo Project\n");
	createSimplePointer();
	return 0;
}
