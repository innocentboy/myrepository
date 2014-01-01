/**
################
Below given link is from the TC recipe wich explains in detail, by using SWEEP LINE  algorithm
we can easily calulate in o(nlogn), insipte of brute force method, which solves it in o(n*n).  
LINK:::http://apps.topcoder.com/forums/;jsessionid=65F147BD295F0AEADFCC23AF4C727C6E?module=Thread&threadID=684537
&start=0&mc=6#1794942
*/
/**
INPUT:

OUTPUT:

*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#define N 1000
using namespace std;

typedef complex <double>  pnt;

struct x_compare
{
	bool operator()(const pnt& a,const pnt& b) 
	{
		if(a.real()!=b.real())
			return a.real()<b.real();
		else
			return a.img()<b.img();
	}
};
struct y_compare
{
	bool operator()(const pnt& a,const pnt& b) 
	{
		if(a.img()!=b.img())
			return a.img()<b.img();
		else
			return a.real()<b.real();
	}
};

vector<pnt> sx;
set<pnt,y_compare> st;
set<pnt,y_compare>::const_iterator lower,upper;

double closet(const vector<pnt> &s)
{
	sx=s;
	int i,j,k,tail=0,n;
	n=s.size();
	const int huge=999999999;
	double h=huge;

	sort(sx.begin(),sx.end(),x_compare());
	for(i=0;i<n;i++)
	{
		 // erase points whose X value is too small to even consider
		while(sx[i].real()-sx[tail].real()>h)
		{
			st.erase(sx[i]);
			tail++;
		}
		lower=lower_bound(st.begin(),st.end(),pnt(sx[i].real(),s[i].img()-h),y_compare());
		upper=upper_bound(st.begin(),st.end(),pnt(sx[i].real(),s[i].img()+h),y_compare());
		for(;lower!=upper;lower++)
		{
		  h=min(h,abs(sx[i]-*lower));
		}
		st.insert(sx[i]);
	}
	printf("\nSmallest Points pairs are:%f\n",h);
}

void driver()
{
	printf("\nDriver of closest points pair running..\n");

}
