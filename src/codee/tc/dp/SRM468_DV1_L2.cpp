/**
http://community.topcoder.com/stat?c=problem_statement&pm=10765&rd=14183
SOL:
http://apps.topcoder.com/wiki/display/tc/SRM+468
*/

/**
INPUT:
//
3
4 6 8
1 7 4
1
//
3
4 6 8
1 11 4
1
//
3
4 6 8
1 11 4
2

OUTPUT:
//
12
//
//
14
//
//
11
//
14
122365

*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#define N 4000004
using namespace std;

int flight[N],road[N];
int n,k;


/**
METHOD 1:
USING RECURANCE RELATION FOR SOLVING THE QUESTION.
*/
int solve(int index,int k,int flying)
{
	int i,j,l,m,ret=99999;
	if(index==n-1)
	{
	  j=road[index];
	  if(k>0||(k==0&&flying==1)){
		  i=flight[index];
		  return min(i,j);
	  }
	  return j;
	}

	if(k>0||(k==0&&flying==1))
	{
		if(flying==1)
		{
            ret=min(ret,min(solve(index+1,k,1)+flight[index],
                solve(index+1,k,0)+road[index]));
        }
        else
        {
            ret=min(ret,min(solve(index+1,k-1,1)+flight[index],
                solve(index+1,k,0)+road[index]));
        }
	}

	else
	{
		ret=0;
		for(i=index;i<n;i++)
			ret+=road[i];
	}
	return ret;
}

/**
METHOD 2:
USING DP FOR SOLVING THE QUESTION.
*/
void solveDP()
{
    int i,j,l,m,f;
    /**
    [first] signifies the storage for current one(i&1), and the vales from stored second one.(!i&1)
    [second] 0 signifies that it's not in flying mod and 1 signifies that it's in flying mod.e
    [third]
    */
    int dp[2][2][41];
    for(i=0;i<2;i++)
    {
       for(j=0;j<2;j++)
         for(l=0;l<=41;l++)
         dp[i][j][l]=0;
    }

    for(i=0;i<n;i++)
    {
      /**
      f==1 signifies that it's in flight mod. ans f==0 signifies that it's nt flying..

      */
      for(f=0;f<2;f++)
      {
        for(j=0;j<=k;j++)
        {
            int &best=dp[!(i&1)][f][j];
            best=dp[i&1][0][j]+road[i];
            if(f==1)
                best=min(best,dp[i&1][1][j]+flight[i]);
            else if(j>0)
                best=min(best,dp[i&1][1][j-1]+flight[i]);
        }
      }
    }
    printf("\nAns:%d\n",dp[(i&1)][0][k]);
}


int main()
{
	printf("\ndriver of king or road is running..\n");
	int i,j,l,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&road[i]);
	for(i=0;i<n;i++)
		scanf("%d",&flight[i]);
	scanf("%d",&k);

	/**
	Using METHOD1:
	*/
	i=solve(0,k-1,1);
	j=solve(0,k,0);
	printf("\nAns:%d\n",min(i,j));
	/**
	Using METHOD 2:
	*/
	solveDP();

	return 0;
}
