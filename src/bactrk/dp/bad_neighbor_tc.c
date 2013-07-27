/*
The old song declares "Go ahead and hate your neighbor", and the residents of Onetinville have taken those words to heart. Every resident hates his next-door neighbors on both sides. Nobody is willing to live farther away from the town's well than his neighbors, so the town has been arranged in a big circle around the well. Unfortunately, the town's well is in disrepair and needs to be restored. You have been hired to collect donations for the Save Our Well fund.

Each of the town's residents is willing to donate a certain amount, as specified in the int[] donations, which is listed in clockwise order around the well. However, nobody is willing to contribute to a fund to which his neighbor has also contributed. Next-door neighbors are always listed consecutively in donations, except that the first and last entries in donations are also for next-door neighbors. You must calculate and return the maximum amount of donations that can be collected. 

EXAMPLE: { 10, 3, 2, 5, 7, 8 }

Returns: 19
*/
#include<stdio.h>
#define N 100
int bad[N];
int a[2][N];
int len=0;
int max(int a,int b)
{
  return a>b?a:b;    
}
int maxx(int index,int bol)
{
    int i,j,k;
    if(index==len)return 0;
    if(index==len-1&&bol)return 0;
    if(index==len-1)return bad[index];
    if(a[bol][index]!=-1)return a[bol][index];
    return a[bol][index]=max(maxx(index+1,bol),maxx(index+2,bol)+bad[index]);
}
int main()
{
   int i,j,k,t,n,max_sum;
   printf("enter the value of no of elements in the array\n");
   scanf("%d",&n);len=n;printf("enter the values\n");
   for(i=0;i<n;i++)scanf("%d",&bad[i]);
   for(i=0;i<n;i++){a[0][i]=a[1][i]=-1;}
   max_sum=max(bad[0]+maxx(2,1),maxx(1,0));
   printf("value of max sum:%d",max_sum); 
   getch(); 
}

