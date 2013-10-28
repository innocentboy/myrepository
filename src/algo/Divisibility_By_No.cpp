/**
This file provides the concepts related to how could we find if a number is particularly divisible by
any no or not.

EX: Suppose we have to find wheteher 21 is divisble by 3 or not. (without using /, % , or * operator.)


Note: Suppose for the divisibility of 3. The given no n is divisible by 3 then, n=2*a+b where 0<=b<2
      then for n to divisible by 3 it should also be divisible by;
      =3*a(if it's completely divisible) - (2*a+b)
      =a-b
      it should also be divisible by (a-b) also.
      So getting the value of a and b putting in the equation as n=(n>>1)-(n&1)
      if(n==0) Then it's divisible by 3.
      else It's not divisible by 3.

Similarly we can find the divisibility for 5 as:
      n=4*a+b where 0<=b<4
      So getting the value of a and b putting in the equation as n=(n>>2)-(n&3)
      if(n==0) Then it's divisible by 5.
      else It's not divisible by 5.

Similarly we can find the divisibility for 6 as:
      n=4*a+b where 0<=b<4
      then for n to divisible by 6 it should also be divisible by;
      =6*a(if it's completely divisible) - (2*a+b)
      =2*a-b
      So getting the value of a and b putting in the equation as n=2*(n>>2)-(n&3)
      if(n==0) Then it's divisible by 5.
      else It's not divisible by 5.
*/


#include <iostream>
#include <cstdio>

using namespace std;



/**
Function checks the divisibility by 3.
*/
bool divisibilityBy3(int n)
{
    while(n>0)
    {
      n=(n>>1)-(n&1);
    }
    return n==0;
}

/**
Function checks the divisibility by 3.
*/
bool divisibilityBy6(int n)
{
    while(n>0)
    {
      n=2*(n>>2)-(n&3);
    }
    return n==0;
}

/**
Function checks the divisibility by 3.
*/
bool divisibilityBy9(int n)
{
    while(n>0)
    {
      n=(n>>3)-(n&7);
    }
    return n==0;
}


/**
This is the main functin..
*/
int main()
{
    int n;
    while(scanf("%d",&n)&&n!=-1){
    if(divisibilityBy9(n))
          printf("\nIt's is divisible by 3.\n");
    else
          printf("\nIt is not divisible by 3.\n");
    }

    return 0;
}
