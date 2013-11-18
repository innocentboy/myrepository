//
//  C++Demo.cpp
//  PrjPractice
//
//  Created by Sanjay on 10/31/13.
//  Copyright (c) 2013 TCS. All rights reserved.
//

#include "C++Demo.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include<queue>

using namespace std;

class Test
{
public:
    ~Test() { cout << "Destroying Object\n"; }
public:
    Test() { cout << "Object Created\n"; }
    Test(const Test &t)
    {
        cout<< "copy construcot is called\n";
        
    }
    
    Test & operator =(const Test &t)
    {
        cout<<"assignmeb is called\n";
        return *this;
    }
    
    friend void destructTest(Test* );
};

class Base
{
public:
    virtual void fun ( int x=0 )
    {
        cout << "Base::fun(), x = " << x << endl;
    }
};

class Derived : public Base
{
public:
    virtual void fun ( int x=10 )
    {
        cout << "Derived::fun(), x = " << x << endl;
    }
};

// Only this function can destruct objects of Test
void destructTest(Test* ptr)
{
    delete ptr;
    cout << "Object Destroyed\n";
}

/**
 Function for checking the copy and default constructor.
 */
void checkDefaultAndCopyConstructor()
{
    Test *t=new Test ;
    Test t1=*t;
    Test t2;
    t2=*t;

}

/**
 Check for virtual function.
 */

struct employee
{
    int     emp_id;
    char    name[0];
    int     name_len;
    
}emp;

void checkVirtualFunction()
{
    
    struct employee *e =( struct employee *) malloc(sizeof(*e) + sizeof(char) * 20);
    e->emp_id 	= 100;
    e->name_len	= strlen("Geeks For Geeks");
    strncpy(e->name, "Geeks For Geeks", e->name_len);
    printf("\nsie of struct:%ld  :%ld\n",sizeof(emp),sizeof(e));
    printf("\nName:%s\n",e->name);
    
    Derived d1;
    Base *bp = &d1;
    bp->fun();
}

/**
 Function for printing the string Corresponding  to the given Number:
 */
void numToStrHelper(int n) {
    if (n == 0) return;
    numToStrHelper((n-1)/26);
    cout << (char)('a'+(n-1)%26);
}

void numTostr(int n) {
    numToStrHelper(n/26);
    cout << (char)('a'+n%26);
    cout<<"\n";
}


/**
 check two arrays having same element.
 */
void checkSameElement()
{
    int a[]={6,2,5,4,3,6};
    int b[]={2,3,6,5,4,7};
    int n=6,i,ans=0;
    for(i=0;i<n;i++)
        ans^=a[i];
    for(i=0;i<n;i++)
        ans^=b[i];
    if(!ans)
        printf("\n Both arrays. having the same value..");
    else
        printf("\n Both arrays have different value.");
}

/**
 Find whether the given array contains the consequitive element.
 */
void containsConsecutive()
{
     int a[]={6,7,4,5,4,222222};
     int n=6,i,min,max,sum=0;
      min=99999;max=-99999;
    for(i=0;i<n;i++)
    {
        sum^=a[i];
        if(a[i]<min) min=a[i];
        else if(a[i]>max) max=a[i];
    }
    if(!((max-min)==n-1))
    {
        printf("\n*********** elements are not consecutive..");
        return;
    }

    for(i=max;i>=min;i--)
        sum^=i;
    if(!sum)
        printf("\n elements are consecutive..");
    else
        printf("\n elemnts are not consecutive...");
        
}

/**
 Print two elements of the array having minimum differencr between them..
 */
void findMinimumDifference()
{
}

/**
 Finding minimum jump to reach the end of the array.
 */
void minimumJumpToReachEndOfArray()
{
    
    int a[]={1,0,4,5,4,5};
    int n=6,i,cur=0,last=0,ret=0;
    for(i=0;i<n;i++)
    {
        if(i>last)
        {
            last=cur;
            ret++;
        }
        cur=max(cur, i+a[i]);
    }
    if(cur>n)
        printf("\n Minimum jump is:%d",ret);
    else
        printf("\n Cann't reach at the end..");
}

