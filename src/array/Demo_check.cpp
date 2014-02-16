/**
This is just to check the syntax.
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<exception>
#include<typeinfo>
using namespace std;

class B;
int x=15;

class Base
{
  public:
  int x;
  Base()
  {
     x=10;
   }
};

class A:private Base
{
   int a,b;
   public:
   A(int a,int b)
   {
       this->a=a;
       this->b=b;
    }
    A(const A& a)
    {
       this->a=a.a;
       this->b=a.b;
       printf("\nCopy constructor of A is called..");
    }
    ~A()
    {
       printf("\nDestructor is called..");
    }
   friend void sum(A& a);
   friend class B;
};

class B
{
    int x,y;
    public:
    static int stat; //Declaration only..
    void min(const A& a)
    {
        printf("\n %d %d %d",a.a,a.b,::x);
    }

    //Constructor.
    explicit B(int x=0)  //If we want the compiler to explicitly call the constructor not the implicit
                      // conversion from single parameter to B(int ) type automatically.
    {
        this->x=x;
        printf("\nB's construct is called..");
    }
    //Copy constructor..
    B(const B& o)
    {
        printf("\nCopy consructor of B is called..");
        x=o.x;
        y=o.y;
    }
    //Destructor..
    ~B()
    {
       printf("\nDestructor of B is called..");
    }

    //A is friend of this class , so can access the private members of the  class B.
    friend class A;

    static void statfun()
    {
       printf("\nGlbal value:%d local:%d",::x,stat);
    }
    int get_x()
    {
            return x;
    }
    void set_x(int x)
    {
            this->x=x;
    }

    friend B operator +(int ,B);
    friend B operator +(B,int);
};

B operator+(int i,B b)
{
    printf("\noperato overload function is called..");
    B bb;
    i=i+b.get_x();
    bb.set_x(i);
    return bb;
}
B operator+(B b,int i)
{
    B bb;
    i=i+b.get_x();
    bb.set_x(i);
    return bb;
}

void sum(A& a)
{
    printf("\nSum:%d",a.a+a.b);
  //  A a=(const_cast)<A>a;
    a.a=a.a+a.b;
}

int B::stat; //Definition..


/**
Pointer airthmetic on class type..
*/
class base {
int i;
public:
void set_i(int num) { i=num; }
int get_i() { return i; }

virtual void fun(){}

};
class derived: public base {
int j;
public:
void set_j(int num) { j=num; }
int get_j() { return j; }
};


void pointerArithmeticPolymorphic()
{
   /*
   base *b;
   derived d;
   b=&d ;
   b->set_i(5);
   //b->set_j     It is error because base class hasn't any member function like that..
   ((derived *)b)->set_j(10); //we can cast the pointer in derived calss to access derived
                              //class members.

    */

    base *bp;
    derived d[2];
    bp = d;
    d[0].set_i(1);
    d[1].set_i(2);
    cout << bp->get_i() << " ";
    bp++; // relative to base, not derived
    cout << bp->get_i(); // garbage value displayed
}
/**
Member pointers to class of members.
int cl::*d;
int *p;
cl o;
p = &o.val // this is address of a specific val
d = &cl::val // this is offset of generic val
*/

/**
NEW and DELETE

###################################
The nothrow Alternative
###################################

#include <new>
p = new(nothrow) int[32]; // use nothrow option
if(!p) {
cout << "Allocation failure.\n";
else
{

}
This is useful with the comatibility with the older versions of C++  when instead of throwning
an exception on failure on the new it returns the NULL on failure.

######################################
The Placement Forms of new and delete
######################################
There is a special form of new, called the placement form, that can be used to specify an
alternative method of allocating memory. It is primarily useful when overloading the
new operator for special circumstances. There is a default implementation of the
placement new operator, which has this general form:
    p_var = new (location) type;
Here, //location// specifies an address that is simply returned by new.

######################################
Creating a Member Operator Funct
######################################
A member operator function takes this general form:
ret-type class-name::operator#(arg-list)
{
// operations
}
ret-type= return type by that operator.
substitute the operator for the #(suppose / operator is verloaded then #=/)

######################################
Friend function operator overloading
######################################
There are some restrictions that apply to friend operator functions.
First, :
you may not overload the =,(),[], or –> operators by using a friend function
Second, as:
explained in the next section, when overloading the increment or decrement operators,
you will need to use a reference parameter when using a friend functio


*/


/**
Reference concept..
*/
void reference(int &i)
{
        i++;
}

/**
Give demonstartion of Virtual Base classes. It ensures only one copy of Base class will be used in
case of muliple inheritence of same base calss.
*/
class base1{
protected:
int j;
public:
int i;
virtual ~base1()
{
        printf("\nDestructor of base is caled..");
}

};
// derived1 inherits base as virtual.
class derived1 : virtual public base1{
public:
int j;
};
// derived2 inherits base as virtual.
class derived2 : virtual public base1 {
public:
int k;
};
/* derived3 inherits both derived1 and derived2.
This time, there is only one copy of base class. */
class derived3 : public derived1, public derived2 {
public:
int sum;
};

