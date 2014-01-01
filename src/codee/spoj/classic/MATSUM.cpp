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

   /*
   printf("\nPrint the array...\n");
   for(int i=0;i<=n;i++)
   {
	for(int j=0;j<=n;j++)
		printf("%d ",a[i][j]);
	printf("\n");
   }
   */

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
	 x-=x&(-x);
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
		for(i=0;i<=n;i++)
		{
		  for(j=0;j<=n;j++)
			  a[i][j]=0;
		}
		scanf("%s",s);
		if(s[0]=='S'&&s[1]=='E')
		{
			scanf("%d%d%d",&r1,&c1,&k);
			r1++;c1++;
			r2=r1;c2=c1;
		  j=read(r2,c2,n);
		  j+=read(r1-1,c1-1,n);
		  j-=read(r1-1,c2,n);
		  j-=read(r2,c1-1,n);
		  update(r1,c1,n,k-j);
		}
		else if(s[0]=='S'&&s[1]=='U')
		{
		  scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		  r1++;c1++;r2++;c2++;
		  printf("\n%d %d %d %d",r1,c1,r2,c2);	
		  k=read(r2,c2,n);
		  printf("\n%d ",k);
		  k+=read(r1-1,c1-1,n);
		  printf("%d ",k);
		  k-=read(r1-1,c2,n);
		  printf("%d ",k);
		  k-=read(r2,c1-1,n);
		  printf("%d ",k);

		  printf("\nAns:%d\n",k);
		}
		else
		{
			break;	
		}
	  }
	}
}
