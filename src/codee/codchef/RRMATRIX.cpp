/**
http://www.codechef.com/problems/RRMATRIX
*/
/**
	EXPLANATION:
					FOR (I,J)th ENTRY OF MATRIX:-
					A(i,j)= I*M+J+1;
					B(i,j)=J*N +I+1;
					SO, FOR BOTH ENTRIES TO BE EQUAL..
					A(I,J)=B(I,J)
					I*M+J+1=J*N +I+1
				OR, I/J=(N-1)/M-1=(P*G)/(Q*G)   WHERE-:G=GCD(N-1,M-1)
				IF, I/J=P/Q=L;
				THEN I=L*P AND J=L*Q
				SO nO OF SUCH ENTRIES IN THE MATRIX :
							(I,J)=> (L*P,L*Q)   WHERE 0<=L<=G  (BY ALLPLYING THE VALUE OF G IN THIS EQUACATION WE COULD GET THIS 
							VALUE EASILY.)
				SO, NO OF SOLUTION WILL BE (G+1).
*/

/**
Input:
1
4 5

Output: 2 
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
#define N 1000000005

int gcd(int a,int b)
{
	if(a<b)
		a^=b^=a^=b;
	if(b==0) return a;
	return gcd(b,a%b);
}

//int main()
void driver()
{
	int i,j,k,t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		i=gcd(n-1,m-1);
		printf("%d\n",i+1);
	}

	//return 0;
}
