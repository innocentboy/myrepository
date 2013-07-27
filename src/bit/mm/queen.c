#include<stdio.h>
#include<conio.h>
#include<math.h>
#define N 8
int b[N][N];
int chessboard(int,int);
int good(int ,int);
void display(){
     int i,j;
      printf("dispaly the positions of queens \n");
    for(i=0;i<N;i++)
     {
       for(j=0;j<N;j++)
      {      if( b[i][j]==1)
               printf(" Q ");
               else printf(" _ ");
                                     
       }
       printf("\n");
     } 
     
     
     }
int main()
{
    int i,j,k;
   // printf("intialize the value of array with zero values \n");
    for(i=0;i<N;i++)
      for(j=0;j<N;j++)
         b[i][j]=0;
    chessboard(0,0);
  /*  printf("dispaly the positions of queens \n");
    for(i=0;i<N;i++)
     {
       for(j=0;j<N;j++)
      {
               printf("%d  ",b[i][j]);
                                     
       }
       printf("\n");
     } */
     display();
    getch();
}
/*
int good(int i,int j)
{
             int k=0,l=0;
             for(k=i-1;k>=0;k--)
                 for(l=0;l<N;l++)
                     if((b[k][l]==1)&&((j==l)||(abs(i-k)==abs(j-l))))
                     return 0;
             return 1;    
    
    
} */


int isrowclear(int qrow ,int qcol){
    int i;
    for(i=0;i<=qcol;i++)
    if(b[qrow][i]==1)
    return 0;
    return 1;
    
} 


int isupperdigclear(int qrow,int qcol){
 int i,j;
 for(i=qrow,j=qcol; i>=0 && j>=0;i--,j--)
    if(b[i][j]==1)
    return 0;
  return 1;     
    
    
} 

int islowerdigclear(int qrow,int qcol){
 int i,j;
 for(i=qrow,j=qcol; i<=N && j>=0;i++,j--)
    if(b[i][j]==1)
    return 0;
  return 1;     
    
    
}         

int good(int qcol,int qrow){
    
    
    return(isrowclear(qrow,qcol)&& isupperdigclear(qrow,qcol) && islowerdigclear(qrow,qcol));
    
    }   

int chessboard(int qcol,int row)
  {
                   
    int rowtotry;
    if(qcol>=N)
      return 1;
    for(rowtotry=0;rowtotry<N;rowtotry++)
    {
      if(good(qcol,rowtotry)){
          b[rowtotry][qcol]=1;
          //display();
          if(chessboard(qcol+1,row+1))
          return 1;
           b[rowtotry][qcol]=0;
         }
         }                                     
    return 0;                                      
   }                                                                                              
                   
                   
                   
                   
                   
                 



/*chessboard(int k, int l)
{
     int i,j,t=0,x,y,m,o;
     x=k;
     y=l;
     b[x][y]=1;
     for(i=1;i<N;i++)
      {
                       for(j=0;j<N;j++)
                       {
                                    if(good(i,j))      
                                    {
                                            b[i][j]=1;
                                            t=1;
                                            break;                   
                                    }      
                       }display();               
                        if(t!=1)
                        { 
                            
                            if((y+1)<N)
                             {       
                                for(m=0;m<N;m++)
                                     for(j=0;j<N;j++)
                                         b[m][j]=0;
                                    printf("\ncall: (%d,%d)\n",x,y+1);      
                                chessboard(x,y+1);
                                return ;
                             }
                       }
                    t=0;    
       }   
       return ;
}   */      
