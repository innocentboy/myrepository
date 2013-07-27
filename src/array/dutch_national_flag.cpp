#include<cstdio>
#include<algorithm>
#define N 100
using namespace std;

/*
this function sort the given having 0's, 1's and 2's by dutch flag algo..
*/
void dutch_sort_0_1_2(int a[],int n)
{
    int i,j,k,low,mid,high;
    low=mid=0;
    high=n-1;
    while(mid<high)
    {
      switch(a[mid])
      {
         case 0:if(a[low]!=a[mid])a[low]^=a[mid]^=a[low]^=a[mid];
                low++;mid++;break;
         case 1:mid++;break;
         case 2:a[high]^=a[mid]^=a[high]^=a[mid];
                high--;
         default :break;
      }

    }
}

/*
this function sort the given having 0's and  1's by dutch flag algo..
*/
void dutch_sort_0_1(int a[],int n)
{
    int i,j,k,low,mid,high;
    low=mid=0;
    //high=n-1;
    while(mid<n)
    {
      switch(a[mid])
      {
         case 0:if(a[low]!=a[mid])a[low]^=a[mid]^=a[low]^=a[mid];
                low++;mid++;break;
         case 1:mid++;break;
         default :break;
      }

    }
}

int main()
{

   int a[N],i,j,n;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   //dutch_sort_0_1_2(a,n);
   dutch_sort_0_1(a,n);
   printf("\nprint the sorted array\n");
   for(i=0;i<n;i++)
   printf("%d ",a[i]);
   return 0;
}
