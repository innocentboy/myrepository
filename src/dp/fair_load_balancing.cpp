/**
PROBLEM STATEMENT: http://community.topcoder.com/stat?c=problem_statement&pm=1901&rd=4650

EX:{ 10, 20, 30, 40, 50, 60, 70, 80, 90 }
5
Returns: 110
With the addition of two more workers, it makes more sense to partition the books as follows:

	10 20 30 40 | 50 60 | 70 | 80 | 90


The most folders that any single worker must look through will be 110.

*/

#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 10000
#define M 100
#define MAX 1000000007
using namespace std;

/**
recursive version for finding the fair load balancing..
*/
int sum(int a[],int s,int e)
{
   int summ=0;
   for(int i=s;i<=e;i++)
   summ+=a[i];
   return summ;
}

int fair_load_balancing_recursion(int a[],int k,int n)
{
  int i,j;
  if(k==1) return sum(a,0,n-1);
  else if(n==1) return a[0];
  int best=MAX;
  for(j=0;j<n;j++)
  {
    best=min(best,max(fair_load_balancing_recursion(a,k-1,j),sum(a,j,n-1)));
  }
  return best;
}

/**
end of functions..
*/



/**
DP version for finding the fair load balancing..
*/
int fair_load_balancing_dp(int a[],int k,int n)
{
  int cum[n],dp[k][n],i,j;
  cum[0]=a[0];
  for(i=1;i<n;i++)
  {
    cum[i]=cum[i-1]+a[i];
   }
   for(i=0;i<n;i++)
   dp[1][i]=cum[i];
   for(i=1;i<=k;i++)
   dp[i][0]=a[0];
   for(i=2;i<=k;i++)
   {
       for(j=1;j<n;j++)
       {
          int best=MAX;
          for(int p=0;p<j;p++)
          {
             best=min(best,max(dp[i-1][p],cum[j]-cum[p]));
           }
          dp[i][j]=best;
        }
    }
    return dp[k][n-1];
}

/**
Method 3 for solving the fair balancing using binary search..
*/
int getMax(int a[],int n)
{
  int maxx=-1;
  for(int i=0;i<n;i++)
  maxx=max(maxx,a[i]);
  return maxx;
}

int getSum(int a[],int n)
{
   int sum=0;
   for(int i=0;i<n;i++)
   sum+=a[i];
   return sum;
}

int getRequired_x(int a[],int n,int maxx)
{
    int total=0,x=1,i;
    for(i=0;i<n;i++)
    {
      total+=a[i];
      if(total>maxx)
      {
          total=a[i];
          x++;
        }
    }
    return x;
}

int fair_load_balancing_binary_search(int a[],int k,int n)
{
   int i,j,low,high,mid;
   low=getMax(a,n);
   high=getSum(a,n);
   while(low<high)
   {
      mid=low+(high-low)/2;
      int x=getRequired_x(a,n,mid);
      if(x<=k)
      high=mid;
      else
      low=mid+1;

    }
    return low;
}

int main()
{
    int i,j,k,n;
    // int a[]={ 10, 20, 30, 40, 50, 60, 70, 80, 90 };n=9;k=5;
    //   int a[]={ 568, 712, 412, 231, 241, 393, 865, 287, 128, 457, 238, 98, 980, 23, 782 };k=4;n=15;
    //  int a[]={ 950, 650, 250, 250, 350, 100, 650, 150, 150, 700 };k=6;n=10;
     //  int a[]={ 50, 50, 50, 50, 50, 50, 50 };k=2;n=7;
     // int a[]={ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1000 };k=2;n=15;
   //   int a[]= {950, 650, 250, 250, 350, 100, 650, 150, 150, 700, 200, 170, 320, 100};k=7;n=14;
      int a[]=	{261, 575, 597, 217, 623, 620, 11, 946, 912, 575, 8, 728, 244, 248, 802};k=7;n=15;
    printf("\nFair loading rec:%d\n",fair_load_balancing_recursion(a,k,n));
    printf("\nFair loading DP:%d\n",fair_load_balancing_dp(a,k,n));
     printf("\nFair loading binary search:%d\n",fair_load_balancing_binary_search(a,k,n));
    return 0;
}
