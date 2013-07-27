/**
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
design an algorithm to find the maximum profit.

EXAMPLE:
INPUT:[2,6,8,7,8,7,9,4,1,2,4,5,8]
OUTPUT:7

INPUT:[5,2,3,0,3,5,6,8,1,5]
OUTPUT:8



*/

/**
METHOD:1
*/

#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,k,n=prices.size();
        if(!n) return 0;
        for(i=0;i<n-1;i++)
        prices[i]=prices[i+1]-prices[i];
        int maxprofit=0,curprofit=0;
        for(i=0;i<n-1;i++)
        {
           curprofit+=prices[i];
           if(curprofit>maxprofit)
           maxprofit=curprofit;
           if(curprofit<0)
           curprofit=0;
        }
        if(curprofit>maxprofit)
        maxprofit=curprofit;
        return maxprofit;
    }
};


/**
METHOD:2
*/
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,k,n=prices.size();
        if(!n) return 0;
        int minn=prices[0],maxx=prices[0];
        int ans=0;
        for(i=1;i<n;i++)
        {
            ans=max(ans,prices[i]-minn);
            if(minn>prices[i])
            minn=prices[i];
        }
        return ans;
    }
};

