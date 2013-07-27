#ifndef _Date_H
#define _Date_H

#include "Headers.h"

struct cache
{
    const bool cachhe;
    const string& rep;

   cache(bool b,string &s):cachhe(b), rep(s)
   {

   }

   ~cache()
   {
     printf("\ndestructor for cache is called\n");

   }

};


class Date
{
  int d,m,y;
  cache *ch;
  public:
  string s;
  Date()
  {

      d=m=y=0;
      s=string("string demo");
      //string str("c++ demo");
      ch=new cache(false,s);
      cout<<ch->rep;
  }

  ~Date()
  {
     delete ch;
     printf("\ndestructor for date is called.\n");
  }

  int day() const{
    return d;
  }

   int month() const{
    return m;
  }

  inline int year() const
  {
      return y;
    }
   string string_rep() const{

       if(!ch->cachhe)
       {
//          string s("updated value");
//          ch->rep=string("updated value");
        }
        return ch->rep;

    }

};

#endif