class derived4:private base1
{
    public:
    derived4(int x=0)
    {
          i=x;
    }
    ~derived4()
    {
        printf("\nDestructor of derived4 is called..");
    }

    using base1::i;
    using base1::j;

   virtual  void v_fun()
    {
      printf("\nVirtual function of derived4");
    }
    virtual void pure_v()=0;

};

class derived5:public derived4
{
    public:
    derived5(int x=0)
    {
        j=x;
    }
    ~derived5()
    {
            printf("\nDestructor of derived5 is called.");
    }

    void v_fun()
    {
      printf("\nVirtual function of derived5");
    }

    //Pure virtual function..

    void pure_v()
    {
        printf("\nPure virtual funv=ction is overloaded..");
    }
};

//Virtual base class..
int virtualBaseClass()
{
derived3 ob;
ob.i = 10; // now unambiguous
ob.j = 20;
ob.k = 30;
// unambiguous
ob.sum = ob.i + ob.j + ob.k;
// unambiguous
cout << ob.i << " ";
cout << ob.j << " " << ob.k << " ";
cout << ob.sum;

//derived4 ob4(10);
//cout<<"\nx :"<<ob4.i;

}

/**
Virtual function and it's importance..
1. If derived class does n't contain the redefinition of virtual function then upn calling that
    function it will call the nearest overriden virtual function present in the hierarchy.
*/
void virtualFunction()
{
    derived4 *p;
    derived5 *o5=new derived5;
    p=o5;
    p->v_fun();
    delete p;
}

/**
TypeID specification..
*/
void typeIdSpecification()
{
    base1 *b;
    derived1 d;
    b=&d;
    if(typeid(*b)==typeid(derived1))
        printf("\n it's is pointing to deriived type..");
    else
        printf("\nit's something else.");
    cout<<"\n "<<typeid(d).name();
}


/**
NOTE:
If the cast fails, then dynamic_cast evaluates to null if the
cast involves pointers. If a dynamic_cast on reference types fails, a bad_cast exception
is thrown.

1.static_cast<> Can be applied to scalar and non-scalar type.
2.const_cast<>  Can be applied to pointer and reference  only and of same type only...
3.dynamic_cast<> Can be applied to pointer and reference  only works for polymorphic only..
4.reinterpret_cast<> Can be applied to any type..
*/

/**
Casting specifications..
*/
void castingSpecification()
{
    base *p,b_ob;
    derived *d_p,d_ob;
    p=&b_ob;
    d_p=dynamic_cast< derived* >(p);
    if(d_p)
        printf("\nCast successded..");
    else
        printf("\n cast failed");
}



/**
Template specification..
*/
template<class T>
T sum(T a,T b)
{
  return a+b;
}

void templateSpecification()
{
    int a=5,b=6;
    float c=1,d=2;
    printf("\nint:%d float:%f",sum<int>(a,b),sum<float>(c,d));
}

/**
Exception handling..
*/
void my_THandler()
{
        printf("\nthis is my termination handler handler..");
        exit(1);
}

void my_UnEXHandler()
{
    printf("\nthsi is my unexpected handler...");
}

void fun(int x)throw(int)
{
     set_terminate(my_THandler);
     set_unexpected(my_UnEXHandler);
     try{
     throw 100.0;
     }
     catch(double x)
     {
       printf("\ninside catch of fun.");
       throw;
      }
}

void exceptionHandling()
{
    int i=100;
    try
    {
            printf("\ninside the try blck..");
            fun(i);
    }
    catch(int i)
    {
        if(uncaught_exception())
            printf("\n this exception is already been caught..");
        printf("\nException is caught");
    }
    catch(...){

        printf("\nGeneric catch is handling the exception");
    }
}


int main()
{
      /**  int x=5,i=2;
        int &y=x;
        y++;
        int *p=&x;
      //  delete p;

        printf("\nx:%d y:%d",x,y);
        */
/**
Concepts related to friend functions and friend classes.
Also about teh static members and methods.
*/

/**
        A a(1,2);
        B b=B(5);
        b.min(a);
        B::stat=10;  //static variable.
        B::statfun(); //static function..// Can't be virtual. Can't be declared with const and volatile
        //or b.statfun();       // Can't have both the static and non-static version of a function..
        sum(a);
        sum(a);
*/

/**
Creating Array of B's objects.
*/
 //       B bArray[2]={B(1),B(2)};

/**
Related to pointers.
*/
//        pointerArithmeticPolymorphic();

/**
Reference related..
*/
/*          int i=9;
          reference(i);
          printf("\ni:%d",i);
          */
/**
Operator overloading through friend function.
*/
/*        B b(5);
        b=b+10;
        printf("\nx:%d",b.get_x());
        */

/**
Overloading new and delete.
*/


/**
Virtual base class.
*/
        //virtualBaseClass();

/**
Virtual function property..
*/
//      virtualFunction();

/**
Template specification..
*/
//        templateSpecification();

/**
Exception handling..
*/
//        exceptionHandling();

/**
TypeID specification..
*/
//        typeIdSpecification();

/**
Casting specifications..
*/
        castingSpecification();

        return 0;
}
