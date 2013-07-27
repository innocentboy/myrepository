// finding pivot element..
#include<cstdio>
#define N 100
int a[N];

int pivot(int n)
{
   int i,l,r,m;
   l=0;r=n-1;
   while(l<=r)
   {
      m=(l+r)>>1;

      if(a[l]<=a[m])
      l=m+1;
      else
      r=m-1;
       printf("\n %d",m);
      if(a[m]<a[m-1]&&a[m]<a[m+1])
      {
          printf("\n****pivot : %d***\n",m);
          return m;
       }
   }

}
int main()
{
    int i,j,l,r,n,m,find;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    scanf("%d",&find);
    l=0;r=n-1;
    pivot(n);
    // printf("\npivot:%d\n",pivot(n));
    while(l<=r)
    {
        m=(l+r)>>1;
      //  printf("\n%d %d %d ",l,r,m);
        if(a[m]==find)
        {
            printf("\nelement found at:%d",m);
            break;
        }
        if(a[m]>=a[l])
        {
          if(find>a[m])
          l=m+1;
          else if(find>=a[l])
          r=m-1;
          else
          l=m+1;
        }
        else{
        if(find>a[m]&&find<=a[r])
        l=m+1;
        else
        r=m-1;
        }
       //printf("  after:  %d %d %d",l,r,m);
    }
    return 0;
}



