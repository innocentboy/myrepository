#include<stdio.h>
#include<conio.h>
#define MAX 5
int t;
void track(int [][],int,int);
int main()
{
     int a[MAX][MAX],i=0,j,k;
     printf("enter the values in array");
     for(i=0;i<MAX;i++)
           for(j=0;j<MAX;j++)
           scanf("%d",&a[i][j]);
     track(a,0,0);           
     if(t!=0)
     {
             printf("there exits a path in maze");
             printf("no of path:%d",t);
     }       
     else
       printf("no path exits");
     getch();  
}

void track(int a[MAX][MAX],int i,int j)
{
    if(i<MAX&&j<MAX)
    { 
     if(i==(MAX-1)&&j==(MAX-1))
     {
             t++;
             return ;                            
     }     
     if((j<(MAX-1)))
     {  
             if(a[i][j+1]==0)       
             track(a,i,j+1);                              
     }
     
     
     if((i<(MAX-1)))
     {
             if(a[i+1][j]==0)
             track(a,i+1,j);                              
     }
  }      
}

