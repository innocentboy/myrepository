/**
LINK:::http://www.codechef.com/MARCH14/problems/PROSUM
*/
/**
Input:
5
3
3 4 5
4
1 1 1 3
3
0 3    5
4
1 14 1 1
6
	3 2 5 2 1 4

Output:
3
0
*/

#include<cstdio>
#include<vector>
#include<algorithm>
#include <set>
#include<cstring>
#define N 100005

using namespace std;

int a[N];

//int main()
void driver()
{
	
	int i,j,k,n,t;
	scanf("%d",&t);
	while(t--)
	{
	  scanf("%d",&n);
	  for(i=0;i<n;i++)
		  scanf("%d",&a[i]);
	  int zero=0,one=0,two=0;
	  long long ans=0;
	  for(i=0;i<n;i++)
	  {
	    if(a[i]!=0&&a[i]!=1&&a[i]!=2)
		{
		    ans+=(i-zero-one-two);
		}
		else
		{
			switch(a[i])
			{
				case 0: zero++;
						break;
				case 1:	one++;
						break;
				case 2: two++;
						break;
			}
		}
	  }
			printf("%lld\n",ans);
	}

	//return 0;
}
