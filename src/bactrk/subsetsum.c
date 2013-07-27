#include<stdio.h>
#include<conio.h>
#define N 7
int summ;
void subsetsum(int b[],int a[],int ,int,int);
int main()
{
    int a[N]={1,3,2,4,5,1,7},b[N],i=0;
    printf("enter the value of summ\n");
    scanf("%d",&summ);
    b[0]=0;
    subsetsum(b,a,-1,0,1);
    getch();
}
void subsetsum(int b[],int a[],int i,int sum,int j)
{
     int s=0,c[N],k=0;
    if(i<N-1)
    {
            if(sum==summ)
            {

                    for(k=0;k<j;k++)
                    {
                         if(b[k]==0)
                            continue;
                         printf("%d  ",b[k]);
                    }
                    printf("\n");
                    k=0;
            }


          else
           {
                   subsetsum(b,a,i+1,sum,j);
                   for(k=0;k<j;k++)
                        c[k]=b[k];
                   c[k]=a[i+1];

                   if(sum<summ)
                    {
                         s=sum+a[i+1];
                         subsetsum(c,a,i+1,s,j+1);
                    }
          }
    }
}
