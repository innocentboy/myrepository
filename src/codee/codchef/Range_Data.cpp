/**
http://www.codechef.com/problems/DRANGE
*/
/*
INPUT:
1
10 2
2 3 6 4
1 5 9 1


OUTPUT:
11
*/

/**
There are TWO METHODS: to solve this problem.
FIRST: By using BIT, But BIT should be used only when we are required to find out both the Operation as
	   applying the some between the given frequency as well as Fing the Frequency of Particular Instance
	   or range of DATA. But here is situation is not like that. So we should prefer the second over the first.

SECOND: Second method is simply to keep the SUM of No to that particulat strating and subtract the
		similar No from the  ending index+1 .of the given INDEX  and Vice-Versa.
		In the last traverse the array and find the MInimum and Maximum between them.
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 1000005
int a[N];

/**
Code related to the BIT.
*/
/**
METHOD 1: Using BIT.
*/
int read(int idx)
{
	int sum=0;
	while(idx>0)
	{
		sum+=a[idx];
		idx-=idx&(-idx);
	}
	return sum;
}
void update(int idx,int maxVal,int val)
{
	while(idx<=maxVal)
	{
		a[idx]+=val;
		idx+=idx&(-idx);
	}
}

int main()
{
	int i,j,k,t,n,m,w,x,y,z;
	int minn,maxx,cur;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			a[i]=0;
		while(m--)
		{
			scanf("%d%d%d%d",&w,&x,&y,&z);

			if(w==1)
			{
				update(x,n,z);
				update(y+1,n,-z);
			}
			else
			{
				update(x,n,-z);
				update(y+1,n,z);
			}

		}
		minn=a[1]+1;maxx=a[1]+1;
		cur=0;
		for(i=2;i<=n;i++)
		{
			cur=read(i);
			if(cur+i<minn)
				minn=cur+i;
			else if(cur+i>maxx)
				maxx=cur+i;
		}
		printf("%d\n",maxx-minn);
	}
    return 0;
}

/**
//METHOD:2

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 1000005
int a[N];

int main()
{
	//printf("\nDriver method is called\n");
	int i,j,k,t,n,m,w,x,y,z;
	int minn,maxx,cur;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			a[i]=0;
		while(m--)
		{
			scanf("%d%d%d%d",&w,&x,&y,&z);
			if(w==1)
			{
				a[x]+=z;
				a[y+1]-=z;
			}
			else
			{
				a[x]-=z;
				a[y+1]+=z;
			}
		}
		minn=a[1]+1;maxx=a[1]+1;
		cur=a[1];
		for(i=2;i<=n;i++)
		{
			cur+=a[i];
			if(cur+i<minn)
				minn=cur+i;
			else if(cur+i>maxx)
				maxx=cur+i;
		}
		printf("%d\n",maxx-minn);
	}
    return 0;
}

*/
