/**
http://www.codechef.com/problems/COUNTPAL/
*/
/**
Input:
bobseesanna

Output:
18
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
#define M 1000000007

char s[N];

int strlenn(char *s)
{
	int i=0;
	while(s[i++]);
	return i-1;
}

//int main()
void driver()
{
	//printf("\ndriver of Countpal is running..\n");
	int i,j,k,n;
	scanf("%s",s);
	n=strlenn(s);

	//printf("\nlen:%d\n",n);
	//Dp[][] , to keep track of different substrings that are palindrom.
	bool dp[N][N]={false};

	//fq[], for storing the count of all possible palindrom till that index i.
	int fq[N];
	for(i=0;i<=n;i++)
		fq[i]=0;
	for(i=0;i<n;i++)
		dp[i][i]=true;
	fq[n]=1;
	for(i=n-1;i>=0;i--)
	{
		for(j=i;j<n;j++)
		{
			if(s[i]==s[j]&&((j-i)<2||dp[i+1][j-1]))
			{
				dp[i][j]=true;
				fq[i]+=(fq[j+1])%M;
			}
		}
	}
	printf("%d\n",fq[0]%M);
	//return 0;
}
