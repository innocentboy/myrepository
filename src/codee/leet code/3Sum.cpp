/**
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ? b ? c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,k,n,s,e;
        sort(num.begin(),num.end());
        n=num.size();
        set< vector<int> > st;
        for(i=0;i<n;i++)
        {
            s=i+1;
            e=n-1;
            while(s<e)
            {
                k=num[i]+num[s]+num[e];
                if(k==0)
                {
                    vector<int> vt;
                    vt.push_back(num[i]);
                    vt.push_back(num[s]);
                    vt.push_back(num[e]);
                    st.insert(vt);
                }
                if(k<0)
                s++;
                else e--;
            }
        }
        vector< vector<int> > res;
        set<vector<int>>::iterator it;
        for(it=st.begin();it!=st.end();it++)
        {
            res.push_back(*it);
        }

        return res;
    }
};
