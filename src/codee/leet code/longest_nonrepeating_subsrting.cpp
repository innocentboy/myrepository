/**
Given a string, find the length of the longest substring without repeating characters.
 For example, the longest substring without repeating letters for "abcabcbb" is "abc",
 which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

*/

#include<cstdio>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,k,len=s.length();
        if(len==0) return 0;
        if(len==1) return 1;
        int a[26];
        for(i=0;i<26;i++) a[i]=-1;
        int cur_len=1,maxlen=-1;
        a[s[0]-'a']=0;
        for(i=1;i<len;i++)
        {
           j=a[s[i]-'a'];
           if(j==-1||j+cur_len<i)
           cur_len++;
           else
           {
               if(cur_len>maxlen)
               maxlen=cur_len;
               cur_len=i-j;
           }
           a[s[i]-'a']=i;

        }
        if(cur_len>maxlen)
        maxlen=cur_len;
        return maxlen;
    }
};
