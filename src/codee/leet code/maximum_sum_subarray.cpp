/**
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,maxsum=A[0],cursum=0;
        for(i=0;i<n;i++)
        {
            cursum+=A[i];
            if(cursum>maxsum)
                maxsum=cursum;

            if(cursum<0)
            {
                cursum=0;
            }

        }
        return maxsum;

    }
};
