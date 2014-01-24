/**
http://www.codechef.com/problems/AMIFIB
NOTE:	 n is a fibonacci number if and only if 5 * n * n + 4 or 5 * n * n - 4 
*/

/**
INPUT:
3
3
4
5

OUTPUT:
YES
NO
YES

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
#define N 6666
#define INF 1000000000
#define ull unsigned long long 

char s[N];
ull fib[N];
set<ull> st;

void preprocess()
{
	int i,j;
	fib[0]=0;fib[1]=1;
	st.insert(0);
	st.insert(1);
	for(i=2;i<N;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		st.insert(fib[i]);
	}
}

//int main()
void driver()
{
	//printf("\ndriver for AMIFIB is running..\n");
	int i,j,n,t;
	ull k;
	scanf("%d",&t);
	preprocess();
	while(t--)
	{
		k=0;i=0;
		scanf("%s",s);
		while(s[i])
		{
			k=k*10+s[i]-'0';
			i++;
		}

		if(st.find(k)!=st.end())
			printf("YES\n");
		else
			printf("NO\n");
	}
	//return 0;
}
