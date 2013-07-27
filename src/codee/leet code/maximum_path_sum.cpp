/**
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which
minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

*/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,k,m,n,minsum=0;
        m=grid.size();
        n=grid[0].size();
        int dp[m+1][n+1];
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==0||j==0)
                {
                    if(i==0&&j==0)
                    dp[i][j]=grid[0][0];
                    else if(i==0)
                    dp[i][j]=grid[i][j]+dp[i][j-1];
                    else
                    dp[i][j]=grid[i][j]+dp[i-1][j];

                }
                else
                {
                    int l,u;
                    u=dp[i-1][j];
                    l=dp[i][j-1];
                    dp[i][j]=grid[i][j]+(u<l?u:l);

                }
            }
        }
        return dp[i-1][j-1];

    }
};
