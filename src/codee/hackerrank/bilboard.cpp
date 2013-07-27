/**


*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define N 100006
long long bilird[N];

int main()
{

    int i,j,n,k,dist=1;
    long long ans=0,total=0;
    scanf("%d%d",&n,&k);
    pair<int,int> f,s;
    for(i=0;i<n;i++)
    {
       scanf("%lld",&bilird[i]);
       total+=bilird[i];
    }

   /* for(i=0;i<n;i++)
    printf("%lld ",bilird[i]);
    printf("\ntotal:%lld\n",total);*/

    f.first=s.first=bilird[0];
    f.second=s.second=0;
    ans=0;
    for(i=1;i<n;i++)
    {
       if(dist!=k+1)
       {
           if(bilird[i]<f.first)
           {
                f.first=bilird[i];
                f.second=i;
                if(i+1<n)
                {
                s.first=bilird[i+1];
                s.second=i+1;
                }
            }
            else
            {
                if(bilird[i]<s.first)
                {
                    s.first=bilird[i];
                    s.second=i;
                }
            }
            dist++;
        }
        else
        {
           if(bilird[i]<f.first)
           {
                f.first=bilird[i];
                f.second=i;
                if(i+1<n)
                {
                s.first=bilird[i+1];
                s.second=i+1;
                }
            }

           ans+=f.first;
           dist=i-f.second;
           f=s;
           s.first=bilird[i];
           s.second=i;
        }
    }
    if(dist==k+1)
    {
      ans+=f.first;
    }
    printf("%lld\n",total-ans);
   // scanf("%d",&i);
    return 0;
}
