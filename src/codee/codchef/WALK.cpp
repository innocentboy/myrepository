/**

*/

/**
Input:

3
5
6 5 4 3 2
5
3 3 4 1 1
5
3 3 3 3 3

Output:

6
5
*/

#include<cstdio>
#include<vector>
#include<algorithm>
#include <set>
#include<cstring>
#define N 100005

using namespace std;
int w[N];

//int main()
void driver()
{
	int i,j,k,t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&w[i]);
		  int ans=w[0];
		  for(i=1;i<n;i++)
		  {
		    if(i+w[i]>ans){
				ans=i+w[i];
			}
		  }
		  printf("%d\n",ans);
	}

	//return 0;
}
