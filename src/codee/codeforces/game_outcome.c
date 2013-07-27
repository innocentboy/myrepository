#include<stdio.h>
#include<conio.h>
#define N 31
int arr[N][N];
int col[N];
int row[N];
int main()
{
   int i,j,k,t,n,cnt=0;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      row[i]=0;             
      for(j=0;j<n;j++)
      {
         scanf("%d",&arr[i][j]);
         row[i]+=arr[i][j];                
      }                
   }
   for(j=0;j<n;j++)
   {
      col[j]=0;
      for(i=0;i<n;i++)
      {
         col[j]+=arr[i][j];                
      }                
   }
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
         if(col[j]>row[i])cnt++;                
      }                
   } 
   printf("%d\n",cnt);
   getch(); 
   return 0;    
}
