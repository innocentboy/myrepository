/**
You are given a set S of positive integers. The integers are not necessary distinct.
ForbiddenSum of S equals to the minimal non-negative integer, that can't be returned by 
the algorithm described below:

    Choose a random subset S' of S(it can be empty as well);
    Calculate the sum of all the numbers of S' and assign it to the variable T;
    Return the value of the variable T. 

I.e. if S = {1, 1, 3, 7}, the algorithm can return 0(S' = {}), 1(S' = {1}),
2(S' = {1, 1}), 3(S' = {3}), 4(S' = {1, 3}), 5(S' = {1, 1, 3}), but it can't return 6. 
So, ForbiddenSum of S equals to 6. 
*/
/**
SOL:
	We would sort the array , and we looking for each element of SET(s), that is
	greater than Sum , till that point.
	
*/

/**
INPUT:

4
1 1 3 7

OUTPUT:
6

*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define N 100


void driver()
{
	printf("\nForbidden sum is running..\n");
	int i,j,k,n;
	int a[N];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	//Sort the given set in asending order so, that we could easily find that number.
	sort(a,a+n);

	//Now traverse the each element of Sorted Set(a) 
	//and try to find out that Number for which Sum(s) is 
	//less than that Number. Then return the calculated sum so far.
	int s=0;
	for(i=0;i<n;i++)
	{
		if(a[i]<=s+1)
			s+=a[i];
		else
			break;
	}
	printf("\nAns:%d\n",s+1);
}
