/**
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, � , ak) must be in non-descending order. (ie, a1 ? a2 ? � ? ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/

#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;

class Solution {
public:

     void helper(set<vector<int> > &res,vector<int> temp,vector<int> &num, int target,vector<int>::iterator it)
    {
        if(target==0)
        {
          res.insert(temp);
          return;
        }
        for(vector<int>::iterator itr=it;itr!=num.end();itr++)
        {
           if(target>=*itr)
           {
               temp.push_back(*itr);
               helper(res,temp,num,target-*itr,itr+1);
               temp.pop_back();
            }

        }


    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > vvi;
        set< vector<int> > res;
        vector<int> temp;
        sort(num.begin(),num.end());
        helper(res,temp,num,target,num.begin());
        for (set<vector<int> >::iterator it=res.begin(); it!=res.end(); ++it)
            vvi.push_back(*it);
        return vvi;
    }

};
