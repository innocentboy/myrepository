//maximum sum in an array while no two consecutive elements would be selected not even both first and last

#include<cstdio>
#include<algorithm>
#define N 100
using namespace std;
int a[N],dp[2][N],n;
int maxsum(int index,int selected)
{
    if(index>=n) return 0;
    if(index==n-1&&selected) return 0;
    if(index==n-1) return a[index];
    if(dp[selected][index]!=-1) return dp[selected][index];
    return dp[selected][index]=max(a[index]+maxsum(index+2,selected),maxsum(index+1,selected));
}
int main()
{
   int i,j,k;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   for(i=0;i<n;i++)
   {
      dp[0][i]=dp[1][i]=-1;
    }
   printf("\n maximum sum:%d",max(a[0]+maxsum(2,1),maxsum(1,0)));
}
