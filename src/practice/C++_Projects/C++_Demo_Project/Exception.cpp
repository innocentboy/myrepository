#ifndef _EXCEPTION_
#define _EXCEPTION_

#include "Headers.h"

typedef void (*unexpectd_handler)();
unexpectd_handler std::set_unexpected(unexpectd_handler);

class STC
{
   unexpectd_handler old;
   public:
   STC(unexpectd_handler t)
   {
        printf("\ninside the constructor of STC\n");
        old=std::set_unexpected(t);
   }
   ~STC()
   {
         printf("\ninside the destructor of STC\n");
         std::set_unexpected(old);
    }

};

class MyException
{
  public:
  virtual  void print_exception()
    {
        printf("\nthis is MyException print method..\n");
    }
};

class Size{};

class DerivedException:public MyException
{
    public:

    DerivedException()
    {
        printf("\ninside the constructor of DerivedException\n");
        throw Size();
    }

    ~DerivedException()
    {
        printf("\ninside the destructor. of DerivedException\n");
    }

    void print_exception()
    {
        printf("\n overrieden function by DerivedException print method..\n");
    }

    void own_print_exception()
    {
        printf("\n own_print_exception.. of DerivedException\n");
    }

};


class MapExceptionClass: public DerivedException //it is creating some problem
{
  public:
  MapExceptionClass()
  {
      printf("\ninside the constructor of MapExceptionClass..\n");
    }

    ~MapExceptionClass()
    {
            printf("\ninside the destructor of MapExceptionClass\n");
    }

};

#endif
