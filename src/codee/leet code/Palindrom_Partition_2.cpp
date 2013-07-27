/**

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

class Solution {
public:
    int minCut(string str){

        int leng = str.size();

        int dp[leng+1];
        bool palin[leng][leng];

      for(int i = 0; i <= leng; i++)
        dp[i] = leng-i;
        for(int i = 0; i < leng; i++)
            for(int j = 0; j < leng; j++)
                palin[i][j] = false;

      for(int i = leng-1; i >= 0; i--){
        for(int j = i; j < leng; j++){
          if(str[i] == str[j] && (j-i<2 || palin[i+1][j-1])){
            palin[i][j] = true;
            dp[i] = min(dp[i],dp[j+1]+1);
          }
        }
      }
      return dp[0]-1;
    }
};

