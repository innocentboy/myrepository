/**
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some
(can be none) of the characters without disturbing the relative positions of the remaining characters.
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3
*/


/**

Let f(i, j) to be the number of distinct subsequences of T(j:) in S(i:). Consider the ith
character in S. If we can use it to match T[j], namely S[i] == T[j], then

f(i, j) = f(i+1, j+1).

If we do not want use it in our matching, then

f(i, j) = f(i+1, j).

Thus,f(i, j) = f(i+1, j) + (S[i] == T[j]) * f(i+1, j+1).

It is very much the same as how we solve C(n, m) or the knapsack problem.

*/

class Solution {
public:
    int numDistinct(string S, string T) {
        vector<int> f(T.size()+1);
        f[T.size()] = 1;
        for (int i = S.size()-1; i >= 0; --i) {
            for (int j = 0; j < T.size(); ++j) {
                f[j] += (S[i]==T[j])*f[j+1];
            }
        }
        return f[0];
    }
};

/**
METHOD 2: DP
*/
class Solution {
public:

int noOfDistinctSubsequence_DP(string s,string t,int m,int n)
{
   int i,j,k,ls,lt;
   int dp[m+1][n+1];
   for(i=0;i<=m;i++)
   dp[i][0]=1;
   for(i=1;i<=n;i++)
   dp[0][i]=0;
   for(i=1;i<=m;i++)
   {
       for(j=1;j<=n;j++)
       {
          if(s[i-1]==t[j-1])
          dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
          else
          dp[i][j]=dp[i-1][j];
        }
    }
    return dp[m][n];
}
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        return noOfDistinctSubsequence_DP(S,T,S.size(),T.size());
    }
};

/**
METHOD 3: BACTRAKING
*/
int noOfDistinctSubsequence(string s,string t,int m,int n)
{
   if(m<0||n<0) return 0;
   if(m==0&&n==0) return 1;
   if(m!=0&&n==0) return 1;
   if(m==0&&n!=0) return 0;
   int sum=0;
   if((s[m-1]==t[n-1]))
   {
       sum=noOfDistinctSubsequence(s,t,m-1,n-1)+noOfDistinctSubsequence(s,t,m-1,n);
    }
   else
      sum=noOfDistinctSubsequence(s,t,m-1,n);
      return sum;
}
