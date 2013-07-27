#include<stdio.h>
#define N 500002
int arr[N];
int main()
{
    
    int i,j,k,n,t;
    int sum=0;
    for(i=2;i<=N;i++)arr[i]=1;
    for(i=2;i<=sqrt(N);i++){
          for(j=i*i;j<=N;j=j+i)
          {
            arr[j]+=i;
            if(i!=(j/i))arr[j]+=j/i;  
          } 
    }
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d",&n);
       printf("%d\n",arr[n]);     
    }
    getch();
    return 0;    
}
