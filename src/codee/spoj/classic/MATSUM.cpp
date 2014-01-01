/**
http://www.spoj.com/problems/MATSUM/
*/
/**
INPUT:
1
4
SET 0 0 1
SUM 0 0 3 3
SET 2 2 12
SUM 2 2 2 2
SUM 2 2 3 3
SUM 0 0 2 2
END

OUTPUT:
1
12
12
13
*/
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <cstring>
using namespace  std;
#define N 1030
int a[N][N];
char s[4];

//Update and read opertaion for 2D-BIT.
void update(int x,int y,int n,int val)
{
   while(x<=n)
   {
      int y1=y;
	  while(y1<=n)
	  {
	    a[x][y1]+=val;
		y1+=y1&(-y1);
	  }
	  x+=x&(-x);
   }
}
int read(int x,int y,int n)
{
   int sum=0;
   while(x>0)
   {
     int y1=y;
	 while(y1>0)
	 {
		sum+=a[x][y1];
		y1-=y1&(-y1);
	 }
	 x+=x&(-x);
   }
   return sum;
}


void driver()
{
	printf("\ndriver of matsum is running..\n");
	int i,j,k,n,t,r1,r2,c1,c2;
    scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		while(1){
		for(i=1;i<=n;i++)
		{
		  for(j=1;j<=n;j++)
			  a[i][j]=0;
		}
		scanf("%s",s);
		if(s[0]=='S'&&s[1]=='E')
		{
		
		}
		else if(s[0]=='S'&&s[1]=='U')
		{
		
		}
		else
		{
			break;	
		}
	  }
	}
}
