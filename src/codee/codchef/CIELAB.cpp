/**
http://www.codechef.com/problems/CIELAB
*/
/**
Sample Input

5858 1234

Sample Output

1624
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
#define M 1000000007

//int main()
void driver()
{
	int i,j,a,b;
	scanf("%d%d",&a,&b);
	if((a-b)%10==9)
		printf("%d\n",a-b-1);
	else 
		printf("%d\n",a-b+1);


	//return 0;
}
