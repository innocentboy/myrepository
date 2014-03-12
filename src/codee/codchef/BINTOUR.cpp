/**
http://www.codechef.com/MARCH14/problems/BINTOUR
*/
/**
nput:
1

Output:
2
2

Input:
2

Output:
0
8
16
24

*/
#include<cstdio>
#include<vector>
#include<algorithm>
#include <set>
#include<cstring>
#define N 20005
#define M 1000000009

using namespace std;

long long fact(long long n)
{
   int i=n,ans=1;
   while(i>0)
   {
     ans=(ans*i)%M;
	 i--;
   }
   return ans;
}

//int main()
void driver()
{
	printf("\ndriver for binary tournament is running..\n");
	int i,j,k,t;
	long long x,y,z;
	scanf("%d",&k);
	x=(1<<k);
	y=(1<<(k-1));

	i=1;
	while(i++<y)
		printf("0\n");
	z=fact(y);
	printf("%lld\n",((z*z)%M)*2);
	i=y+1;

	z=((((z*z)%M)*y)%M)*2;

	while(i++<x)
	{
	  printf("%lld\n",z);
	}
	z=fact(x);
	printf("%lld\n",z);

	//return 0;
}
