/**
http://community.topcoder.com/stat?c=problem_statement&pm=1215&rd=4555
*/
/**
INPUT:
RBR
RBRB
AABBCCDDCCBBAABBCCDD
ABACADA
BECBBDDEEBABDCADEAAEABCACBDBEECDEDEACACCBEDABEDADD

OUTPUT:
2
3
7
4
26
*/
#include <cstdio>	
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#define N 60
using namespace std;
char s[N];

int strlenn(char *s)
{
	int i=0;
	while(s[i++]);
	return i-1;
}

int solve(char *s,int i,int j)
{
	int k,l,m;
	if(i>j)
	{
		if(i==j) return 1;
		else return 0;
	}
	if(s[i]==s[j])
	{
		while(i<=j)
		{
		  if(s[i]!=s[j])
		  {
		    break;
		  }
		  i++;j--;
		}
		l=1+solve(s,i,j);
	}
	else
	{
		  printf("\ninsdide else\n");
          k=i+1;m=j-1;
		  while(k<=j&&s[k]==s[i])k++;
		  while(m>=i&&s[m]==s[j]) m--;
	      l=1+min(solve(s,k,j),solve(s,i,m));
	}
	return l;
}

void driver()
{
	printf("\nstriper painter is running..\n");
	int i,j,k,n;
	scanf("%s",s);
	n=strlenn(s);
	k=solve(s,0,n-1);
	printf("\nAns:%d\n",k);
}
