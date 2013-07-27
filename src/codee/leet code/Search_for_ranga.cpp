/**
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]
*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,s,e,l,u,m;
        vector<int> ans;
        s=0;e=n-1;
        while(s<e)
        {
          m=(s+e)/2;
          if(A[m]<target)
          s=m+1;
          else e=m;
        }
        if(A[s]==target)
        l=s;
        else
        {
          ans.push_back(-1);
          ans.push_back(-1);
          return ans;
        }

        s=0;e=n;
        while(s<e)
        {
          m=(s+e)/2;
          if(A[m]>target)
          e=m;
          else s=m+1;
        }
        u=e-1;
        ans.push_back(l);
        ans.push_back(u);
        return ans;
    }
};
