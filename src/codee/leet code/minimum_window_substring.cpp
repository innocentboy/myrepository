/**
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

*/


#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ansb=-1,anse=-1;
        int hasToFind[256],needToFind[256],i,j,k;
        int slen=S.length(),tlen=T.length();
        int minnWindow=999999,b=-1,e=0,count=0;
        for(i=0;i<256;i++) needToFind[i]=hasToFind[i]=0;
        for(i=0;i<tlen;i++)
        needToFind[T[i]]++;
        for(i=0;i<slen;i++)
        {
            if(needToFind[S[i]]==0)
            continue;
            hasToFind[S[i]]++;
            if(hasToFind[S[i]]<=needToFind[S[i]])
            count++;
            if(count==tlen)
            {
                e=i;
                if(b==-1)
                b=0;
                while(needToFind[S[b]]==0||hasToFind[S[b]]>needToFind[S[b]])
                {
                    if(needToFind[S[b]]==0);
                    else
                    {
                        hasToFind[S[b]]--;
                    }
                    b++;
                }
                int minn=e-b+1;
               if(minn<minnWindow)
               {
                  ansb=b;anse=e;
                  minnWindow=min(minnWindow,minn);
               }
            }

        }
        if(ansb==-1)
        return "";
        return S.substr(ansb,(anse-ansb)+1);

    }
};
