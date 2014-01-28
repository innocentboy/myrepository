/**
LINK::http://www.codechef.com/problems/PPNUM
*/
/**
INPUT:
1
9 12

OUTPUT:
75

*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MOD 1000000007
using namespace std;

int poww(int i,int j)
{
    int ans=10;
    j--;
    while(j--)
    {
      ans*=i;
    }
    return ans;
}

int main()
{
    int i,j,k,t,l,r;
    long long ans=0;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d%d",&l,&r);

        //find the No of digits present in the L.
        i=0;j=l;
        while(j>0)
        {
          i++;
          j=j/10;
        }
        j=l;
        while(j<=r)
        {
            //Calculate the right value of the segment.
            //As left value is already in the j variable.
            k=min(poww(10,i)-1,r);
            long long t1,t2;
            t1=(k+j);
            t2=i;
            t1=t1*t2;
            t2=(k-j+1);
            ans=(ans+(((t1*t2)/2)%MOD))%MOD;
            //Increment the No of digits.
            i++;
            //Reset the left value of next segment by the Previous right segment value plus one.
            j=k+1;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
