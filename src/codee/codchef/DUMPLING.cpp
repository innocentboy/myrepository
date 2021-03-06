/**
http://www.codechef.com/problems/DUMPLING
*/
/**
NOTE:
	SINCE FOR PO OR SHIFU IT'S POSSIBLE TO REACH OUT AT DISTANCE K , IF THE GCD OF A ,B OR C,D IS LESS THAN K.
	SECOND: AT WHAT PLACES SHOULD THAT DUMPLING BE PLACED SO THAT , IT COULD BE REACHABLE BE BOTH OF THEM EXACTLY
			THERE, AT DISTANCE WHICH IS RECAHBLE AND LESS THEN OR EQUAL TO K.
			SO, IT'S A SIMPLE PROBLEM OF FINDING SMALL INTEGER WHERE TWO  WILL INTERSECT EACH OTHER(lcm).
			SO, WE NEED TO FIND THE LCM OF BOTH GCD , THAT IS DISTANCE THAT IS REACHED BY THEM INDIVIDUALLY.
			AFTER GETTING THE LCM , IT WILL BE THE PLACVE WHICH WILL BE RECHABLE BY BOTH OF THEM.
			SO, FOR FINDING THE NO OF POSSIBLE POSITION WE JUST NEED TO DIVIDE THE K BY LCM 
			I.E. ANS=(K/lcm).
			IMPORTANT: WE HAVE COUUNTED ONLY THE ANSWERS FOR THE POSITIVE (RIGHT SIDE) ON nO. LINE.
						WE ALSO NEED TO CALULATE THE ANSWERS FOR THE NEGATIVE SIDE(LEFT SIDE) ON oN. LINE.
						WE ALSO NEED TO CONSIDER THE STARTING POINT OR THE CENTER POINT OF BOTH PO AND SHIFU.
			HENCE OUR FINAL ANSWER WILL BE.
					ANS=2*(K/lcm)+1;
						DUE TO SUMMETRY WE JUST ADDED THE K TWICE (2) FOR BOTH RIGHT AND LEFT SIDE OF nO. LINE.

			IMPORTANT: TO AVOID THE OVERLOAD I HAVE CALCULATE THE ANSWER BY BREAKING THE EXPRESSION.
*/

/**
Input:
3
2 4 3 6 7
1 2 4 5 1
10 12 3 9 16

Output:
3
3
5
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
#define N 1005
#define M 23102009

long long gcd(long long a,long long b)
{
	if(b==0) return a;
	if(a<b)
		a^=b^=a^=b;
	return gcd(b,a%b);
}

//int main()
void driver()
{
	long long a,b,c,d,k;
	int i,j,t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&k);

		long long x,y,l,temp;
		x=gcd(a,b);
		y=gcd(c,d);

		//Now calculate the lcm.
		l=gcd(x,y);

		temp=x/l;
		
		temp=k/temp;

		l=temp/y;

		l=2*l+1;

		printf("%lld\n",l);
	}

	//return 0;
}
