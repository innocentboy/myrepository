/**
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/
class Solution {
public:

    int helper(int start,int end)
    {
      if(start>end) return 1;
      int sum=0,left,right;
      for(int i=start;i<=end;i++)
      {
        left=helper(start,i-1);
        right=helper(i+1,end);
        sum+=left*right;
      }
      return sum;
    }

    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     return helper(1,n);
    }
};
