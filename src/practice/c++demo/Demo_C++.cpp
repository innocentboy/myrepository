/**
This file contains the basic concepts of C++.
*/

#include "Demo_C++.h"
#include<cstdio>
#include<iostream>]
#include<algorithm>
#include<string>
#include<fstream>
#define N 1000
using namespace std;

/**
This function deals with the array parts. This is a kind of generic array.
*/
 template <class T>
class ArrayTemplate
{
   private:
        int size;
        T *data;
   public:
        ArrayTemplate(int size)
        {
           this->size=size;
           data=new T[size];
        }
        ~ArrayTemplate()
        {
           delete []data;
           cout<<"indside destrctor"<<endl;
        }
        ArrayTemplate(ArrayTemplate &o)
        {
            size=o.size;
            data=new int[size];
            for(int i=0;i,o.size;i++)
              data[i]=o.data[i];
        }

        T getData(int n)
        {
            return data[n];
        }
        void setData(int n,T value)
        {
            data[n]=value;
        }
        T operator[](int i)
        {
          return data[i];
        }
};

void array_helper_method()
{
    ArrayTemplate<int> arrInt(5),arrInt2(5);
    ArrayTemplate<char> arrChar(5);
    arrInt.setData(0,1);
    arrInt.setData(1,3);
    arrInt.setData(2,5);
    arrChar.setData(0,'a');
    arrChar.setData(1,'c');
    arrChar.setData(2,'e');
    arrInt2=arrInt;
    cout<<"Int Array Value:"<<arrInt.getData(0)<<"  "<<arrInt2.getData(2)<<"  special: "<<arrChar[1]<<endl;
    cout<<"Int Char Value:"<<arrChar.getData(0)<<"  "<<arrChar.getData(2)<<endl;
}



/**
Concepts related to the classes.
*/


void Point::offset(double offsetX, double offsetY) {
  x += offsetX; y += offsetY;
}
void Point::print() {
  cout << "(" << x << "," << y << ")";
}
void Vector::offset(double offsetX, double offsetY) {
  start.offset(offsetX, offsetY);
  end.offset(offsetX, offsetY);
}
void Vector::print() {
  start.print();
  cout << " -> ";
  end.print();
  cout << endl;
};

  const  string  Car::getDesc() const //  Overriding  this  member  function
 {
     ostringstream  ss;
     ss<<year;
     return  ss.str()  + "  "  +  style  +  ":  "  +  license;

  }



/**
This function related to the operations related to the MITStudent Class.
*/
void class_demo_MITStudent()
{
    MITStudent student1;
    MITStudent student2;
    student1.name = "Geza";
    student1.studentID = 123456789;
    student2.name = "Jesse";
    student2.studentID = 987654321;
    cout << "student1 name is" << student1.name << endl;
    cout << "student1 id is" << student1.studentID << endl;
    cout << "student2 name is" << student2.name << endl;
    cout << "student2 id is" << student2.studentID << endl;
}




/**
This function related to the operations related to the Vector Class.
*/


void class_demo_Vector()
{
    Vector vec1,vec2;
    Point p1,p2;
    p1.x=5;p1.y=10;
    p1.print();
    vec1.start.x = 3.0;
    vec1.start.y = 4.0;
    vec1.end.x = 5.0;
    vec1.end.y = 6.0;

    vec2.start = vec1.start;
    vec2.start.x = 7.0;
    vec1.print();

}


/**

*/
void class_demo_Car()
{
    Car  *c=new Car("VANITY",2003,"blue") ;
    Vehicle  * vPtr=c;
    cout  <<  vPtr -> getDesc () ;
    delete c;
}


/**

*/
void class_demo_IntegerArray()
{
    IntegerArray arr(2);
    arr.data[0] = 4; arr.data[1] = 5;
    if (true) {
      IntegerArray b = arr;
      b.data[0]=10;
   }
    cout <<"integer Array's value:"<< arr.data[0] << endl;
}


/**
This shows the use of templates.
*/
template <class T>

   T sum_template(T a,T b){
        return a+b;
   }


/**
This function reads the input from input file and write the values to output files.
*/
void file_in_out_helper()
{
    ifstream source("in.txt");
    ofstream destination("out.txt");
    int x;
    char s[20];
    source>>s;
    source>>x;
    cout<<"values: "<<s<<"  "<<x<<endl;
    destination<<s;
    destination<<x;

}



/**
Start of the main function..
*/
int main()
{
     int a=5,&x=a;
     int *ptr=&a;
     cout<<"this is C++ demo.."<<a<<endl<<endl;
     //class_demo_MITStudent();
     //class_demo_Vector();
     //class_demo_Car();
     //class_demo_IntegerArray();
     //array_helper_method();
     //file_in_out_helper();
     //printf("\nsum value:%d  %f\n",sum_template<int>(4,5),sum_template<double>(3.5,7.4));
     return 0;
}

