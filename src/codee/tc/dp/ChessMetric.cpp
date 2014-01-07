/**
http://community.topcoder.com/stat?c=problem_statement&pm=1592&rd=4482
SOLU:
	This problem is a  variation of finding the K-length path existence between two vertices of the graph.
	Here, NoOfMov (K-length path) and start and end position of knioght is equilvalent to start  and end 
	vertex of GRAPH.
*/

/**
INPUT:
3 
0 0
1 0 
1

3 
0 0
0 0
2 

OUTPUT:
1
5

*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#define N 102
using namespace std;

int dp[N][N][60];

const int dx[16]={1,1,1,0,-1,-1,-1,0, 2,1,-1,-2,-2,-1,1,2}; 
const int dy[16]={1,0,-1,-1,-1,0,1,1, -1,-2,-2,-1,1,2,2,1};

void driver()
{
	printf("\ndriver for chessmetric is running..\n");
	int i,j,k,n,sx,sy,ex,ey,noOfMov;
	scanf("%d",&n);
	scanf("%d%d",&sx,&sy);
	scanf("%d%d",&ex,&ey);
	scanf("%d",&noOfMov);

	dp[sx][sy][0]=1;

	for(i=1;i<=noOfMov;i++)
	{
		for(j=sx;j<n;j++)
		{
			for(k=sy;k<n;k++)
			{
			  for(int l=0;l<16;l++)
			  {
					int nx,ny;
					nx=j+dx[l];
					ny=k+dy[l];
					if (nx<0 || ny<0 || nx>=n || ny>=n) continue; 
					dp[nx][ny][i]+=dp[j][k][i-1];
			  }
			}
		}
	}
	printf("\nNo of ways:%d\n",dp[ex][ey][noOfMov]);
}



