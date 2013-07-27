/**
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on
the row below.

For example, given the following triangle
[
     [2],
     [3,4],
     [6,5,7],
     [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

*/

#define N 1000000
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,k,size=triangle.size();
        int p[size];
        for(i=0;i<size+2;i++) p[i]=0;
        while(size--)
        {
            for(i=0;i<=size;i++)
            {
                p[i]=triangle[size][i]+((p[i]<p[i+1])?p[i]:p[i+1]);
            }
        }
        return p[0];
    }
};
