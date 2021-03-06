/**
http://www.codechef.com/COOK41/problems/GERALD03
*/

/**
INPUT:
4
3
-1 0
0 1
3 5
1
0 1
3
-2 -1
-2 -1
-2 0
4
4 6
3 5
-1 1
1 2


OUTPUT:
9
R+L+R+L+R+L+R+L+R+
0

1
R+
13
L-R-L-L-L-L-R-R-R-R-L+R+L+

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
#define INF 1000000000

typedef pair<int,int> pt;
vector< pt > vt(N,make_pair(0,0));

int dl[]={-1,1,0,0};
int dr[]={0,0,-1,1};
string di[]={"L-","L+","R-","R+"};

int dist(int l,int r,int nl,int nr)
{
	return abs(l-nl)+abs(r-nr);
}

//int main()
void driver()
{
	//printf("\nGERALd03 driver is running\n");
	int i,j,k,t,n,l,r;
	scanf("%d",&t);
	while(t--)
	{
		string ans;
		scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%d%d",&j,&k);
				vt[i].first=j;vt[i].second=k;
			}
			l=vt[0].first;r=vt[0].second;
		
		if(n==0||n==1)
		{
			printf("0\n");
			continue;
		}

			for(i=1;i<n;i++)
			{
				int nl,nr;
				nl=vt[i].first;nr=vt[i].second;
				while(!(nl==l&&nr==r))
				{
					int id=-1,d=INF,cur_dist=0;
					for(j=0;j<4;j++)
					{
						int nx,ny;
						nx=l+dl[j];
						ny=r+dr[j];
						cur_dist=dist(nl,nr,nx,ny);

						if(nx>=ny)
							continue;
						if(id==-1||cur_dist<d||cur_dist==d&&di[id][0]>di[j][0])
						{
							d=cur_dist;
							id=j;
						}
					}
					l+=dl[id];r+=dr[id];ans+=di[id];
				}
			}
			printf("%d\n",ans.size()/2);
			const char *str=ans.c_str();
			printf("%s\n",str);
	}
//	  return 0;
}
