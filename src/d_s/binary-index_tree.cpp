/*
  this file implement the structure of binary index tree.
  Q:Statement:
  There is an array of n cards. Each card is putted face down on table. You have two queries:
  1. T i j (turn cards from index i to index j, include i-th and j-th card - card which was face down will be face up;
     card which was face up will be face down)
  2. Q i (answer 0 if i-th card is face down else answer 1)
*/


#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#define N 1000
using namespace std;
int card[N],n;


/*
this function reads the cumulative frequency stored upto that index.
*/
int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum += card[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val){
	while (idx <=n){
		card[idx] += val;
		idx += (idx & -idx);
	}
}


/*
this function reads the individual frequency stored at that index.
*/
int  query(int idx){
int sum =card[idx];
if (idx>0){
	int z=idx-(idx&-idx);
	idx--;
	while (idx != z){
		sum-=card[idx];
		idx-=(idx & -idx);
	}
}
return sum;
}

/*
start of main function
*/
int main()
{
   int i,j,k,t,q;
   scanf("%d",&n);
   scanf("%d",&t);
   while(t--)
   {
        scanf("%d%d%d",&q,&i,&j);
        if(q==1)
        {
          update(i,1);
          update(j+1,-1);printf("\n");
        }
        else
        {
           if(read(i)%2==0)printf("\ncard is face UP\n");
           else  printf("\ncard is face DOWN\n");

        }

    }
     return 0;
}
