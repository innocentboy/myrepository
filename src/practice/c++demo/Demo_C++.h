#include<iostream>
#include<string>
#include<sstream>
//#include<string.h>
using namespace std;

/**
This file contains the header information of implementaion file.
*/
class Point {
public:
  double x, y;
  void offset(double offsetX, double offsetY);
  void print();
  Point() {
    x = 0.0; y = 0.0; //cout << "Point instance created";
  }
  Point(Point &o)
  {
    x=o.x;
    y=o.y;
  }
};

class Vector {
public:
  Point start, end;
  void offset(double offsetX, double offsetY);
  void print();
};

class MITStudent {
public:
  char *name;
  int studentID;
};


class  Vehicle  {
protected :
    string  license ;
    int  year ;
public :

 Vehicle( const  string  &myLicense ,  const  int  myYear):license(myLicense),  year(myYear)  {
       cout<<"We are in the vehical class.."<<endl;
     }
   ~Vehicle()
   {
       cout<<endl<<"We are in the vehical class destrucor.."<<endl;
    }
  virtual const  string  getDesc()  const=0;
   const  string  &getLicense()  const  {return  license;}
   const  int  getYear()  const  {return  year;}
 };

 class  Car  :  public  Vehicle  {  //  Makes  Car  inherit  from  Vehicle
 string  style;
 public :
 Car( const  string  &myLicense ,  const  int  myYear ,  const  string
&myStyle) :  Vehicle(myLicense ,  myYear),  style(myStyle)  {
        cout<<"We are in the Car class.."<<endl;
    }
   ~Car()
   {
        cout<<endl<<"We are in the Cars class destrucor.."<<endl;
    }
 const  string  Car::getDesc() const;
 const  string  &getStyle()  {return  style;}

};

class IntegerArray {
public:
  int *data;
  int size;

  IntegerArray(int size) {
    data = new int[size];
    this->size = size;
  }

    ~IntegerArray () {
        delete[] data;
        cout<<endl<<"We are in the Integer class destrucor.."<<endl;

    }
    IntegerArray(IntegerArray &o)
    {
        size=o.size;
        data=new int[size];
    }
};

