#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#define N 4009
using namespace std;
//int a[N][N],n,m;
//int dp[N][N];
char c[N][N];
stack<int> st;
vector<int> d(N,-1),d1(N),d2(N);
int main()
{

   int i,j,k,t,m,n,f,ans=0;
   while(scanf("%d%d%d",&n,&m,&f)&&n!=0)
   {
      gets(c[0]);
      ans=0;
      int res=0;
      for(i=0;i<n;i++)
      gets(c[i]);
      for(j=0;j<m;j++)
      d[j]=-1;
      for(i=0;i<n;i++)
      {
         for(j=0;j<m;j++)
         {
            if(c[i][j]=='C')
            d[j]=i;
         }
          while(!st.empty()) st.pop();
         for(j=0;j<m;j++)
         {
            while(!st.empty()&&d[j]>=d[st.top()])st.pop();
            d1[j]=st.empty()?-1:st.top();
            st.push(j);
         sss}
          while(!st.empty()) st.pop();
          for(j=m-1;j>=0;j--)
          {
              while(!st.empty()&&d[j]>=d[st.top()]) st.pop();
              d2[j]=st.empty()?m:st.top();
              st.push(j);
            }
          for(j=0;j<m;j++)
          {
              ans=max(ans,(i-d[j])*(d2[j]-d1[j]-1));
              printf("%d ",(i-d[j])*(d2[j]-d1[j]-1));
              if((i-d[j])>=2&&(d2[j]-d1[j]-1)>=2)
              res++;
            }
            printf("\n");
      }
        printf("%d %lld\n",res,(long long)ans*f);
    }
   return 0;
}
