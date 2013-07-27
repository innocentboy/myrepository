#include<stdio.h>
#include<conio.h>
#define N 5
int totl_path;
int t[N];
int preced[N];
/* int graph[N][N]={
    0,1,0,1,0,0,0,0,0,
    1,0,1,0,1,0,0,0,0,
    0,1,0,0,0,0,0,0,0,
    1,0,1,0,0,0,1,0,0,
    0,1,0,0,0,1,0,0,0,
    0,0,0,0,1,0,0,1,1,
    0,0,0,1,0,0,0,0,0,
    0,0,0,0,0,1,0,0,1,
    0,0,0,0,0,1,0,1,0
  };*/
int graph[N][N]={
        0,10,5,0,0,
        0,0,2,0,1,
        0,0,0,2,9,
        0,0,0,0,0,
        0,0,0,4,0 };   
/*int graph[N][N]={
        0,1,1,1,1,
        0,0,0,0,0,
        0,0,0,0,1,
        0,1,0,0,0,
        0,0,0,0,0}; */         
int path_undirected(int,int);
int path_directed(int);
int ancestor(int,int);
int main()
{
    int p,i,j,s,d;
    printf("enter the graph....\n");
    printf("\n enter whether the graph is directed or undirected..");
    printf("\n******************");
    printf("\nenter 0:for undirected.\n1:fordirected\n");
    scanf("%d",&i);
    switch(i)
    {
       case 0:p=path_undirected(0,-1);
              break;
       case 1:p=path_directed(0);
              break;
       default:printf("\n you have entered the wrong choive..."); 
               exit(0);                       
             
    }
 //   for(i=0;i<N;i++)
  //     for(j=0;j<N;j++)
  //         scanf("%d",&graph[i][j]);
 //   printf("\n enter the source and distination...\n"); 
 //   scanf("%d%d",&s,&d);      
    if(p)
      {
            printf("\n there exits a cycle in the graph.... ");
      }            
    else
            printf("\n there is no cycle in the graph..");
   getch();    
}

int path_undirected(int s,int adj)
{
    int i;
    t[s]=1;
    for(i=0;i<N;i++)
    {
               if(graph[s][i])
               {
                   if(i!=adj&&t[i]==1)
                     return 1;                   
                   return path_undirected(i,s);        
               }            
    }
    t[s]=0;
    return 0;
}
int path_directed(int s)
{
    int i;
    t[s]=1;
    for(i=0;i<N;i++)
    {
               if(graph[s][i])
               {
                   if(t[i]==1)
                     return 1;                   
                   return path_directed(i);        
               }            
    }
   // t[s]=0;
    return 0;
}
int ancestor(int s,int d)
{
    
    
}

