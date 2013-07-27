using namespace std;
class Solution {
    char s[10000];
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
           vector < string > vt;
         if(n>0)
         print_all_paranthese(vt,0,n,0,0);
          return vt;
    }

    void print_all_paranthese(vector <string> &vt,int pos,int n,int open,int close)
  {
    if(close==n)
    {
     // printf("%s\n",s);
      string ss(s);
      vt.push_back(ss);
    }
    else
    {
      if(open>close)
      {
          s[pos]=')';
          print_all_paranthese(vt,pos+1,n,open,close+1);
       }
       if(open<n)
       {
           s[pos]='(';
           print_all_paranthese(vt,pos+1,n,open+1,close);
        }
    }

}
};
