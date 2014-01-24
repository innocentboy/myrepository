/**
http://www.codechef.com/problems/GERALD04
*/

/**
INPUT:
3
10:00
09:00
10
10:00
09:00
30
10:00
09:00
60


OUTPUT:
70.0 60.0
90.0 60.0
120.0 90.0

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
#define N 1000
char s[10];


int getTime(int hh,int mm)
{
	return hh*60+mm;
}

void driver()
{
	//printf("\ndriver for geral004 is running..\n");

	int i,j,k,test,d;
	float ans1,ans2;
	int t1,t2;
	scanf("%d",&test);
	while(test--)
	{
		//for t1..
		scanf("%d:%d",&i,&j);
		t1=getTime(i,j);
		//for t2..
		fscanf(stdin,"%d:%d",&i,&j);
		t2=getTime(i,j);
		scanf("%d",&d);
		//for first case..
		ans1=(t1-t2)+d;
		//for second case..
		if(2*d<=(t1-t2))
			ans2=(t1-t2);
		else
			ans2=(t1-t2+2*d)/2.0;
		printf("%.1f %.1f\n",ans1,ans2);
	}

	//return 0;

}
