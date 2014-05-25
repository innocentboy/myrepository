#include<cstdio>
#include <iostream>
#include<algorithm>
#include<string>
#include<map>
#include <fstream>
#include<vector>
#define N 1000
#define M 256
using namespace std;
char s[N];
int len;
int p[N],c[N],dp[M];
int cnt=0;

void writeCharcter();

/**
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
    writeCharcter();
   /** for(i=0;i<len;i++)
    printf("\nindex:%d %s\n",p[i],s+p[i]);
    */
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

/**
end of the function
*/

int compareStr(char *src,char *pattern)
{
    int i=0,j=0,k;
    while(src[i]!='\0'&&pattern[j]!='\0')
    {
      if(src[i]==pattern[j]);
      else if(src[i]<pattern[j])
      return 1;
      else return -1;
      i++;j++;
    }
    if((src[i]!='\0'||src[i]=='\0')&&pattern[j]=='\0')
     return 0;
    else if(src[i]=='\0'&&pattern[j]!='\0')
      return 1;
    else
      return -1;
}


/**
string serach(pattern serach) in the given document( i.e. string taken as the array of chars..)
*/
int pattern_search(char * pattern)
{
   int start,end,i,m,k;
   printf("\n len:%d",len);
   start=0;end=len-1;
   m=start+(end-start)>>1;
   while(start<end)
   {
        m=(end+start)/2;
        k=compareStr(s+p[m],pattern);
      /*  if(k==0)
        {
            printf("\nbreaking condition..m:%d\n",m);
            break;
        }
        */
        if(k>0)
        {
           start=m+1;
        }
        else
           end=m;
        printf("\ninside the loop :%d %d %d\n",start,m,end);
    }
    if(start>=0||end<len)
    {
         printf("\nprint the all occurences of the pattern..\n");
         for(i=(start);i<=end;i++)
         {
            // printf("\nsrc:%s pattern:%s\n",s+p[i],pattern);
            k=compareStr(s+p[i],pattern);
            if(k==0)
            {
               printf("\npattern ocurres at index:%d",p[i]);
            }
            else{

              //  printf("\nk:%d\n",k);
                break;
            }
          }

    }
    else
    {
      printf("\nNo text found..\n");
    }

}

/**
Writing characters to file..
*/
void writeCharcter()
{
     int i,j;
     ofstream outputFile;
     outputFile.open("output.txt");
     char *str;
     for(i=0;i<len;i++)
     {
        str=s+p[i];
        j=0;
        outputFile<<i;
        while(str[j]!='\0')
        {
           outputFile<<str[j];
           j++;
        }
        outputFile<<endl;
      }
     outputFile.close();
}


/**
Reading the characters from the file and storing it in the array..
*/
void raedCharacterFromDocument()
{
     ifstream myReadFile;
     myReadFile.open("input.txt");
     int i=0;
     if (myReadFile.is_open()) {
       while (myReadFile.good())          // loop while extraction from file is possible
      {
          char c = myReadFile.get();       // get character from file
       //   if (myReadFile.good())
          s[i]=c;
          i++;
      }
      myReadFile.close();
      s[i]='\0';
      len=strlen(s);
      printf("\n strlen:%d\n",len);
     }
     else
     {
         printf("\n not openned properly....\n");
     }
}



/**
start of the main function.
*/
int main()
{
   int i,j,k,t,l;
   char pattern[100];

   //gets(s);
   raedCharacterFromDocument();
   len=strlen(s);

    /**
      suffix_array_NlogN();
    */
    suffix_array_Nlog2N();

   /**while loop that takes the pattern and search
      it in the given document string that is already
      preprocessed and stored in the form of
      Suffix ARRAY data structure.
   */
   char input='y';
   while(input=='y'||input=='Y')
   {
       fflush(stdin);
       printf("\nenter the pattern to be searched\n");
       gets(pattern);
       pattern_search(pattern);
       printf("\nTo continue searching enter 'y'\n");
       scanf("%c",&input);
    }

   return 0;
}
