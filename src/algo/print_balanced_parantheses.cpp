/**
this file prints the all balanced parantheses.
EX:
N=2;
{}{}
{{}}
*/
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#define N 10000
using namespace std;
char s[N];

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

vector< string > printParenthesis(int n)
{
   vector < string > vt;
   if(n>0)
   print_all_paranthese(vt,0,n,0,0);
   return vt;
}


int main()
{

    int i,j,k,n;
    scanf("%d",&n);
    vector < string > vt=printParenthesis(n);
    for(i=0;i<vt.size();i++)
    cout<<vt[i]<<endl;
    return 0;
}
