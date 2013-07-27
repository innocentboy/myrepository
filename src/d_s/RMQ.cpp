/*
  programe for finding the range minimum queries in an given array, by storing in an auxilary array , by preprossesing it.
  start of the function.

*/
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#define N 10000
#define MAX 9999
using namespace std;
int a[N],n,mm,l,r;
int m[2*N];
int dp[N][N];

/*
this section includes the code related to the segment tree. that is created for finding the minimum element in the rage.
start..
*/
void initialise(int node,int l,int r)
{
    if(l==r)
    m[node]=a[l];
    else{
      int md=(l+r)>>1;
      initialise(2*node+1,l,md);
      initialise(2*node+2,md+1,r);
      m[node]=min(m[2*node+1],m[2*node+2]);
    }
}

int query(int node,int s,int e,int l,int r)
{
    if(l>e||r<s)
    return -1;
    else if(s>=l&&e<=r)
    return m[node];
    else
    {
        int p,q,mm;
        mm=(s+e)>>1;
        p=query(2*node+1,s,mm,l,r);
        q=query(2*node+2,mm+1,e,l,r);
        if(p==-1) return q;
        else if(q==-1) return p;
        else return min(p,q);
    }
}

/*
end of the stuff related to the segment tree.
*/




/*
this function stores the indexes of minimum value of different ranges of array.(RMQ)
(this method basicallt used when there are no updatiion opeartion on array.)
start of function.
*/
void RMQ_array()
{
  int i,j,k;
  for(j=0;j<n;j++)
  {
      for(i=0;i<n;i++)
      dp[i][j]=n;
    }
  for(i=0;i<n;i++)
  dp[i][0]=i;
  for(j=1;(1<<j)<=n;j++)
  {
     for(i=0;(i+(1<<j))-1<n;i++)
     {
        //dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        if(a[dp[i][j-1]]<a[dp[i+(1<<(j-1))][j-1]])
        dp[i][j]=dp[i][j-1];
        else
        dp[i][j]=dp[i+(1<<(j-1))][j-1];
      }
   }
   printf("\n*** print the minimum array **\n");
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      printf("%4d  ",dp[i][j]);
      printf("\n");
    }
}


int query_RMQ(int l,int r)
{
    int i=0,j,k;
    while((l+(1<<i)-1)<r)i++;
    if((l+(1<<i)-1)==r) return dp[l][i];
    else
    {
       i--;
       j=r-(1<<i);
       int min=(a[dp[l][i]]<a[dp[l+j][i]])?dp[l][i]:dp[l+j][i];
       return min;
    }
}

/*
end of the functiom
*/


/*
start of the main.
*/
int main()
{

    int i,j,k,t;
    scanf("%d%d",&n,&t);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
   // RMQ_array();
      initialise(0,0,n-1);
    while(t--)
    {
       scanf("%d%d",&l,&r);
      // printf("minimum:%d\n",a[query_RMQ(l,r)]);
      printf("minimum:%d\n",query(0,0,n-1,l,r));
    }
    return 0;
}
