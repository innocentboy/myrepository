#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#define N 26
#define M 1000
using namespace std;
queue < vector <int> > q;
int best[N][N][N][N];
int bad[N][N][N][N];
vector < string > v;
int inf=10000000;

vector<string> parse(string s,string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;
  do
  {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
  }while (p != string::npos);

  return ans;

}

int main()
{
   int i,j,k,l,m,n,t;
   vector<int> vi(4);
   char s[5],f[5],forbid[M][M];
   for(i=0;i<N;i++)
     for(j=0;j<N;j++)
       for(k=0;k<N;k++)
         for(l=0;l<N;l++)
         {
             best[i][j][k][l]=inf;

       }
    for(i=0;i<4;i++)
    vi[i]=s[i]-'a';
    best[vi[0]][vi[1]][vi[2]][vi[3]]=0;
    q.push(vi);
   // v=abc();
   for(t=0;t<n;t++)
   {
     v=parse(forbid[t]," ");
     for(i=0;i<v[0].size();i++)
     {
         for(j=0;j<v[1].size();j++)
           for(k=0;k<v[2].size();k++)
              for(l=0;l<v[3].size();l++)
              {
               bad[v[0][i]-'a'][v[1][j]-'a'][v[2][k]-'a'][v[3][l]-'a']=1;

              }
     }


   }

   while(!q.empty())
   {
      vi=q.front();
      q.pop();
     int  cur=best[vi[0]][vi[1]][vi[2]][vi[3]];
     for(i=0;i<4;i++)
      {
          vi[i]=(vi[i]+1)%N;
          if(!bad[vi[0]][vi[1]][vi[2]][vi[3]]&&best[vi[0]][vi[1]][vi[2]][vi[3]]==inf) {
          best[vi[0]][vi[1]][vi[2]][vi[3]]=cur+1;
          q.push(vi);
          }
          vi[i]=(vi[i]+24)%N;
          if(!bad[vi[0]][vi[1]][vi[2]][vi[3]]&&best[vi[0]][vi[1]][vi[2]][vi[3]]==inf) {
          best[vi[0]][vi[1]][vi[2]][vi[3]]=cur+1;
          q.push(vi);
          }
          vi[i]=(vi[i]+1)%N;
       }
   }
   int ans=best[f[0]-'a'][f[1]-'a'][f[2]-'a'][f[3]-'a'];
   ans=ans<inf?ans:-1;
   printf("\n answer:%d",ans);
    return 0;
}




