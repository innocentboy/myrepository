/**
LINK:::http://www.codechef.com/MARCH14/problems/MIKE3
*/
/**
Input:
4 3
2 1 2
2 2 3
2 3 4

Output:
2
*/

#include<cstdio>
#include<vector>
#include<algorithm>
#include <set>
#include<cstring>
#define N 20005
#define M 25

using namespace std;
int a[M][N];

//int main()
void driver()
{
	printf("\ndriver for mike is running...\n");
	int i,j,k,n,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i][0]);
	  for(j=1;j<a[i][0];j++)
		  scanf("%d",&a[i][j]);
	  map<int,int> mp;

	}

	//return 0;
}
