/**
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/

/**

METHOD1 :Backtracking solutio
*/


    class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> vec;
        vector<int> index;

        if(s.length() == 0)
            return vec;

        index.push_back(-1);
        f(s, 0, vec, index);
        return vec;
    }

    void f(string s, int i, vector<vector<string>> &vec, vector<int> &index) {
        if(i == s.length()){
            vector<string> v;
            int len = index.size();
            for(int k = 0; k < len-1; k++)
                v.push_back(s.substr(index[k]+1, index[k+1]-index[k]));

            vec.push_back(v);
            return;
        }

        for(int j = i; j < s.length(); j++) {
            if(isPalindrome(s, i, j)) {
                index.push_back(j);
                f(s, j+1, vec, index);
                index.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int i, int j)
    {
        while(i < j)
        {
            if(s[i++] != s[j--])
                return false;
        }

        return true;
    }
};

/**
METHOD 2:DP java code..
*/
public ArrayList<ArrayList<String>> partition(String s) {
    if(s == null || s.length() == 0)
        return new ArrayList<ArrayList<String>>();
    boolean[][] isPa = new boolean[s.length()][s.length()];
    for(int i = 0; i < s.length(); i++){
        isPa[i][i] = true;
    }
    for(int i = s.length() - 2; i >= 0; i --){
        isPa[i][i + 1] = s.charAt(i) == s.charAt(i + 1);
        for(int j = i + 2; j < s.length(); j++)
            isPa[i][j] = (s.charAt(i) == s.charAt(j)) && isPa[i + 1][j - 1];
    }
    return partitionHelper(s, 0, isPa);
}

public ArrayList<ArrayList<String>> partitionHelper(String s, int start, boolean[][] isPa){
    ArrayList<ArrayList<String>> pa = new ArrayList<ArrayList<String>>();
    if(start == s.length()){
        pa.add(new ArrayList<String>());
        return pa;
    }
    for(int i = start; i < s.length(); i++){
        if(isPa[start][i])
            for(ArrayList<String> subPa: partitionHelper(s, i + 1, isPa)){
                subPa.add(0, s.substring(start, i + 1));
                pa.add(subPa);
            }
    }
    return pa;
}


