/**

THIS FILE WILL PRINT THE ALL LONGEST COMMEN SUBSEQUENCE OF TWO STRINGS..
*/
#include<cstdio>
#include<sstream>
#include<iostream>
#include<vector>
#include<set>
#include<string>
#define N 101

using namespace std;

char str1[N];
char str2[N];
int  c[N][N];
char path[N][N];

set<  string > uniq;
vector< string > res;
vector < pair<int,int> > arr[1000][26];

int max(int i,int j)
{
  return (i>j?i:j);
}

/**
THIS FUNCTION PRINTS THE LONGEST SUBSEQUENCE OF STRINGS.
*/
void print_path(int i,int j)
{
   if(i==0||j==0)return;
   else if(path[i][j]=='d')
   {
        print_path(i-1,j-1);
        printf("%c ",str1[i]);
   }
   else if(path[i][j]=='D')print_path(i,j-1);
   else print_path(i-1,j);
}

/**

THIS FUNCTION TRY TO FIND OUT THE ALL LONGEST SUBSEQUNCES OF THE GIVEN STRINGS.
*/

void allSubsequence(int ls1,int ls2,string str,int maxlen)
{
    int i,j,k,d,len;
    d=maxlen;
    if(d==0)
    {
       if(uniq.count(str)==0)
       {

          uniq.insert(str);
          res.push_back(str);
        }
        return;
    }
    for(i=0;i<26;i++)
    {
       len=arr[d][i].size();
       for(j=0;j<len;j++)
       {
          pair<int,int> pr;
          pr=arr[d][i][j];
          //string s;
          //s.assign(i+'a');
          char c=i+'a';
          if(pr.first<ls1&&pr.second<ls2)
          {
              allSubsequence(pr.first,pr.second,c+str,d-1);
            }
        }
    }

}

int main()
{
   int i,j,k,n,m,t;
   scanf("enter the value of strings...\n");
   scanf("%s%s",str1+1,str2+1);
   n=strlen(str1+1);m=strlen(str2+1);
   printf("\nsize: %d  %d\n",n,m);
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=m;j++)
     {
        if(str1[i]==str2[j])
        {
              c[i][j]=c[i-1][j-1]+1;
              path[i][j]='d';
        }
        else
        {
             if(c[i-1][j]>c[i][j-1])
             {
                c[i][j]=c[i-1][j];
                path[i][j]='R';
             }
             else
            {

                c[i][j]=c[i][j-1];
                path[i][j]='D';
            }

        }
     }
   }

    printf("\nprint the c array:\n");
    for(i=0;i<=n;i++)
    {
      for(j=0;j<=m;j++)
      printf("%d ",c[i][j]);
      printf("\n");
    }
    printf("\nlength of longest common sequence is:%d\n",c[n][m]);
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=m;j++)
       {
          if(str1[i]==str2[j])
          {
            pair<int,int> pr;
            pr.first=i;
            pr.second=j;
            arr[c[i][j]][str1[i]-'a'].push_back(pr);
          }
       }
    }
    printf("\n");
    int maxlen=c[n][m];
    allSubsequence(n+1,m+1,"",maxlen);
    sort(res.begin(),res.end());
    for(i=0;i<res.size();i++)
    {
        cout<<res[i]<<endl;
    }
    return 0;
}