/*
Related to C++ syntax..
 */
void compareStr()
{
    const char *s1="a";
    const char *s2="aa";
    if(s1==s2)
        printf("\nBoth pointing to same..");
    else
        printf("\nBoth pointing to different..");
    int *a=new int(100);
    delete a;
}

/**
 Related to polymorphism.
 */

void friendfun()
{
    printf("\ni:");
}

class A
{
    
    const int j;// Const & reference members must be intialized explicity by constructor..
public:
    
    //friend  function..
    friend void friendfun();
    
    int i;
    A(int x):j(x)
    {
        printf("\nConstructor of A is called..");
        i=x;
    }
    A(const A& o):j(o.j) //
    {
        printf("\n Copy constructor of A is called..");
    }
    A& operator =(const A& o)
    {
        printf("\nAssignment opertaor is called.:%d",o.i);
        this->i=o.i;
        return *this;
    }
    
    ~A()
    {
        printf("\nDestructor of A is called..");
    }
    
    void fun()
    {
        printf("\n This is fun..");
    }
    
   static bool compare(int &a,int &b)
    {
        return a>b;
    }
    
    void fun1(vector<int> &num)
    {
        printf("\nThis is fun1..");
        fun();
        sort(num.begin(), num.end(),compare);
    }
    
    A  operator+(const A& o)
    {
        printf("\noperator + is called :%d ",o.i);
        
        A temp(0);
        temp.i=this->i+o.i;
        return temp;
    }
    
    operator int ()
    {
        return this->i;
    }
    
//    friend A operator+(const A& o,int i);
//    friend A operator+(int i,const A& o);
    
};

A operator+(const A& o1,const A& o2)
{
    A temp(0);
    temp.i=o1.i+o2.i;
    return temp;
}

A  operator+(const A& o,int i)
{
    A temp(0);
    temp.i=o.i+i;
    return temp;
    
}
A  operator+(int i,const A& o)
{
    A temp(0);
    temp.i=o.i+i;
    return temp;
}

void polymorphic()
{
    A a(10),b(3);
  //  A arrar[={A(1),A(2)};
    b=11+a;
    int i=b;
    printf("\ni: %d %d",b.i,i);
    
    
//    vector<int> v;
//    for(int i=0;i<5;i++)
//    {
//        v.push_back(i);
//    }
//    a.fun1(v);
//    printf("\n after sorting..\n");
//    for(int i=0;i<5;i++)
//        printf("%d ",v[i]);
    
}


/**
 1.Only a few assumptions are made about the meaning of a user-defined operator. In particular, operator=, operator[], operator(), and operator-> must be nonstatic member functions; this ensures that their first operands will be lvalues .
 2.Because of historical accident, the operators = (assignment), & (address-of), and , (sequencing; §6.2.2) have predefined meanings when applied to class objects. These predefined meanings can be made inaccessible to general users by making them private:
 3.In particular, it is not possible to define an operator function that operates exclusively on pointers.
 4.A friend class must be previously declared in an enclosing scope or defined in the non-class scope immediately enclosing the class that is declaring it a friend. For example:
 5.A friend declaration can be placed in either the private or the public part of a class declaration; it
 6.It follows that a friend function should either be explicitly declared in an enclosing scope or take an argument of its class. If not, the friend cannot be called. For example:
 7.mplicit conversions are not used for non-const reference arguments
 8.An operation modifying the state of a class object should therefore be a member or a global func- tion taking a non-const reference argument (or a non-const pointer argument).
 9.If no type conversions are defined, there appears to be no compelling reason to choose a mem- ber over a friend taking a reference argument, or vice versa.
 10.
 */

/**
 start of the main function.
 */
int main()
{
    
    printf("\nThis is c++ file\n");
    //checkDefaultAndCopyConstructor();
    //checkVirtualFunction();
    //numTostr(730);
    //checkSameElement();
    //containsConsecutive();
    //findMinimumDifference();
    //minimumJumpToReachEndOfArray();
    //compareStr();
    polymorphic();
    
    
    return 0;
}
