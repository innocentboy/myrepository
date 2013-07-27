#include<stdio.h>
#include<conio.h>
#define N 9
int totl_path;
int t[N];
int graph[N][N]={
    0,1,1,1,0,0,0,0,0,
    1,0,1,0,1,0,0,0,0,
    1,1,0,1,0,1,0,0,0,
    1,0,1,0,0,0,1,0,0,
    0,1,0,0,0,1,0,0,0,
    0,0,1,0,1,0,0,1,1,
    0,0,0,1,0,0,0,0,0,
    0,0,0,0,0,1,0,0,1,
    0,0,0,0,0,1,0,1,0
  };
void path(int,int);
int main()
{
    int p,i,j,s,d;
    printf("enter the graph....\n");
 //   for(i=0;i<N;i++)
  //     for(j=0;j<N;j++)
  //         scanf("%d",&graph[i][j]);
    printf("\n enter the source and distination...\n"); 
    scanf("%d%d",&s,&d);      
    path(s,d);
    if(totl_path>0)
      {
            printf("\nthere exits a path between the nodes.. ");
            printf("\ntotal no of paths:%d",totl_path);
      }            
    else
            printf("there is no path between the nodes..");
   getch();    
}

void path(int s,int d)
{
    int i;
    t[s]=1;
    if(graph[s][d]==1&&t[d]!=1)
      totl_path++;
    for(i=0;i<N;i++)
    {
               if(graph[s][i]&&t[i]!=1)
               {
                   path(i,d);                    
               }            
    }
    t[s]=0;
}

