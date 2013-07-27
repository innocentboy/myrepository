/**
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array


*/



class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l,r,m,i;
        l=0;r=n-1;
        while(l<=r)
        {
            m=(l+r)/2;
            if(A[m]==target)
            return m;
            if(A[l]<=A[m])
            {
               if(A[l]<=target&&A[m]>target)
               r=m-1;
               else
               l=m+1;
            }
            else
            {
                if(A[m]<target&&A[r]>=target)
                l=m+1;
                else
                r=m-1;
            }
        }
        return -1;

    }
};
