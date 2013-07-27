/*
this file calculates the counting inversion problem.
Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

Example:
The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
*/

#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#define N 10000
#define MAX 9999
int a[N],temp[N],n;

int merge(int l,int mid,int r)
{
    int i,j,k,t,inv_count=0;
    i=l;j=mid+1;k=l;
    while(i<=mid&&j<=r)
    {
       if(a[i]<=a[j])
       {
          temp[k]=a[i];
          i++;k++;
        }
        else
        {
           temp[k]=a[j];
           k++;j++;
           inv_count+=mid-i+1;
        }
    }
     while (i <=mid)
     temp[k++] = a[i++];
     while (j<=r)
    temp[k++] = a[j++];
    for (i=l;i<=r;i++)
       a[i]=temp[i];
     return inv_count;
}

int inversion_count(int l,int r)
{
    int inversion=0,mid;
    if(l<r){
    mid=(l+r)/2;
    inversion+=inversion_count(l,mid);
  //  printf("\bkfskfsk %d %d %d\n",l,mid,r);
    inversion+=inversion_count(mid+1,r);
   // printf("inside inversion\n");
    inversion+=merge(l,mid,r);
   }
    return inversion;
}

int main()
{

  int i,j,k;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  scanf("%d",&a[i]);
  printf("gkhkjhfskj\n");
  int inversios=inversion_count(1,n);
  printf("\nNo of inversions:%d\n",inversios);
  return 0;
}
