#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#define N 1000
using namespace std;
char s[N];
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

    printf("\nprint d1 \n");
    for(i=0;i<len;i++)
    printf("%d",d1[i]);

     printf("\nprint d2 \n");
    for(i=0;i<len;i++)
    printf("%d",d2[i]);k=-1;
    int f=-1;
    for(i=0;i<len;i++)
    {
        if(d1[i]>k) {k=d1[i];j=i;f=0;}
        if(d2[i]>k) {k=d2[i];j=i;f=1;}
      }
      printf("\n***print the maximum palindrom.  %d %d %d***\n",j,k,f);
    if(f==0)
    {
       f=j-k+1;
       printf("odd palindrom:%s",(s+f));
    }
    else
    {
        f=j-k+1;
        printf("even npalindrom:%s",s+f);
        //printf("even");
    }
}

int main()
{

   int i,j,k;
   scanf("%s",s);
   find_palindrom();
   return 0;
}
