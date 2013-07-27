/**
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.


*/


#include<string>
#include<cstdio>
#include<iostream>
#define N 1000
using namespace std;
string s1,s2,s3;
int dp[N][N];
/**

recursive version..
*/
bool interleave(int m,int n,int l)
{
   if(l<0) return true;
   return ((s1[m]==s3[l]&&interleave(m-1,n,l-1))||(s2[n]==s3[l]&&interleave(m,n-1,l-1)));
}

/**
dp version..
**/
int dp_interleave(int m,int n,int l)
{
    int i,j,k;
    if(l<0) return 1;
    if(dp[m][n]!=-1){
      return dp[m][n];
    }
    if((s1[m]==s3[l]&&interleave(m-1,n,l-1))||(s2[n]==s3[l]&&interleave(m,n-1,l-1)))
    return dp[m][n]=1;
    else return dp[m][n]=0;

}

int main()
{
   int n,m,l,i,j;
   cin>>s1;
   cin>>s2;cin>>s3;
   m=s1.length()-1;n=s2.length()-1;
   l=s3.length()-1;
   printf("\n%d %d %d\n",m,n,l);
   for(i=0;i<=m;i++)
     for(j=0;j<=n;j++)
       dp[i][j]=-1;
   if((l==m+n+1)&&interleave(m,n,l))
   printf("\nYES\n");
   else if(dp_interleave(m,n,l)==1)
   {
        printf("\nYES\n");
    }
   else
   printf("\nFALSE \n");
   return 0;
}
