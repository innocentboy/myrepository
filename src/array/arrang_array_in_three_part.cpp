/**
In given array of elements like [a1,a2,a3,..an,b1,b2,b3,..bn,c1,c2,c3,...cn]
Write a program to merge them like [a1,b1,c1,a2,b2,c2,...an,bn,cn].
*/
#include<cstdio>
#include<vector>
#include<algorithm>
#define M 1000

using namespace std;
//int a[N];

int getIndex(int idx, int N) {
return (idx % 3) * N + (idx / 3);
}

void swap(int *x, int *y) {
if (x != y) {
*x ^= *y;
*y ^= *x;
*x ^= *y;
}
}

void orderArray(int a[], int len) {
    int N = len / 3;
    for(int i = 0; i < len; i++) {
    int idx = getIndex(i, N);
    while(idx < i) {
    idx = getIndex(idx, N);
    }
    printf("i: %d; new_idx: %d\n", i, idx);
    swap(a[i], a[idx]);
    }
}

int main () {
//int len = 24;
//int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
    int n,a[M],i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("\nprint the array\n");
    for(i=0;i<n;i++) {
    printf("%d ", a[i]);
    }
    printf("\n");
    orderArray(a,n);
    for( i = 0; i <n; i++) {
    printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

/*void arrange_array(int n)
{
   int ia,ib,ic,i,j,k,iaa,iba,ica;
   ia=0;ib=n/3;ic=ib+ib;
   for(i=0;i<n;i++)
   {


   }
}

int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("\nprint the array before arrangement..\n");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    arrange_array(int n);
    printf("\npritnt the array after arrangement..\n");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}*/
