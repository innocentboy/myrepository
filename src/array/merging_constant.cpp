#include<cstdio>
#include<algorithm>
#define N 100
using namespace std;

/*
this function merges two arrays and kept the result into the larger array.
*/
int merge_constant(int a[],int b[],int m,int n)
{
    int i,j,k,t;
    k=m+n-1;
    i=m-1;j=n-1;
    while(i>=0&&j>=0)
    {
      if(a[i]>b[j])
      {
          a[k]=a[i];
          k--;i--;
        }
        else
        {
              a[k]=b[j];
              k--;j--;
            }
    }
    while(j>=0)a[k--]=b[j--];
}


int main()
{

  int a[N],b[N],i,j,m,n;
  scanf("%d%d",&m,&n);
  for(i=0;i<m;i++)scanf("%d",&a[i]);
  for(i=0;i<n;i++) scanf("%d",&b[i]);
  merge_constant(a,b,m,n);
  printf("\nprint the sorted merged array\n");
  for(i=0;i<m+n;i++)
  printf("%d ",a[i]);
  return 0;
}
