/**
  this file implement the structure of binary index tree.
  Q:Statement:  There is an array of n cards. Each card is putted face down on table. You have two queries: 
  1. T i j (turn cards from index i to index j, include i-th and j-th card - card which was face down will be face up;   
  card which was face up will be face down)  
  2. Q i (answer 0 if i-th card is face down else answer 1)
*/

/**
INPUT:
1 5
8
0 2 5
0 1 4
1 2 2
1 5 5
1 4 4
0 1 5
1 4 4
1 5 5


OUTPUT:
FACEDOWN
FACEUP
FACEDOWN
FACEUP
FACEDOWN
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 1000

using namespace std;

int card[N],n;

/**
Here the code stuff related to BIT is given..
*/
int read(int idx)
{
	int sum=0;
	while(idx>0)
	{
		sum+=card[idx];
		idx-=idx&(-idx);
	}
	return sum;
}
void update(int idx,int maxVal,int val)
{
	while(idx<=maxVal)
	{
		card[idx]+=val;
		idx+=idx&(-idx);
	}
}

int query(int idx)
{
	int sum=0,z;
	sum=card[idx];
	z=idx-(idx&(-idx));
	idx--;
	while(idx!=z)
	{
		sum-=card[idx];
		idx-=idx&(-idx);
	}
	return sum;
}


void driver()
{
	int i,j,k,t,q,n;
	scanf("%d%d",&t,&n);
	while(t--)
	{
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d%d",&k,&i,&j);
			if(k==1)
			{
			  int k=read(i);
			  if(k&1)
				  printf("\n####Card is face UP\n");
			  else
				  printf("\n****Card is face down..\n");
			}
			else
			{
				update(i,n,1);
				update(j+1,n,-1);
			}
		}
	}
}
