/**
LINK:::http://oj.leetcode.com/problems/longest-palindromic-substring/
*/

/**
NOTE: Since there are total , N*N substrings are possible for a string of length N.
      So we use a DP[][], array for storing the valide palindrom in the given range.
      And will use that for the processing of further substring. Start traversing the
      string from the end , keep moving towards the Starting of the string.
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define MOD 1000000007
#define N  1005
using namespace std;

string longestPalindrome(string s)
{
    int i,j,k,n;
    n=s.size();
    bool dp[N][N]={false};
    int ans=0;
    k=-1;
    for(i=n-1;i>=0;i--)
    {

        for(j=i;j<n;j++)
        {
            if(s[i]==s[j]&&((j-i)<2||dp[i+1][j-1]))
            {
                dp[i][j]=true;
                if((j-i+1)>ans)
                {
                    ans=j-i+1;
                    k=i;
                }
            }
        }
    }
    return s.substr(k,ans);
}

int main()
{
    string s("abcabbada");
    cout<<"string: "<<longestPalindrome(s)<<endl;

    return 0;
}
