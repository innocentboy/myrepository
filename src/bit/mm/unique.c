#include<stdio.h>
#define N 8
int main()
{
    int a[N][N],A[N],i,j,k,n,text=1;
    printf("enter the dimention fo matixe"); 
    scanf("%d",&n);
    printf("enter the element of array");
    for(i=0;i<n;i++)
    {
                    A[i]=0;
                    for(j=0;j<n;j++)
                    scanf("%d",&a[i][j]);                
    }   
    for(i=0;i<n;i++)
    {
                    for(j=i+1;j<n;j++)
                    {
                                    if(A[j]!=1)
                                         for(k=0;k<n;k++)
                                    {
                                                    if(a[i][k]!=a[j][k])
                                                    {
                                                                        A[j]=0;
                                                                        text=0;   
                                                                        break;                 
                                                    }                
                                                    A[j]=1;
                                    }
                                                    
                    }                
                    
    }
    printf("print only the unique rows of the array....");
    for(i=0;i<n;i++)
    {
                    if(A[i]!=1)
                    {
                               for(j=0;j<n;j++)
                               printf("%d   ",a[i][j]);           
                               
                    }                
                    printf("\n");
    }
    getch();
    
}
