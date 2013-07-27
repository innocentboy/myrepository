#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<iostream>
#define N 25
using namespace std;

int visit[N][N];
char img[N][N];
int dx[]={-1,1,0,0,-1,-1,1,1};
int dy[]={0,0,-1,1,-1,1,-1,1};
int best=0,max_x,max_y,r,c;

int dfs(int x,int y)
{
  int i,nx,ny,sum=0;
  if(x>=r||y>=c||x<0||y<0)return 0;
  if(visit[x][y])return 0;
  visit[x][y]=1;
  for(i=0;i<4;i++)
  {
    nx=x+dx[i];ny=y+dy[i];
    if(nx>=r||ny>=c||nx<0||ny<0)
    {
        sum+=1; continue;
    }
    else if(((*(img[nx]+ny)-'X')==0) && visit[nx][ny]!=1)
    {
        sum+=dfs(nx,ny);
    }
    else if((*(img[nx]+ny)-'.')==0)
    sum+=1;
  }
  for(i=4;i<8;i++)
  {
    nx=x+dx[i];ny=y+dy[i];
    if(nx>=r||ny>=c||nx<0||ny<0) sum+=0;
    else if(((*(img[nx]+ny)-'X')==0) && visit[nx][ny]!=1)
    {
        sum+=dfs(nx,ny);
    }
  }
  return sum;

}


int  main()
{
    int i,j,x,y,t;
    while(scanf("%d%d%d%d",&r,&c,&x,&y)&&r!=0&&c!=0)
    {
      x--;y--;
      for(i=0;i<r;i++)scanf("%s",img[i]);
      for(i=0;i<r;i++)
      {
        for(j=0;j<c;j++)
        {
          if((*(img[i]+j)-'.')==0)
          {
              visit[i][j]=1;
          }
          else visit[i][j]=0;
        }
      }
      printf("%d\n", dfs(x,y));
    }
    return 0;
}
