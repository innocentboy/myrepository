#include<stdio.h>
#define N 10005
#define MAX 999999999
int wt[N];
int p[N],w[N];
int min(int a,int b)
{
return a<b?a:b;
}
int main()
{
int i,j,k,t,e,f,n,q;
scanf("%d",&t);
while(t--)
{
scanf("%d%d",&e,&f);
scanf("%d",&n);
for(i=1;i<=n;i++)
scanf("%d%d",&p[i],&w[i]);
wt[0]=0;
for(i=1;i<=f-e;i++)
{
q=MAX;
for(j=1;j<=n;j++)
{
if((i-w[j])>=0)
{
q=min(q,(p[j]+wt[i-w[j]]));
}
}
wt[i]=q;
}
if(wt[f-e]!=MAX)
printf("The minimum amount of money in the piggy-bank is %d.\n",wt[f-e]);
else printf("This is impossible.\n");
}
return 0;
}