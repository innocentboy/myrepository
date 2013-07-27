#include<stdio.h>
#include<string.h>
#define N 10000
#define INF 200002
int cost[N][N];
int arr[N][N];
int r;
struct city
{
   char name[10];
   int index;       
};
struct city list[N];
void search(char *sr,char *dst,int *s,int *d)
{
    int i,j,k,f1=1,f2=2;
    for(i=0;i<r&&(f1||f2);i++)
    {
          if(strcmp(list[i].name,sr)==0)
          {
             f1=0;
             *s=list[i].index;                          
          }
          if(strcmp(list[i].name,dst)==0)
          {
             f2=0;
             *d=list[i].index;                          
          }            
    }     
     
}
void warshal(int r)
{
	int i, j, k, n = 4 ;
	for (i=0;i<r;i++)
	{
		for (j=0;j<r;j++)
		{
			if (cost[i][j]==0)
				arr[i][j] = INF ;
			else
				arr[i][j] = cost[i][j] ;
		}
	}

	/*printf("Adjacency matrix of cost of edges:\n" ) ;
	for ( i = 0 ; i < n ; i++ )
	{
		for ( j = 0; j < n ; j++ )
			printf ( "%d\t", arr[i][j] ) ;
		    printf ( "\n" ) ;
	}*/

	for ( k = 0 ; k < n ; k++ )
	{
		for ( i = 0 ; i < n ; i++ )
		{
			for ( j = 0 ; j < n ; j++ )
			{
				if ( arr[i][j] > arr[i][k] + arr[k][j] )
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
}

int main( )
{
	int c,t,i,j,k,p,nr,cst,s=0,d=0;
	char source[10],destin[10];
	scanf("%d",&t);
	while(t-->0)
	{
       scanf("%d",&r);
       c=r;i=0;
       while(c-->0)
       {
         list[i].index=i;          
         scanf("%s",list[i].name);i++;
         scanf("%d",&p); 
         while(p-->0)
         {
           scanf("%d%d",&nr,&cst);
           cost[i][nr]=cst;            
         }         
      }warshal(r);
       scanf("%d",&k);
       while(k-->0)
       { 
            scanf("%s%s",source,destin);        
            search(source,destin,&s,&d);
            printf("\n%d",cost[s][d]);             
       }         
    }
    getch() ;
    return 0;
}
