/**
Given a set of non-negative integers, and a value sum, determine if there is
a subset of the given set with sum equal to given sum.

Examples: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output:  True  //There is a subset (4, 5) with sum 9.

*/

#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 1000
#define SUM 1000
using namespace std;
/**
  recursive dunction for checking the subset sum in the array..
*/
bool isSubsetSum(int a[],int n,int sum)
{
   if(sum==0)
   return true;
   else if(n<0&&sum!=0)
   {
      return false;
    }
    else if(a[n]>sum)
    return isSubsetSum(a,n-1,sum);
    return (isSubsetSum(a,n-1,sum)||isSubsetSum(a,n-1,sum-a[n]));

}
/**
DP version for calculating the subset sum in array..
*/
bool dp_isSubsetSum(int a[],int n,int sum)
{

   int i,j,k;
   bool dp[N][SUM];
   for(i=0;i<n;i++)
     for(j=1;j<=sum;j++) dp[i][j]=false;
  // for(i=0;i<n;i++)
  // dp[0][a[i]]=true;

  for(i=0;i<n;i++)
  {
   for(j=1;j<=sum;j++)
   {
        if((j-a[i])==0)
        dp[i][j]=true;
        else{if(dp[i-1][j]||((j-a[i])>=0&&dp[i-1][j-a[i]]))
        dp[i][j]=true;
        else
        dp[i][j]=false;}

      }
   }
   printf("\nprintf the dp matrix\n");
   for(j=1;j<=sum;j++)
  printf("%2d ",j);printf("\n");
   for(i=0;i<n;i++)
   {
      for(j=1;j<=sum;j++)
      printf("%2d ",dp[i][j]);
      printf("\n");
    }
    j=sum;
   for(i=0;i<n;i++){
   if(dp[i][sum]) return true;}
   return false;

}

/**

*/
void print_balance(char s[],int ind,int open,int close,int n)
{
    if(close==n)
    {
      printf("%s\n",s);
    }
    else
    {
      if(open>close){
       s[ind]='}';
      print_balance(s,ind+1,open,close+1,n);

      }
      if(open<n)
         {
            s[ind]='{';
             print_balance(s,ind+1,open+1,close,n);
          }

    }

}

int main()
{
   int i,j,k,n,sum=27;
   int a[N]={3,25, 4, 12, 5, 2};
   n=6;
   if(isSubsetSum(a,n-1,sum))
   printf("\nsubset sum exits in the given array..\n");
   if(dp_isSubsetSum(a,n,sum))
   printf("\nDP  subset sum exits in the given array..\n");
   else printf("\nno such subset exits.\n");
   printf("\nprint the balanced paranthese.\n");
  // char s[11];s[10]='\0';
  // print_balance(s,0,0,0,5);
   return 0;
}
