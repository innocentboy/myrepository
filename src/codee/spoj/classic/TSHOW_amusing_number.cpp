#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#define N 100000

using namespace std;

int main()
{
    int i,j,t,count;
    long long n,k,pow;
    int c[N];
   // char s[N];
    scanf("%d",&t);
    while(t--)
    {
       count=0;pow=1,n=0;
       scanf("%lld",&k);
       while(n<k)
       {
          pow<<=1;
          n+=pow;
          count++;
        }
        n=n-pow;
        k=(k-n)-1;
       // printf("%lld %d\n",k,count);
       i=count;
       while(k>0)
        {
           c[--i]=(int)k%2;
           k/=2;
        }
        while(i>0)
        c[--i]=0;
        for(i=0;i<count;i++){
        if(c[i])printf("6");
        else printf("5");

        }
        printf("\n");

    }
    return 0;
}
