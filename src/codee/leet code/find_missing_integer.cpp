/**
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

*/

#include<cstdio>

class Solution {
public:
  int firstMissingPositive(int A[], int n) {
    int i = 0;
    while (i < n) {
      if (A[i] >= 0 && A[i] < n && A[A[i]] != A[i]){
        //swap(A[i], A[A[i]]);
        int t,tt=A[A[i]];
        t=A[i];
        A[i]=A[tt];
        A[tt]=t;
      }
      else i++;
      printf("\najbakaasn");
    }
    int k = 1;
    while (k < n && A[k] == k) k++;
    if (n == 0 || k < n) return k;
    else return A[0] == k ? k + 1 : k;
  }
};



int main()
{
  int n;
  int A[]={3,4,-1,1};
  n=4;
  Solution s;
  printf("\nmissing integer:%d\n",s.firstMissingPositive(A,n));
  return 0;
}
