#include<stdio.h>
#define N 5000
int arr[N];
int f[1001];
int main()
{
    
    int i,j,k=0,n,t;
    int sum=0;
    for(i=2;i<=N;i++)arr[i]=0;
    for(i=2;i<=sqrt(N);i++){
          if(arr[i]==0)                  
          for(j=i;j<=N;j=j+i)
          arr[j]+=1; 
    }j=1;
    for(i=2;i<=N;i++)
    {
      if(arr[i]>=3)
      f[j++]=i;
      if(j==1002)break;                 
    }
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d",&n);
       printf("%d\n",f[n]);     
    }
    getch();
    return 0;    
}

