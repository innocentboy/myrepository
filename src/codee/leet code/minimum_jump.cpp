/**

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/


/**
METHOD :1
*/
#include<algorithm>
using namespace std;
class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0||n==1) return 0;
        int i=0,j,k=A[0]+1,min=1,l;

        while(i+k<n){
            min++;
            j=A[i++];k=-1;
            while(j--){
            if(k<A[i])
            {
                k=A[i];
                l=i;
            }
            i++;
            }
            i=l;

        }
        return min;

    }
};


/**
METHOD 2:
*/
class Solution {
public:
    int jump(int A[], int n) {
        int ret = 0;
        int last = 0;
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            if (i > last) {
                last = curr;
                ++ret;
            }
            curr = max(curr, i+A[i]);
        }

        return ret;
    }
};
