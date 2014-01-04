/**
http://www.spoj.com/problems/INCSEQ/
*/
/**
1 N 10,000
1  K 50

INPUT:
7 4
1
2
2
10
15
4
25

4 3
1
2
2
10


OUTPUT:
11
2
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
#define N 10005
#define K 52
#define M 5000000

struct compare
{
	bool operator()(const pair<int,int> &a,const pair<int,int> &b) const
	{
		return a.first<b.first;
	}
};

int a[N];
int dp[N][K];
set< pair<int,int> > st;
set< pair<int,int> >::iterator it,it1;


int main()
{
	//printf("\ndriver of incse is running...\n");
	int i,j,l,k,n,ans=0;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<=k;j++)
	    dp[i][j]=0;
		dp[i][1]=1;
	}

	for(i=0;i<n;i++)
	{
		    printf("\n");
		    it=st.lower_bound(make_pair(a[i],i));
			for(it1=st.begin();it1!=it;it1++)
			{
				j=(*it1).second;
				printf("%d ",a[j]);
				for(l=2;l<=k;l++)
				{
						if(a[i]>a[j])
						{
							dp[i][l]=(dp[i][l]+dp[j][l-1])%M;
						}
				}
			}
		  }
		}
	}
		st.insert(make_pair(a[i],i));
		//printf("\nlen:%d\n",st.size());
	}
		ans=0;
		for(i=0;i<n;i++)
		{
			ans=(dp[i][k]+ans)%M;
		}
		printf("%d\n",ans);
		return 0;
}
