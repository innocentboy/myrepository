/**
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1]


*/

class Solution {
public:

    long long fact(int n)
    {
        long long i=n,j,ans=1;
        if(n==0) return 1;
        while(i>0)
        ans*=i--;
        return ans;
    }
    int combination(int n,int r)
    {
        long long i,j,k,m;
        long double ans=1;
        if((r)>n-r)
        {
          i=r;j=n-r;
        }
        else
        {
           j=r;i=n-r;
        }
        m=fact(j);
        while(n>i)
          ans*=n--;
        ans=ans/m;
        return (int)ans;
    }

    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,min=1,n=rowIndex;
        vector<int> v(n+1,-1);
        for(i=0;i<=n;i++)
        {
            v[i]=(int)combination(n,i);
        }
     return v;

    }
};
