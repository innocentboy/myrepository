#include<stdio.h>
#include<conio.h>
#include<math.h>
#define N 8
int b[N][N];
int chessboard(int);
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
    chessboard(0);
    display();
    getch();
}
int good(int i,int j)
{
             int k=0,l=0;
             for(k=i-1;k>=0;k--)
                 for(l=0;l<N;l++)
                     if((b[l][k]==1)&&((i==k||j==l)||(abs(i-k)==abs(j-l))))
                     return 0;
             return 1;


}


/*int isrowclear(int qrow ,int qcol){
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

    }    */

int chessboard(int qcol)
  {

    int rowtotry;
    if(qcol>=N)
      return 1;
    for(rowtotry=0;rowtotry<N;rowtotry++)
    {
      if(good(qcol,rowtotry)){
          b[rowtotry][qcol]=1;
          //display();
          if(chessboard(qcol+1))
          return 1;
          // b[rowtotry][qcol]=0;
         }
         b[rowtotry][qcol]=0;
    }
    return 0;
   }
