#include "Headers.h"
#include "Date.h"
#include "Exception.cpp"
#include "VectorDemo.cpp"
#include "Storable.cpp"
#include "InheritanceDemo.cpp"

/**
Demo regarding the string..
*/
void string_demo()
{

//    string s("hfkshfkhakdfa");
//    const char *str=s.c_str();
//    printf("\nstr:%s\n",str);

//     string s1="hello";
//     string s2="hello";
//     if(!s1.compare(s2))
//       printf("\nboth are pointing to the same string literal.\n");
//    else
//        printf("\nboth are pointing to the different string literal.\n");

//      string s;
//      printf("\nplease enter your name..\n");
//      getline(cin,s);
//      cout<<"hello"<<"  "<<s;


/**
displaying the output through the ostream.
*/
        ostream_iterator< string > oo(cout);
        *oo="hello";
        oo++;
        *oo="  sanjay";
        *oo="\n";

/**
taking the input from the iterator  and  displaying it to the screen.
*/
       istream_iterator< string > cinput(cin);
       string s1=*cinput;
       cinput++;
       string s2=*cinput;
       cout<<s1<<"   "<<s2;

}

/**
vector related demo
*/

/*
this fuction is used by the iterator of the vector.
*/
bool gt_2(int &o)
{
    return o>2;
}

void vector_demo()
{
   vector<int> vec;
   typedef vector<int>::const_iterator itrVec;
   for(int i=0;i<5;i++)
   {
      vec.push_back(i);
   }
   itrVec i=find_if(vec.begin(),vec.end(),gt_2);

//   for(itr=vec.begin();itr!=vec.end();itr++)
//   {
//      printf("%d ",*itr);
//   }

    printf("\nval:%d  countvalue:%d\n",*i,count_if(vec.begin(),vec.end(),gt_2));



}

/**
this gives the testing related to enum values..
*/
void enum_demo()
{
    enum keyboard{AUTO,BREAK,SHIFT};
    keyboard key=keyboard(0);
    switch(key)
    {
      case  AUTO:
                    printf("\nthis is auto type..\n");
                    break;
      case  BREAK:
                    printf("\nthis is break type..\n");
                    break;

      case  SHIFT:
                    printf("\nthis is shift type..size:%d\n",sizeof(key));
                    break;

      default:
                    printf("\nthis is default value..\n");
                    break;
    }




}

/**
This is normal declaration related test function
*/
void check_declaration()
{
/*
  checking the notion of const with pointer variables.
*/
//    int x=5,y=10;
//    int* const p=&x;
//    *p=1;
//    printf("\nx:%d sixz of bool:%d\n",*p,sizeof(char));

/*
checking the notion of declaration related to string..
*/
//   char *p="string";
//   char *q="string";
//   printf("\nstr:%s  addressP:%u  addressQ:%u\n",p,p,q);


/*

*/
   int x=4,y=10;
   int *ptr=(int *)&x;
   int &r=x;
   r++;
   r=y;
   printf("\nx:%d\n",r);

}


/**
test function for class related data..
*/
void class_demo()
{
   Date date;
   printf("\ndate:%d  month:%d  year:%d\n",date.day(),date.month(),date.year());
   cout<<"rep: "<<date.string_rep();
}

/**
test function for exception handling..
*/

/*
some problem while trying to map the exception to some different exception through set_unexpected()
method. c++ strastroup page:391
*/
void throwMapExceptionClass() throw(MapExceptionClass)
{
     printf("\nunexpected exception is called..\n");
     throw MapExceptionClass();
}

void my_unexpected() {
  cout << "unexpected exception thrown";
}

void exception_handling_demo() throw(DerivedException)
{
    int x=0;
    STC xx(throwMapExceptionClass);
    //std::set_unexpected(my_unexpected);
    try
    {
        if(!x){
           throw VectorDemo();
        }

        else
        {
          printf("\nNo error is repported.\n");
        }
    }
    catch(DerivedException &ex)
    {
        printf("\n inside the cache of exception_handling_demo method\n");
        ex.print_exception();
        throw exception();
    }

    if(uncaught_exception())
    {
      printf("\nexception is thrown but not caught properly..\n");
    }

    printf("\nprintf function after catch ..\n");

}



/**
test function for stl ..
*/
void stl_demo()
{
  printf("\ninside the stl_demo c++\n");
}


/**
test fuction for demonstrating the multiple inheritance concepts. inheritance concepts..
*/
void class_hieracrchy_demo()
{
    const char *s="radio";
    //Storable ss(s);
     Radio r(s);
     RadioClone rc(s);
}

/**
test function for checking inheritance concepts.
*/
void inheritance_concept_demo()
{
    //C c;
//    A a;
//    B b;
//    a=b;
//    a.fun_A();

    A *a;
    B *b=new B();
    C *c=new C();
    //b=c;
    b->fun_A();

}




/**
this is our main function..
*/
int main()
{
    cout << "Hello world!" << endl;
    //string_demo();
    //vector_demo();
    //enum_demo();
    //check_declaration();
    //class_demo();
    //stl_demo();
    //class_hieracrchy_demo();
    inheritance_concept_demo();


//std::set_unexpected(throwMapExceptionClass);
//     try{
//       exception_handling_demo();
//     }
//
//     catch(DerivedException &ex)
//     {
//         ex.print_exception();
//         ex.own_print_exception();
//         printf("\nexception is progated in main function\n");
//     }
//
//     catch(exception &e)
//     {
//         printf("\nthrows unexpected error..\n");
//
//     }
//     catch(std::bad_exception &bad)
//     {
//       printf("\na bad exception is thrown..\n");
//     }
//     catch(Size &e)
//     {
//         printf("\nthrows unexpected error..of size class. error occured in costructing the class. \n");
//
//     }
//     catch(MapExceptionClass &ex)
//     {
//            printf("\ncaught MapExceptionClass  exception type..\n");
//     }


    return 0;
}
