/**
You are given an array of n+2 elements. All elements of the array are in range 1 to n.
And all elements occur once except two numbers which occur twice. Find the two repeating numbers.

For example, array = {4, 2, 4, 5, 2, 3, 1} and n = 5

The above array has n + 2 = 7 elements with all elements occurring once except 2 and 4 which occur twice.
So the output should be 4 2.


Method 1: (Make two equations)
Let the numbers which are being repeated are X and Y. We make two equations for X and Y and the simple
task left is to solve the two equations.
We know the sum of integers from 1 to n is n(n+1)/2 and product is n!. We calculate the sum of
input array, when this sum is subtracted from n(n+1)/2, we get X + Y because X and Y are the two
numbers missing from set [1..n]. Similarly calculate product of input array, when this product is divided from n!,
we get X*Y. Given sum and product of X and Y, we can find easily out X and Y.

Let summation of all numbers in array be S and product be P

X + Y = S – n(n+1)/2
XY = P/n!

Using above two equations, we can find out X and Y. For array = 4 2 4 5 2 3 1, we get S = 21 and P as 960.

X + Y = 21 – 15 = 6

XY = 960/5! = 8

X – Y = sqrt((X+Y)^2 – 4*XY) = sqrt(4) = 2

Using below two equations, we easily get X = (6 + 2)/2 and Y = (6-2)/2
X + Y = 6
X – Y = 2


METHOD:2 XOR.
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<math.h>
#define N 1000
using namespace std;

/**
method 1:
*/
void find_repeat_element_method1(int a[],int n,int nn)
{
    int i,j,k,s=0,p=1,d,x=1,y;
    for(i=0;i<n;i++)
    {
      s+=a[i];
      p*=a[i];
    }
    for(i=1;i<=nn;i++)
    x*=i;
    s-=(nn*(nn+1)/2);
    p=p/x;
    d=(int)sqrt(s*s-4*p);
    printf("\n%d %d repeated elements are:%d %d\n",s,d,(s+d)/2,(s-d)/2);
}


/**
method 2: By using XOR method...
*/
void find_repeat_element_method2(int a[],int n,int nn)
{
    int i,j,k,xorr=0,set_bit;
    for(i=0;i<n;i++)
    {
      xorr^=a[i];
    }
    for(i=1;i<=nn;i++)
    xorr^=i;
    set_bit=(xorr)&(~xorr+1);
    xorr=0;j=0;
    for(i=0;i<n;i++)
    {
        if(a[i]&set_bit)
        xorr^=a[i];
        else j^=a[i];
    }
    for(i=1;i<=nn;i++)
    {
      if(i&set_bit)
      xorr^=i;
      else j^=i;
    }
    printf("\nrepeating elements are:%d %d\n",xorr,j);
}

int main()
{
   int i,j,k,n=7;
   int a[N]={4, 2, 1, 5, 2, 3, 1};
  // find_repeat_element_method1(a,n,n-2);
   find_repeat_element_method2(a,n,n-2);
   return 0;
}
