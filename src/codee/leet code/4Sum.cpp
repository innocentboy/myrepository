/**
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.

Note:

    Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ? b ? c ? d)
    The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

*/
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num,int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,k,n,s,e;
        sort(num.begin(),num.end());
        n=num.size();
        set< vector<int> > st;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++){
            s=j+1;
            e=n-1;
            while(s<e)
            {
                k=num[i]+num[j]+num[s]+num[e];
                if(k==target)
                {
                    vector<int> vt;
                    vt.push_back(num[i]);
                    vt.push_back(num[j]);
                    vt.push_back(num[s]);
                    vt.push_back(num[e]);
                    st.insert(vt);
                }
                if(k<target)
                s++;
                else e--;
            }
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
