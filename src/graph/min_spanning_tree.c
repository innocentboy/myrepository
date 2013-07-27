#include<stdio.h>
#include<conio.h>
#define N 9
#define MAX 9999999
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
/*int graph[N][N]={
        0,10,5,0,0,
        0,0,2,0,1,
        0,3,0,2,9,
        7,0,0,0,6,
        0,0,0,4,0 };  */   
int traverse[N];
int predecessor[N];    
int distance[N];    
void min_spanning(int g[][],int);
int main()
{
    int i,j,k;
    for(j=0;j<N;j++)
        distance[j]=MAX;
    printf("print the minimum spanning tree for the given graph.....\n");
    printf("\n***********************\n");
    min_spanning(graph,0);
    printf("\n*******************\n");
    printf("\n*********************\n");
    printf("print the nodes between which these edges exits...\n");
    for(j=0;j<N;j++)
    {
            if(j!=0)
            {
               printf("\n path between %d  and  %d is in the tree. with distance :%d",predecessor[j],j,distance[j]);                 
                             
            }                
    }              
    getch();    
}         
void min_spanning(int g[][N],int s)
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
             if(!traverse[i]&&s!=i)
             {
                   if(g[s][i]&&(g[s][i]<distance[i]))
                   {
                         distance[i]=g[s][i];
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
