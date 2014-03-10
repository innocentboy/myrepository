/**
LINK:::http://www.codechef.com/MARCH14/problems/TMSLT
*/
/**
Input:
4
1 1 1 1 1
2 1 1 1 1
3 1 2 3 4
4 2 3 4 1

Output:
1
2
763
74896

*/

#include<cstdio>
#include<vector>
#include<algorithm>
#include <set>
#include<cstring>
#include<cmath>
#define N 3000005
#define M 1000000

using namespace std;
int dp[M];

//int main()
void driver()
{
	int i,j,k,t,n;
	int a,b,c,d,e;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
		long long prv=d;
		//reset the a[] array.
		for(i=1;i<M;i++) dp[i]=0;
		dp[d]++;

		for(i=1;i<n;i++)
		{
			long long next=(((long long)a*prv*prv)+ ((long long )b*prv) +c)%M;
			int t=(int) next;
			dp[t]++;
			prv=next;
		}
		long long first=0,second=0;
		bool turn=true;
		for(i=1;i<M;i++)
		{
			first+=(dp[i]/2)*i;
			second+=(dp[i]/2)*i;
			if(dp[i]!=0&&dp[i]&1)
			{
				if(turn)
				 {
					first+=i;
					turn=false;
				}
				else
				 {
					 second+=i;
					 turn =true;
				 }
			}
		}
			printf("%lld\n",abs(first-second));
	}

	//return 0;
}
