/**
http://www.codechef.com/problems/MAANDI
*/
/**
NOTE: This prblem is all about finding the All divisers of any given Number.
*/

#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <cmath>
#include <cstring>
using namespace  std;
#define N 1005
#define M 1000000007

bool isLucky(int n)
{
    int i;
    while(n>0)
    {
        i=n%10;
        n/=10;
        if(i==4||i==7)
        return true;
    }
    return false;
}

int main()
{
    int i,j,k,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        j=0;
        for(i=1;i*i<=n;i++)
        {
            k=n/i;
            if(n%i==0)
            {
                if(isLucky(i)) j++;
                if(k!=i&&isLucky(k)) j++;
            }
        }
        printf("%d\n",j);
    }

    return 0;
}
