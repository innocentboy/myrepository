#include<stdio.h>
#include<conio.h>
#define N 10
int totl_path=0;
int m[N][N]={
     1,1,1,0,0,0,0,0,0,0,
     1,0,1,0,0,0,0,1,1,1,
     1,1,1,1,1,0,0,0,1,1,
     0,0,1,0,0,1,1,1,0,0,
     0,1,1,1,1,1,1,0,0,0,
     0,0,1,1,0,0,1,1,0,1,
     0,0,0,0,0,0,1,1,1,0,
     1,1,0,1,0,0,0,1,1,1,
     0,0,0,0,0,1,1,1,0,0,
     0,1,0,0,0,1,1,1,1,1
    
    };
int showpath[N][N];
int maze(int,int,int,int);
int main()
{
    int path=0,i,j;
    printf("enter the value of maze...\n");
  //  for(i=0;i<N;i++)
   //    for(j=0;j<N;j++)
   //    scanf("%d",&m[i][j]);
    path=maze(0,0,-1,-1);
    if(path)
    {
       printf("\nthere is a path in the maze...");
       printf("\n total no of paths:%d\n",totl_path);
       for(i=0;i<N;i++)
       {
         for(j=0;j<N;j++)
         {
            if(showpath[i][j])             
                 printf("* ");
            else 
                 printf("B ");
         }
            printf("\n");
       }     
    }  
    else
       printf("\nthere is no path in the maze..");
    getch();      
    
}
int maze(int row,int col,int prerow,int precol)
{
  
    showpath[row][col]=1;  
    if(row==N-1&&col==N-1)
    {
        totl_path++;                      
        return 1;  
    }    
    if((row+1<N)&&(row+1)!=prerow&&m[row+1][col]&&maze(row+1,col,row,col))
       return 1;
    if((col+1<N)&&(col+1)!=precol&&m[row][col+1]&&maze(row,col+1,row,col))
       return 1;
    if((row-1>=0)&&(row-1)!=prerow&&m[row-1][col]&&maze(row-1,col,row,col))
       return 1; 
    if((col-1>=0)&&(col-1)!=precol&&m[row][col-1]&&maze(row,col-1,row,col))
       return 1;   
   // showpath[row][col]=0;                  
    return 0;
}
