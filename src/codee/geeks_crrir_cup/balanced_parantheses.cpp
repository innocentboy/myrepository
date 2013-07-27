#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<stack>
#define N 1000
using namespace std;

int strlen(char *s){

    int i=0,c=0;
    while(s[i++])c++;
    return c;
}

bool check_expression(map<char,int> &mp,stack<int> &st,char *s)
{
   int i,j,k,len=0;
   len=strlen(s);
   mp['[']=3;mp['{']=2;mp['(']=1;
   mp[']']=-3;mp['}']=-2;mp[')']=-1;
   for(i=0;i<len;i++)
   {
      if(s[i]=='['||s[i]=='{'||s[i]=='(')
      {
          if(st.empty()) st.push(mp[s[i]]);
          else
          {
              if(mp[s[i]]<=st.top()) st.push(mp[s[i]]);
              else return false;

            }
      }
      else
      {
          if(st.empty()) return false;
          else if(mp[s[i]]+st.top()==0)
          st.pop();
          else return false;

       }

   }
   if(st.empty()) return true;
   else return false;
}

int main()
{
   int i,j,k,n,t;
   scanf("%d",&t);
   char exp[100];
   map<char,int> mp;
   stack<int> st;
   while(t--){
   scanf("%s",exp);
   if(check_expression(mp,st,exp))
   printf("\nit's valide expression..\n");
   else
   printf("\nit's invalide expression..\n");
   }
   return 0;
}
