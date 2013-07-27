/**
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1
must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

*/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
  static  bool compar(pair<int,int> a,pair<int,int> b)
   {
      if(a.first<b.first) return true;
      else return false;
   }
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,k,ind1,ind2;
        vector<int> a;
        pair<int,int> p;
        int size=numbers.size();
        vector< pair<int,int> > nw;
        for(i=0;i<size;i++)
        {
            p.first=numbers[i];
            p.second=i;
            nw.push_back(p);
        }
        vector< pair<int,int> >::iterator b,e;
        b=nw.begin();e=nw.end();
        sort(b,e,Solution::compar);
        i=0;j=size-1;
        while(i<size&&j>=0)
        {
            if(nw[i].first+nw[j].first==target)
            break;
            else if(nw[i].first+nw[j].first>target)
            j--;
            else i++;

        }

            a.push_back(nw[i].second+1);
            a.push_back(nw[j].second+1);
            sort(a.begin(),a.end());
        return a;
    }
};
