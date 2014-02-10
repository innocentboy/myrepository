/**
http://www.codechef.com/problems/CIEL8STR
*/
/**
NOTE: ONE OF THE FACT THAT 1000 IS MULTIPLE OF 8.
		SO, ANY NUMBER X WOULD BE DIVISIBLE  BY 8 IF:
													X=X'*1000+ (Y):
		SO, NO X WOULD BE DIVISIBLE BY 8, IF Y IS DIVISIBLE BY 8.
		SINCE 1000 IS DIVISIBLE BY 8, THEN WE NEED TO MAKE SURE ONLY ABOUT THE Y PART OF X.

		SO ALGORITHM FOR FINDING THE DIFFERENT SUBSTRINGS OF STRING THAT IS DIVISIBLE BY 8: WOULD BE LIKE-
		1. CALCULATE THE NO OF SINGLE DIGITS THAT ARE DIVISIBLE BY 8.
				i.e. S[DIGIT]%8==0 &&S[DIGIT]!=0 THEN COUNT=COUNT+1;
		2. CALCULATE THE NO OF TWO DIGITS SUBSTRING THAT ARE DIVISIBLE BY 8.
				i.e. (S[DIGIT-1]*10+S[DIGIT])%8 && S[DIGIT-1]!=0 THEN COUNT=COUNT+1;

		3. CALCULATE ALL THE DIGITS HAVING NO OF DIGITS THREE OR MORE THAN WITH THEM:
				(S[DIGIT-2]*100+S[DIGIT-1]*10+S[DIGIT])%8
					COUNT= COUNT+ No. OF NON-DIGITS NUMBER FORM S[1... DIGIT-2].


IMPORTANT: SAME ALGORITHM WILL BE APPLICABLE FOR DIVISIBLE FO 7 ALSO.
*/


/**
Sample Input

5858

Sample Output

2
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include <iostream>
using namespace std;
#define N 10000005

char s[N];

int strlenn(char *ss)
{
	int i=0;
	while(s[i++]);
	return i-1;

}

int main()
{
	int i,j,k,n;
	scanf("%s",s);
	n=strlenn(s);
	long long res=0;

	//calculate answer for the single digit.
	for(i=0;i<n;i++)
	{
		k=s[i]-'0';
		if(k%8==0)
			res++;
	}
	//calculate answer for the double digit.
	for(i=1;i<n;i++)
	{
		k=(s[i-1]-'0')*10+(s[i]-'0');
		if(k%8==0&&s[i-1]!='0')
			res++;
	}

	//calculate for three digits or more.
	int no_of_nonzero=0;
	for(i=2;i<n;i++)
	{
		k=(s[i-2]-'0')*100+(s[i-1]-'0')*10+(s[i]-'0');
		if(s[i-2]!='0') no_of_nonzero++;
		if(k%8==0) res+=no_of_nonzero;
	}
	printf("%lld\n",res);
    return 0;
}
