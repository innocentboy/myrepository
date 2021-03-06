/**
http://www.codechef.com/problems/J2
*/

/**
Input
3
acbd
acbd

vnvn
vn

abcd
efgh

Output
4 1
2 1
*/

#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <cstring>
using namespace  std;
#define N 1005
#define M 23102009

int dp[N][N];
int lcsDP[N][N];

char s1[N],s2[N];

int strlenn(char *s)
{
	int i=0;
	while(s[i++]);
	return i-1;
}

//int main()
void driver()
{
	int i,j,k,t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s1);
		scanf("%s",s2);
		int l1,l2;
		l1=strlenn(s1);
		l2=strlenn(s2);
		//compute Maxlength LCS.
		for(i=0;i<=l1;i++)
		{
			for(j=0;j<=l2;j++)
			{
				if(i==0||j==0)
					lcsDP[i][j]=0;
				else
				{
					if(s1[i-1]==s2[j-1])
						lcsDP[i][j]=lcsDP[i-1][j-1]+1;
					else if(lcsDP[i-1][j]<lcsDP[i][j-1])
						lcsDP[i][j]=lcsDP[i][j-1];
					else
						lcsDP[i][j]=lcsDP[i-1][j];
				}
						
			}
		}
		//Compute the all distinct No. of LCS.
		for(i=0;i<=l1;i++)
		{
			for(j=0;j<=l2;j++)
			{
				//Base case.We have empty string subsequence common in both strings.
				//That's why it's value i.e. No. of distinct LCS would be 1.
				if(i==0||j==0)
					dp[i][j]=1;
				else
				{
					if(s1[i-1]==s2[j-1])
						dp[i][j]=dp[i-1][j-1];
					else
					{
						dp[i][j]=0;
						if(lcsDP[i-1][j]==lcsDP[i][j])
							dp[i][j]=dp[i-1][j]%M;
						if(lcsDP[i][j-1]==lcsDP[i][j])
							dp[i][j]=(dp[i][j]+dp[i][j-1])%M;
						//This is the overlapping situation so we need to subtract it,
						//otherwise we would not get the Distinct LCS.
						if(lcsDP[i][j]==lcsDP[i-1][j-1])
						{
							if((dp[i][j]-dp[i-1][j-1])>0)
								dp[i][j]=(dp[i][j]-dp[i-1][j-1])%M;
							else
								dp[i][j]=(dp[i][j]-dp[i-1][j-1])+M;
						}
					}
				}
			}
		}
		//In case Maxlength of LCS of Both strings are  0, i.e. we have empty string subsequence ,still 
		//No of distinct LCS would be one.
		printf("%d %d\n",lcsDP[l1][l2],dp[l1][l2]);
	}

	//return 0;
}
