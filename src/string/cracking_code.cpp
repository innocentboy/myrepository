/*
this file contains code related to strings..
*/
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#define N 10000
using namespace std;

/**
Printing the all interleaving of the string..

*/

void interleaving(char s1[],char s2[],char s3[],int m,int n,int i)
{
   if(m==0&&n==0)
   {
      printf("%s\n",s3);
    }
    else
    {
      if(m>0)
      {
          s3[i]=s1[0];
          interleaving(s1+1,s2,s3,m-1,n,i+1);
       }
       if(n>0)
      {
           s3[i]=s2[0];
           interleaving(s1,s2+1,s3,m,n-1,i+1);

       }
    }
}

bool checkInerleave(char *s1,char *s2,char *s3)
{

        while(*s3!='\0')
        {
          if(*s1==*s3)
          s1++;
          else if(*s2==*s3)
          s2++;
          else return false;
          s3++;
        }
        return true;
}

int main()
{
   char s1[]="ABE";
   char s2[]="CD";
   char s[]="ADCBE";
   char s3[6];
   interleaving(s1,s2,s3,3,2,0);
   if(checkInerleave(s1,s2,s))
   {
      printf("string is interleaving..\n");
    }
    else
    {
      printf("string is not interleaving..\n");
    }

   return 0;
}
