/*
calculating the diameter of tree..
*/
#include<stdio.h>
#define N 1009
int visit[N][N];
char labr[N][N];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int best=0,max_x,max_y,r,c;
void dfs(int x,int y,int n)
{
  int i,nx,ny;
  if(x>=r||y>=c)return ;
  if(visit[x][y])return ;
  visit[x][y]=1;
  if(n>=best)
  { best=n;
          max_x=x;max_y=y;
  }
  for(i=0;i<4;i++)
  {
    nx=x+dx[i];ny=y+dy[i];
    if(((*(labr[nx]+ny)-'.')==0) && visit[nx][ny]!=1)
    {
        //printf("\n%d %d %d",best,nx+1,ny+1);
        dfs(nx,ny,n+1);
    }
  }
 
}
int  main()
{
    int i,j,x,y,t;
    scanf("%d",&t);
    while(t--)
    {
      best=0;
      scanf("%d%d",&c,&r);
      for(i=0;i<r;i++)scanf("%s",labr[i]);
     // printf("sring\n");
     // for(i=0;i<r;i++)puts(labr[i]);
      x=-1;
      for(i=0;i<r;i++)
      {
        for(j=0;j<c;j++)
        {
          if(x==-1&&((*(labr[i]+j)-'.')==0))
          {
              x=i;y=j;
          }
          if((*(labr[i]+j)-'#')==0)
          {
              visit[i][j]=1;
          }
          else visit[i][j]=0;
        }
      }
     /*printf("prin visit\n");
      for(i=0;i<r;i++)
      {
       for(j=0;j<c;j++)printf("%d ",visit[i][j]);printf("\n");
      }*/
      dfs(x,y,0);
     // printf("\n %d %d %d\n",best,max_x,max_y);
     // best=0;
      for(i=0;i<r;i++)
      {
        for(j=0;j<c;j++)
        {
         // if(x!=-1&& (*(labr[i]+j)-'.')==0){x=i;y=j;}
          if((*(labr[i]+j)-'#')==0)visit[i][j]=1;
          else visit[i][j]=0;
        }
      }
      dfs(max_x,max_y,0);
      printf("Maximum rope length is %d.\n",best);
    }
    return 0;
}
 
