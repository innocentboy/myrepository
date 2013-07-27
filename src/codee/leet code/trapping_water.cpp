/**
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much
water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


*/

#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l[n],r[n],i,j,k,maxx=0;
        stack<int> st;
        for(i=0;i<n;i++)
        {
            if(st.empty())
            {
               l[i]=-1;
               st.push(A[i]);
            }
            else
            {
                while(!st.empty()&&st.top()<A[i]) st.pop();
                if(st.empty())
                {
                   st.push(A[i]);
                   l[i]=-1;
                }
                else
                {
                    l[i]=st.top();
                }


            }
        }
        while(!st.empty()) st.pop();

        for(i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
               r[i]=-1;
               st.push(A[i]);
            }
            else
            {
                while(!st.empty()&&st.top()<A[i]) st.pop();
                if(st.empty())
                {
                   st.push(A[i]);
                   r[i]=-1;
                }
                else
                {
                    r[i]=st.top();
                }


            }
        }
        for(i=0;i<n;i++)
        {
            if(l[i]==-1||r[i]==-1)
            continue;
            else
            {
                maxx+=min(l[i],r[i])-A[i];
            }
        }
        return maxx;

    }
};
