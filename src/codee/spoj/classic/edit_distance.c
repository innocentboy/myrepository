#include<stdio.h>
#define N 2100
char s1[N],s2[N];
int dp[N][N];
int min(int a,int b)
{
  return a>b?b:a;    
}
int main()
{
int i,j,k,n,t,val,l1,l2,temp1,temp2;
scanf("%d",&t);
while(t--){
scanf("%s%s",s1,s2);l1=strlen(s1);l2=strlen(s2);               
dp[0][0]=0;
for(i=1;i<=l1;i++) dp[i][0]=i;
for(j=1;j<=l2;j++) dp[0][j]=j;
for(i=1;i<=l1;i++)   {
     for(j=1;j<=l2;j++)   {
          val=(s1[i-1]==s2[j-1])?0:1;
          temp1=min(dp[i-1][j]+1,dp[i][j-1]+1);
          temp2=dp[i-1][j-1]+val;
          dp[i][j]=min(temp1,temp2);
     }
}
  printf("%d\n",dp[l1][l2]);
}
getch();
}

