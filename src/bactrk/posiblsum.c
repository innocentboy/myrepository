#include<stdio.h>
#include<conio.h>
#define N 4
int summ=N;
void subsetsum(int b[],int,int);
int main()
{
    int a[N]={1,1,1,1},i=0;
    subsetsum(a,1,N);
    getch();
}

void subsetsum(int b[],int r,int j)
{
     int s=0,c[N],a[N],k=0;
    if(j!=1)
    {
            
                    for(k=0;k<j;k++)
                    {
                        printf("%d ",b[k]); 
                        a[k]=b[k]; 
                        if(k!=0)   
                        c[k-1]=b[k];
                    }   
                    printf("\n");
                    c[0]=b[0]+b[1]; 
                    a[j-2]=a[j-2]+a[j-1];
                    if(r==1)                 
                         subsetsum(c,1,j-1);
                         subsetsum(a,0,j-1);
                          
                    }
}
