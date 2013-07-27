#ifndef _STORABLE_CPP
#define _STORABLE_CPP
#include "Headers.h"
class Storable
{
   const char *store;
   Storable(const Storable& obj);
   Storable& operator =(Storable & obj);
  public:

    Storable()
    {
      printf("\ndefault constructor for strorable class.\n");
      read();
    }

    Storable(const char *str)
    {
        printf("\nconstructor of strorable iscalled \n");
        store=str;
    }
    virtual ~Storable()
    {
        printf("\n destructor of strorable iscalled \n");
    }

    const char *getStore() const
    {
        return store;
    }

    virtual void read()
    {
      printf("\nread method of storable is caalled only once..\n");
    }
    virtual void write()=0;

};

class Transmitter: public virtual Storable
{
   public:
    Transmitter(const char *str):Storable(str)
    {
        //Storable::read();
        printf("\nconstructor of Transmitter..\n");
    }
    void write()
    {

    }
    //void read();

};


class Receiver: public virtual Storable
{
  public:
     Receiver(const char *str):Storable(str)
     {
        //Storable::read();
        printf("\nconstructor of receiver..\n");
     }
     void write()
     {

     }
     //void read();
};

class Radio: public Receiver,public Transmitter
{
    public:
      Radio(const char *str):Receiver(str),Transmitter(str)
      {
        printf("\nconstructor of Radio\n");
      }
      void write()
      {
         printf("\nthis is write function of radio.\n");
      }
//      void read()
//      {
//          printf("\nthis is read function of radio.\n");
//      }

};

class RadioClone:public Receiver
{
    public:
      RadioClone(const char *str):Receiver(str)
      {
        printf("\nconstructor of RadioClone\n");
      }
      void write()
      {
         printf("\nthis is write function of radio.\n");
      }

};

#endif
