/**

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time
(ie, you must sell the stock before you buy again).

*/

#include<cstdio>
#include<vecctor>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,k,ans=0,n=prices.size();
        if(n==0||n==1) return 0;
        int history[n],future[n];
        int minn=0,maxx=0;
        for(i=0;i<n;i++)
        history[i]=future[i]=0;
        minn=prices[0];
        for(i=1;i<n;i++)
        {

            minn=min(prices[i],minn);
            history[i]=max(history[i-1],prices[i]-minn);

        }
        maxx=prices[n-1];
        for(i=n-2;i>=0;i--)
        {

            maxx=max(prices[i],maxx);
            future[i]=max(future[i+1],maxx-prices[i]);

            //ans=max(ans,history[i]+future[i+1]);
        }
        for(i=0;i<n;i++)
        ans=max(ans,(history[i]+future[i]));
        return ans;
    }
};

