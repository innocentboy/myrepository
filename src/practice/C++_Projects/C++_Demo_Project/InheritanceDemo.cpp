#include "Headers.h"

class A
{
  public:
   A()
   {
     printf("\ndefault constructor of A\n");
   }
   ~A()
   {
     printf("\n destructor  of A\n");
   }
   virtual void fun_A()
   {
      printf("\nfunction of A\n");
    }
    void fun_A_own()
    {
      printf("\nown function of class A.\n");
    }

};

class B:protected A
{
   public:
    B()
   {
     printf("\ndefault constructor of B\n");
   }
   virtual ~B()
   {
     printf("\n destructor  of B\n");
   }
    void fun_A()
   {

       fun_A_own();
       printf("\n overrriden function in B function of A\n");
    }


};


class C:public B
{
   public:
   C()
   {
     printf("\ndefault constructor of C\n");
   }
   virtual ~C()
   {
     printf("\n destructor  of C\n");
   }
   void fun_A()
   {

       printf("\n overrriden function in C function of A\n");
    }
    void fun_C()
    {
        printf("\nthis is the function of c class\n");
    }

};


