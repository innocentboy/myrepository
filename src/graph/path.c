#include<stdio.h>
#include<conio.h>
#define N 5
int totl_path;
int t[N];
/*int graph[N][N]={
    0,1,1,1,0,0,0,0,0,
    1,0,1,0,1,0,0,0,0,
    1,1,0,1,0,1,0,0,0,
    1,0,1,0,0,0,1,0,0,
    0,1,0,0,0,1,0,0,0,
    0,0,1,0,1,0,0,1,1,
    0,0,0,1,0,0,0,0,0,
    0,0,0,0,0,1,0,0,1,
    0,0,0,0,0,1,0,1,0
  }; */
/*int graph[N][N]={
        0,10,5,0,0,
        0,0,2,0,1,
        0,0,0,2,9,
        0,0,0,0,0,
        0,0,0,4,0 };   */ 
int graph[N][N]={
        0,0,0,1,0,
        0,0,0,1,1,
        0,0,0,0,1,
        0,1,1,0,0,
        0,0,0,1,0};        
int path(int,int);
int main()
{
    int p,i,j,s,d;
    printf("enter the graph....\n");
    printf("\n enter the source and distination...\n"); 
    scanf("%d%d",&s,&d);      
    p=path(s,d);
    if(p)
      {
            printf("\nthere exits a path between the nodes.. ");
      }            
    else
            printf("there is no path between the nodes..");
   getch();    
}

int path(int s,int d)
{
    int i;
    t[s]=1;
    if(graph[s][d]&&t[d]!=1)
    {             
      return 1;
    }  
    for(i=0;i<N;i++)
    {
                 
               if(graph[s][i]&&(t[i]!=1)&&(path(i,d)==1)) 
               {
                  
                   return 1;                 
               }            
    }
     
    t[s]=0;
    return 0;
}
