/**
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.
For example,
Given height = [2,1,5,6,2,3],
return 10

*/

#include<algorithm>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,k,n=height.size();
        if(n==0) return 0;
        int ans=0;
        int dp[n],minn=0;
        for(i=0;i<n;i++) dp[i]=0;
        for(i=0;i<n;i++)
        {
            minn=height[i];
            for(j=i;j>=0;j--)
            //ans=max(ans,min(height[i],height[j])*(j-i+1));
            {
                if(minn>height[j])
                {
                    dp[i]=max(dp[i],(minn)*(i-j+1));
                    minn=height[i];
                }
                dp[i]=max(dp[i],(minn)*(i-j));
            }


        }
        for(i=0;i<n;i++)
        ans=max(ans,dp[i]);
        return ans;
    }
};
