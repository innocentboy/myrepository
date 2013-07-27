#include<stdio.h>
#define N 8
int a[N]={1,4,3,6,2,4,8,9};
int LS[N];
int p[N];
int main()
{
    int i,j,k,n,largest=0,inc=0;
    for(i=0;i<=N-1;i++)
    {        
        LS[i]=1;
        p[i]=-1;
        for(j=0;j<=i-1;j++)
        if (a[i]>a[j]&&LS[i]<=LS[j])
        {                        
            LS[i] = LS[j]+1;
            p[i]=j;inc++;
        }
    }                                
    for(i=0;i<=N-1;i++)
    if (largest < LS[i])
    {
      largest = LS[i];
      n=i;  
    }
    printf("largest:%d seq:%d\n",largest,inc);
    while(n!=-1)
    {
     printf("%d ",a[n]);
     n=p[n];              
    }
    getch();
    return 0;    
}
