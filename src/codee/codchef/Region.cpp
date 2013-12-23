/**
PROBLEM LINK:http://www.codechef.com/DEC13/problems/REIGN
*/
/**
Input:
3
5 3
-1 1 2 3 -1
8 3
5 5 -1 -2 3 -1 2 -2
6 0
5 -1 5 0 -1 9

OUTPUT:
-2
12
18
*/

#include "stdafx.h"
#include <iostream>
#include <cstdio>

#ifndef REGION_H
#define REGION_H

#define N 100
int a[N];
int dpl[N];
int dpr[N];

int solve(int a[],int n,int k)
{
	int i,j,maxx,cur,ans;
	for(i=0;i<n;i++){
		dpl[i]=0;
		dpr[i]=0;
	}
	maxx=a[0];
	cur=0;
	dpl[0]=maxx;
	for(i=0;i<n;i++)
	{
		cur+=a[i];
		if(cur>maxx)
			maxx=cur;
		dpl[i]=maxx;
		if(cur<0)
			cur=0;
	}
	maxx=a[n-1];
	cur=0;
	dpr[n-1]=maxx;
	for(i=n-2;i>=0;i--)
	{
		cur+=a[i];
		if(cur>maxx)
			maxx=cur;
		dpr[i]=maxx;
		if(cur<0)
			cur=0;
	}
	ans=dpl[n-k-2]+dpr[n-1];
	for(i=n-k-3;i>=0;i--)
	{
		if(dpl[i]+dpr[i+k+1]>ans)
			ans=dpl[i]+dpr[i+k+1];
	}
	return ans;
}

void driver()
{
	printf("\nMethod of region is called..\n");
	int i,j,k,t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		n=solve(a,n,k);
		printf("\nSolu:%d\n",n);
	}
}

#endif
