/**
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.


*/

#include<string>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int i,j,k,n=s.length();
        if(n==0) return 0;
        int dp[n+1];
        for(i=0;i<=n;i++) dp[i]=0;
        dp[0]=1;
        for(i=1;i<=n;i++)
        {
            if(s[i-1]!='0')
            dp[i]=dp[i-1];
            if(i>=2&&((s[i-2]=='1'&&s[i-1]<='9')||(s[i-2]=='2'&&s[i-1]<='6')))
            dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};
