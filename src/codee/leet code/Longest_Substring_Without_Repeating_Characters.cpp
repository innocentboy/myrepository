/**
Given a string, find the length of the longest substring without repeating characters. For example,
the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb"
the longest substring
is "b", with the length of 1.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,k,n,cur_len,maxx;
        int dp[26];
        n=s.size();
        if(!n) return 0;
        for(i=0;i<26;i++)
        dp[i]=-1;
        dp[s[0]-'a']=0;
        maxx=-1;cur_len=1;
        for(i=1;i<n;i++)
        {
            int index=dp[s[i]-'a'];
            if(index==-1||i-cur_len>index)
            {
                cur_len++;
            }
            else
            {
                if(cur_len>maxx)
                maxx=cur_len;
                cur_len=i-index;
            }
            dp[s[i]-'a']=i;
        }
        if(cur_len>maxx)
                maxx=cur_len;
        return maxx;
    }
};
