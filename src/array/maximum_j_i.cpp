/**
Given an array arr[], find the maximum j – i such that arr[j] > arr[i].

Examples:

  Input: {34, 8, 10, 3, 2, 80, 30, 33, 1}
  Output: 6  (j = 7, i = 1)

  Input: {9, 2, 3, 4, 5, 6, 7, 8, 18, 0}
  Output: 8 ( j = 8, i = 0)

  Input:  {1, 2, 3, 4, 5, 6}
  Output: 5  (j = 5, i = 0)

  Input:  {6, 5, 4, 3, 2, 1}
  Output:-1
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 1000
using namespace std;

int max_j_i(int a[],int n)
{
   int i,j,k,inc[n],dec[n],min_ind=-1,max_ind=-1;
   min_ind=0;inc[0]=a[0];
   for(i=1;i<n;i++)
   {
     inc[i]=min(a[i],inc[i-1]);

   }
   max_ind=n-1;dec[n-1]=a[n-1];
   for(i=n-2;i>=0;i--)
   {
     dec[i]=max(a[i],dec[i+1]);

   }
   int ans=-1;
  /* i = 0;j = 0;
    while (j < n && i < n)
    {
        if (inc[i]<dec[j])
        {
            ans=max(ans, j-i);
            j=j+1;
        }
        else
            i = i+1;
    }*/
    return ans;
}

int main()
{
  int i,j,k,n;
   //int a[]={19, 20, 3, 4, 5, 6, 7, 8, 18, 0};n=10;
  //int a[]={6, 5, 4, 3, 2, 7};n=6;
   int a[]={34, 38, 10, 3, 2, 8, 3, 13, 1};n=9;
  // int a[]={1, 2, 3, 4, 5, 6};n=6;
  printf("\nmaximum length:%d\n",max_j_i(a,n));
  return 0;
}
