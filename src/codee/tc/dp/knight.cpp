#include<cstdio>
#include<vector>
#include<algorithm>
#include<math.h>
#define N 8
int d[N][N][N][N];
int main()
{

   int i,j,u,v,n,m,s,t;
   int kr,kc,rr,rc,qr,qc;
   char k[3],q[3],r[3];
   scanf("%s%s%s",k,r,q);
   int inf=1000000,ans,res1,res2;
   for(i=0;i<N;i++)
     for(j=0;j<N;j++)
       for(u=0;u<N;u++)
         for(v=0;v<N;v++)
         {
            d[i][j][u][v]=inf;
            if(i==u&&j==v)d[i][j][u][v]=0;
            if(abs(i-u)==1&&abs(j-v)==2)d[i][j][u][v]=1;
            if(abs(i-u)==2&&abs(j-v)==1)d[i][j][u][v]=1;
         }

    for(i=0;i<N;i++)
     for(j=0;j<N;j++)
     {
       for(u=0;u<N;u++)
       {
         for(v=0;v<N;v++)
         {
             if(d[i][j][u][v]==1)
             printf("%d ",d[i][j][u][v]);
             else
             printf("0 ");

         }
         printf("\n");
       }
         printf("\n*******%d  %d********\n",i,j);
     }
     for(s=0;s<N;s++)
      for(t=0;t<N;t++)
       for(i=0;i<N;i++)
        for(j=0;j<N;j++)
          for(u=0;u<N;u++)
            for(v=0;v<N;v++)
            {
               if(d[i][j][s][t]+d[s][t][u][v]<d[i][j][u][v])
               d[i][j][u][v]=d[i][j][s][t]+d[s][t][u][v];
            }
     kr=k[0]-'a';kc=k[1]-'1';
     rr=r[0]-'a';rc=r[1]-'1';
     qr=q[0]-'a';qc=q[1]-'1';
     res1=d[kr][kc][rr][rc]+d[rr][rc][qr][qc];
     res2=d[kr][kc][qr][qc]+d[qr][qc][rr][rc];
     ans=res1<res2?res1:res2;
     printf("\n\n minimum steps:%d",ans);
     return 0;
}
