/**
this file produces the group of words anagram to each other.
EX:
Sample Input: Resistance, Ancestries, Gainly, Laying, test, troop
There are two sets of anagrams in the input list

Output:
Resistance, Ancestries
Gainly, Laying
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#define N 1000
#define MAXLEN 50
#define MAX 50*26
using namespace std;

int group_anagram(vector<string> &list,vector<vector<vector<int> > > &vg,int &max_len,int &max_sum)
{
   int i,j,k,len,sum=0;
   for(i=0;i<list.size();i++)
   {
      string s=list[i];
      len=s.length();
      sum=0;
      for(j=0;j<len;j++)
      {
        sum+=s[j]-'a';
      }
      vg[len][sum].push_back(i);
      if(sum>max_sum)
      max_sum=sum;
      if(len>max_len)
      max_len=len;
   }
}


void check_vector_function()
{
  vector<int> v (7,-1);
  cout << "myvector contains:";
  //v.emplace(v.begin(),10);
  for (vector<int>::iterator it=v.begin();it!=v.end();++it)
  cout <<' '<<*it;
  cout << '\n';

}

int main()
{
  vector<string> list;
  vector<int> vt(MAX);
  vector<vector<vector<int> > > vg(MAXLEN,vector<vector<int> > (MAX,vector<int> (1,-1)));
  int i,j,k,n,max_len=0,max_sum=0;
  string ss("sdfss"),s1;
  const char *s=ss.c_str();
  scanf("%d",&n);
  for(i=0;i<n;i++){
  cin>>s1;
  list.push_back(s1);
  }
  printf("\nprint the list\n");
  for(i=0;i<n;i++)
  cout<<list[i]<<endl;
  group_anagram(list,vg,max_len,max_sum);
  printf("\nprint the all grouped anagrams..\n");
  for(i=0;i<=max_len;i++)
  {
     if(vg[i].size())
     for(j=0;j<=max_sum;j++)
     {
        vector<int> v=vg[i][j];
       if(v.size()>2)
        {

          int f;
          for(k=0;k<v.size();k++)
          {
              n=v.at(k);f=0;
              if(n!=-1){
              cout<<list[n]<<" ";
              f=1;
              }
           }
           if(f){
           cout<<endl;
           //printf("size:%d capacity:%d mac_size:%d\n",v.size(),v.capacity(),v.max_size());
           }
        }
      }

   }
  // check_vector_function();
  return 0;
}
