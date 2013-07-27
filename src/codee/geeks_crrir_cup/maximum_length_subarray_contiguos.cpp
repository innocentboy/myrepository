/**
Find the longest
subarray which consists of numbers that can be arranged in a continuous sequence.
For ex- {4,5,1,5,7,6,8,4,1}
output-{5,7,6,8,4}.Find the longest.

*/

#include<cstdio>
#include<algorithm>
#define N 1000
using namespace std;
int a[N];
int main()
{

   int i,j,k,n;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   int start=0,end=0,max=-1,min=N,max_len=0,f_start=0,f_end=0,len=1;
   min=max=a[0];
   for(i=1;i<n;i++)
   {
      if(a[i]>max) max=a[i];
      else if(a[i]<min) min=a[i];
      if(max-min==i-start) len++;
      else
      {
        if(len>max_len){
             max_len=len;
             f_start=start;f_end=i;

        }
        start=i;
        len=1;max=min=a[i];
      }
   }
   printf("\nprint that sequence..\n");
   for(i=f_start;i<=f_end;i++)
   printf("%d ",a[i]);
   return 0;
}
