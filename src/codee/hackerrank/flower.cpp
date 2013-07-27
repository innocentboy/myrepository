/**


*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 109
int a[N];
using namespace std;
inline bool comp(int a,int b)
{
  if(a>b) return true;
  else return false;
}

int main()
{

     int i,j,n,k;
     scanf("%d%d",&n,&k);
     for(i=0;i<n;i++)
     scanf("%d",&a[i]);
     sort(a,a+n,comp);

    /* printf("\nafter soritng..\n");
     for(i=0;i<n;i++)
     printf("%d ",a[i]);
     printf("\nanswer:");
     */
     long long ans=0;
     int x=1;
     for(i=0;i<n;)
     {
        if(n-i<k)
        {
          k=n-i;
        }
        for(j=0;j<k;j++)
        {
            //printf("a[i]:%d \n",a[i+j]);
            ans+=x*a[i+j];
        }
        i=i+k;x++;
      }
      printf("%lld\n",ans);
     return 0;
}
