#include<stdio.h>
#include<conio.h>
#define N 9
#define MAX 9999999
/*int graph[N][N]={
        0,10,5,0,0,
        0,0,2,0,1,
        0,3,0,2,9,
        7,0,0,0,6,
        0,0,0,4,0 }; */
int graph[N][N]={
    0,4,8,0,0,0,0,0,0,
    4,0,11,0,8,0,0,0,0,
    8,11,0,7,0,1,0,0,0,
    0,0,7,2,6,0,0,0,0,
    0,8,0,2,0,0,7,4,0,
    0,0,1,6,0,0,0,2,0,
    0,0,0,0,7,0,0,14,9,
    0,0,0,0,4,2,14,0,10,
    0,0,0,0,0,0,9,10,0,
    };        
int traverse[N];
int predecessor[N];    
int distance[N];     
void shortest_path(int g[][],int);        
int main()
{
    int i,j,k;
    for(i=0;i<N;i++)
      distance[i]=MAX;
    printf("we have given a graph... \n We are going to find the shortest path from the source to other nodes\n");
    shortest_path(graph,0);
    printf("\n***************");
    printf("\n print the shortest distance...\n");
    for(i=0;i<N;i++)
      printf("%d: %d\n",i,distance[i]);
    getch();    
}
void shortest_path(int g[][N],int s)
{
     int i,j,k,min_distance=MAX;
     distance[s]=0;
     predecessor[s]=0;
     k=0;
     while(!empty())
     {
         s=k;           
         for(i=0;i<N;i++)
         {
             if(!traverse[i]&&i!=s)
             {
                   if(g[s][i]&&(distance[s]+g[s][i])<distance[i])
                   {
                        distance[i]=distance[s]+g[s][i];  
                         predecessor[i]=s;                                   
                   }
                                         
                                  
                   if(min_distance>distance[i])
                   {
                          k=i;                            
                          min_distance=distance[i];  
                   } 
             }           
         }  
         traverse[s]=1;             
         min_distance=MAX;
     }
     
}
int empty()
{
   int i,f=1;
   for(i=0;i<N;i++)
   {
         if(traverse[i]==0)
         {
            f=0;
            break;                  
         }
   }    
   return f;
}

