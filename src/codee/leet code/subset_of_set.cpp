/***
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         int i,j,k,n=S.size();
         int ts=1<<n;
         sort(S.begin(),S.end());
         vector< vector<int> > vt;
         for(i=0;i<ts;i++)
         {
             vector<int> v;
             j=0;
             while(j<n)
             {
                 k=1<<j;
                 if(i&(k))
                 v.push_back(S[j]);
                 j++;
             }
             vt.push_back(v);
         }
         return vt;
    }
};
