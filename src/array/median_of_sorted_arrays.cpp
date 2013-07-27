/***

*/
#include<cstdio>
#include<algorithm>
#include<iostream>
#define N 10000
using namespace std;

int median_of_sorted_arrays(int a1[],int a2[],int n1,int n2)
{


}

int main()
{
  int i,j,k,n1,n2,a1[N],a2[N],median;
  scanf("%d%d",&n1,&n2);
  for(i=0;i<n1;i++) scanf("%d",&a1[i]);
  for(i=0;i<n2;i++) scanf("%d",&a2[i]);
  median=median_of_sorted_arrays(a1,a2,n1,n2);
  printf("\nMedian :%d\n",median);
  return 0;
}
