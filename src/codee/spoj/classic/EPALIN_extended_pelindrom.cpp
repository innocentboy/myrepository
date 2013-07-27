#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<fstream>
#define MAX_INT 1000000
#define FOR(i,s,e) for(int i=s;i<=e;i++)
#define REP(i,n)   for(int i=0;i<n;i++)
#define si(i)      int i; scanf("%d",&i);
#define gi(i)       scanf("%d",&i);
#define SET(x,a) memset(x,a,sizeof(x));
#define tr(c,i)    for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define pb push_back
#define sz(a) (int)(a.size())
#define INF 100000000000000000LL
#define EPS (double)1e-9
#define is istringstream
#define os ostringstream
#define f first
#define s second
#define N 100009
using namespace std;
typedef long long LL;
char s[N];


/** FAST I/O
*/
#define MAXX 1000000
char *ipos, *opos, InpFile[MAXX]; //OutFile[MAXX], DIP[30];

inline int input_int(int flag = 0){
while(*ipos <= 32) ++ipos;
if ( flag ) return (*ipos++ - '0');
int x = 0, neg = 0; char c;
while( true ) {
c = *ipos++; if(c == '-') neg = 1;
else{
if(c <= 32) return neg ? -x : x;
x = (x << 1) + (x << 3) + c - '0';
}
}
}

inline LL input_LL(int flag = 0){
while(*ipos <= 32) ++ipos;
if ( flag ) return (*ipos++ - '0');
LL x = 0, neg = 0; char c;
while( true ) {
c = *ipos++; if(c == '-') neg = 1;
else{
if(c <= 32) return neg ? -x : x;
x = (x << 1) + (x << 3) + c - '0';
}
}
}

inline void input_st(char *s){
while(*ipos <= 32) ++ipos;
int pos = 0;char c;
while( true ) {
c = *ipos++;
if(c <= 32) {s[pos] = '\0'; break;}
else s[pos++] = c;
}
}
/*
inline void output(int x){
int y;
int dig = 0;
while(x || !dig) {y = x / 10; DIP[dig++] = x - ((y << 3) + (y << 1)) + '0'; x = y;}
while(dig--) *opos++ = DIP[dig];
} */
inline void InitFASTIO(){
ipos = InpFile; //opos = OutFile;
fread(InpFile, MAXX, 1, stdin);
}
/*inline void FlushFASTIO(){
fwrite(OutFile, opos - OutFile, 1, stdout);
}*/

/**End of FAST I/O
*/



int strlen(char *s)
{
  int i=0,c=0;
  while(s[i++])
  c++;
  return c;
}

void find_palindrom()
{
   int i,j,k,l=0,r=0,len=strlen(s);
   vector<int> d1(len,1),d2(len,1);
   d1[0]=1;
   for(i=1;i<len;i++)
   {
      if(i<=r) d1[i]=min(d1[l+r-i],r-i);
      while(i+d1[i]<len&&i-d1[i]>=0&&s[i-d1[i]]==s[i+d1[i]]) d1[i]++;
      if((i+d1[i]-1)>r)
      {
         l=i-d1[i]+1;r=i+d1[i]-1;
       }
    }

   for(i=1,l=0,r=0;i<len;i++)
   {
       if(i<=r)d2[i]=min(d2[l+r-i+1],r-i+1);
       while(i-d2[i]>=0&&i+d2[i]-1<len&&s[i-d2[i]]==s[i+d2[i]-1]) d2[i]++;
       if(i+d2[i]-1>r)
       {
          l=i-d2[i]+1;r=i+d2[i]-2;
        }
    }

    k=-1;
    int f=-1;j=-1;
    for(i=0;i<len;i++)
    {
        if(i!=len-1&&d1[i]+i==len&&d1[i]>k)
        {
            k=d1[i];
            j=i;f=0;
        }
        if(i!=len-1&&d2[i]+i-1==len&&d2[i]>k) {
            k=d2[i];
            j=i;f=1;
        }
      }
   //   printf("\n***print the maximum palindrom.  %d %d %d***\n",j,k,f);
   if(j!=-1){
        if(f==0)
    {
       f=j-k+1;
    //   printf("odd palindrom:%s\n",(s+f));
    }
    else
    {
        f=j-k+1;
       // printf("even npalindrom:%s\n",s+f);
        //printf("even");
    }
    printf("%s",s);
    for(i=f-1;i>=0;i--)
    printf("%c",s[i]);
    printf("\n");
   }
   else
   {
      printf("%s",s);
      for(i=len-1;i>=0;i--)
      printf("%c",s[i]);
      printf("\n");
    }
}

int main()
{
    //freopen("input.txt","rt",stdin);
   // freopen("output.txt","wt",stdout);

   int i,j,k,t;
   InitFASTIO();
   while(1)
   {
       input_st(s);
       if(s[0]=='-')break;
       find_palindrom();
      //printf("%s\n",s);
   }
   return 0;
}
