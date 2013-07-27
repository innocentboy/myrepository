/**
simply implements the binary search in an array..
*/

#include<cstdio>
#define N 1000
using namespace std;

int binary_search(int a[],int n,int k)
{
    int low,high,mid,i;
    low=0;high=n-1;
    while(low<high)
    {
      mid=low+(high-low)/2;
      if(k<=a[mid]) high=mid;
      else low=mid+1;
    }
    return low;
}

int main()
{
   int i,j,k=12,n=8;
   int a[]={1,3,6,7,8,9,10,12};
   printf("\nindex of element in array:%d\n",binary_search(a,n,k));
   return 0;
}
