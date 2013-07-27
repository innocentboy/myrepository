#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<cmath>
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define REP(i,n) for(i=0;i<n;i++)
#define EVER while(1)
#define dbgi(x) printf(#x" = %d\n",x);
#define dbgll(x) printf(#x" = %ll\n",x);
#define gi(i) scanf("%d",&i);
#define gll(i) scanf("%lld",&i);
#define gd(i) scanf("%f",&i);
#define gui(i) scanf("%u",&i);
#define gull(i) scanf("%ull",&i);
#define gs(s) scanf("%s",s);
#define gdi(m,n) scanf("%d%d",&m,&n);
#define ps(s) printf("%s\n",s);
#define pi(i) printf("%d\n",i);
#define pll(i) printf("%ll\n",i);
#define pd(i) printf("%f\n",i);
#define sl(s) strlen(s)
#define nl puts("");
#define mcl(buff) memset(buff,0,sizeof(buff));
#define mst(buff,val) memset(buff,val,sizeof(buff));
#define f first
#define s second
#define x f
#define y s.f
#define z s.s
#define N 1000000
#define pb push_back
#define mp make_pair
#define mt(a,b,c) mp(a,mp(b,c))
 
using namespace std;
 
typedef long long int LL;
typedef int I;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef vector<int> VI;
typedef pair< int,pair< int,int > > tri;
 
pii n1[1005];
int X[1005];
 
int main()
{
I T,i,j,n,in;
gi(T)
while(T--)
{
gi(n)
 
FOR(i,1,n)
{
gi(in)
n1[i].f=in;
}
 
FOR(i,1,n)
{
gi(in)
n1[i].s=in;
 
}
sort(n1+1,n1+n+1);
 
X[0]=0;
FOR(i,1,n){
X[i]=1;
FOR(j,1,i-1)
{
if(n1[i].s >=n1[j].s && X[j]+1 > X[i] )
X[i]=X[j]+1;
}
}
int max=0;
FOR(i,1,n)
if(max<X[i])
max=X[i];
 
printf("%d\n",max);
 
 
}
return 0;
}