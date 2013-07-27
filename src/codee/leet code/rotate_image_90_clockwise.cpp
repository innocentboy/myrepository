/**
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/



/**
METHOD1: by using another array for storage..
*/
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,k,n=matrix.size();
        int v[n+1][n+1];
        for(i=0;i<n;i++)
        {
            for(j=n-1;j>=0;j--)
            v[i][n-1-j]=matrix[j][i];
        }
        for(i=0;i<n;i++)
          for(j=0;j<n;j++)
          matrix[i][j]=v[i][j];
    }
};


/**
METHOD1: inplace rotation of the array..
*
/


