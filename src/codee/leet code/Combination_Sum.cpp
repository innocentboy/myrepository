/**
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where
the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, ... , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ ... ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set [2, 3, 6, 7] and target 7

A solution set is:

[
  [7],
  [2, 2, 3]
]
*/

class Solution {
public:
    void helper(vector<vector<int> > &r, vector<int> &cand, vector<int> x, int target, vector<int>::iterator beg) {
        if (target == 0) {
            r.push_back(x);
            return;
        }
        else {
            for (vector<int>::iterator it=beg; it != cand.end(); ++it) {
                if (target - *it >= 0) {
                    x.push_back(*it);
                    helper(r, cand, x, target-*it, it);
                    x.pop_back();
                }
                else
                break;
            }
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > r;
        vector<int> x;
        sort(candidates.begin(), candidates.end());
        helper(r, candidates, x, target, candidates.begin());
        return r;
    }
};

