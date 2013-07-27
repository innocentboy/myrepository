#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#define N 1000
#define M 256
using namespace std;
char s[N],len;
int p[N],c[N],dp[M];
int cnt=0;
/*
this function constructs the suffix array of the the string.
this function creates the SUFFIX ARRAY OF STRING in logn(nlogn) complexity.
start.
*/
inline bool comp(int a,int b)
{
   int i,j,k,l;
   k=((cnt+a)<len)?c[a+cnt]:-1;
   l=((cnt+b)<len)?c[b+cnt]:-1;
   if(c[a]!=c[b]) {

       return c[a]<c[b]?true:false;
   }
   else
   {
        return k<l?true:false;
     //return (c[a+cnt])<(c[b+cnt])?true:false;
    }
}

void suffix_array_Nlog2N()
{
   int i,j,k,classes=1,c1[N],no_of_different_str=0;
   for(i=0;i<len;i++)
   dp[s[i]-'a']++;
   for(i=1;i<26;i++)
   dp[i]=dp[i]+dp[i-1];
   for(i=0;i<len;i++)
   {
       p[--dp[s[i]-'a']]=i;
       }
  for(i=1;i<len;i++)
  {
      if(s[p[i-1]]!=s[p[i]]) classes++;
      c[p[i]]=classes-1;
    }
    no_of_different_str+=classes;

   for(cnt=1;(1<<(cnt-1))<=len;cnt++)
   {
       classes=1;
       sort(p,p+len,comp);
     //  c1[p[0]]=c[p[0]];
      c1[p[0]]=0;
       for(i=1;i<len;i++)
       {
          if(c[p[i]]==c[p[i-1]]&&c[p[i]+cnt]==c[p[i-1]+cnt])
          c1[p[i]]=classes-1;
          else
          {
              classes++;
              c1[p[i]]=classes-1;
              //printf(" %d %d %d     ",i,c1[p[i]],classes);
            }
        }
      //  printf("%d  ",classes);
        for(i=0;i<len;i++)
        c[i]=c1[i];
      /*  printf("\nc and p after each step\n");
        for(i=0;i<len;i++)
        printf("%d ",c[i]); printf("\n");
        for(i=0;i<len;i++)
        printf("%d ",p[i]);*/
      no_of_different_str+=classes;
    }
    printf("\n");
    for(i=0;i<len;i++)
    printf("%s\n",s+p[i]);
   // printf("\n****** different no of string *********:%d\n",no_of_different_str);
}
/*
end of the function.
*/


/*
this function creates the SUFFIX ARRAY OF STRING in nlogn complexity.
start of the function
*/
void suffix_array_NlogN()
{
   int i,j,k,classes=1,cn[N],pn[N],n=len;
   int no_of_distinct_str=0;
   for(i=0;i<len;i++)
   dp[s[i]]++;
   for(i=1;i<M;i++)
   dp[i]=dp[i]+dp[i-1];
   for(i=0;i<len;i++)
   {
       p[--dp[s[i]]]=i;
       }
  for(i=1;i<len;i++)
  {
      if(s[p[i-1]]!=s[p[i]]) classes++;
      c[p[i]]=classes-1;
    }
    no_of_distinct_str+=classes;
 /*  for(i=0;i<len;i++)
   printf("%d ",c[i]);
   printf("\n");
   for(i=0;i<len;i++)
   printf("%d ",p[i]);*/

   for ( int h = 0 ; ( 1 << h ) < n ; ++ h )
   {

    for(i=0;i<n;i++)
    {
          pn[i]=p[i]-(1<<h);
          if(pn[i]<0) pn[i]+=n;
        }
	printf("\n*****\n");
	for(i=0;i<n;i++)
	printf("%d  ",c[i]);printf("\n");
	for(i=0;i<n;i++)
	printf("%d  ",p[i]);printf("\n");
	for(i=0;i<n;i++)
	printf("%d  ",pn[i]);
	memset (dp,0 , (classes+1) * sizeof ( int ) ) ;
	for(i=0;i<n;i++)
	{
	      ++dp[c[i]];
	    }
	for(i=1;i<classes;i++)
	dp[i]+=dp[i-1];
	for(i=n-1;i>=0;i--)
	{
	    p[--dp[c[pn[i]]]]=pn[i];
	    }
	cn[p[0]]=0;
	classes = 1 ;
	for ( int i = 1 ; i < n ; ++ i ) {
		int mid1 = ( p [ i ] + ( 1 << h ) ) % n,  mid2 = ( p [ i - 1 ] + ( 1 << h ) ) % n ;
		if (c[p[i]]!=c[p[i-1]]||c[mid1]!=c[mid2])
			++ classes ;
		cn [ p [ i ] ] = classes - 1 ;
	}
	memcpy ( c, cn, n * sizeof ( int ) ) ;
    no_of_distinct_str+=classes;
   }

    printf("\n");
    for(i=0;i<len;i++)
    printf("%s\n",s+p[i]);
    //printf("\n******* no of distinct substring ***** :%d\n",no_of_distinct_str);
}

/*
end of the function
*/


/*
start of the main function.
*/
int main()
{
   int i,j,k,t,l;
 //  printf("%d",'$');
   scanf("%s",s);
   len=strlen(s);
  /* s[len]='$';
     s[len+1]='\0';
    len++;
    suffix_array_NlogN();*/
   suffix_array_Nlog2N();
   return 0;
}
