#include<stdio.h>
#define N 300000
struct list{
       int rate;
       int index;
};
struct list a[N];
struct list h[N];
int search(struct list a[],int index,int length)
{
    int find=-1,l,u,mid,i;
    for(i=0;i<length&&find==-1;i++)
    {
        if(a[i].index==index)
        find=i;                           
    }
    return find;
}
int partition(struct list a[],int p,int r)
{
    int x=a[r].rate,i,j,temp;
    i=p-1;
    j=p;
    for(j=p;j<r;j++)
    {
       if(a[j].rate<x)
       {
          i=i+1;
          temp=a[i].rate;
          a[i].rate=a[j].rate;
          a[j].rate=temp;          
       }                
    }
    a[r].rate=a[i+1].rate;
    a[i+1].rate=x;
    return i+1;    
}
void quick(struct list a[],int p,int r)
{
    int q; 
   if(p<=r)
   {
          q=partition(a,p,r);
          quick(a,p,q-1);
          quick(a,q+1,r);   
   }     
}
int main()
{
   int i=0,j,k,t,ar,hr,no;
   scanf("%d",&t);no=t;
   while(t-->0)
   {
       scanf("%d%d",&ar,&hr);
       a[i].index=ar;h[i].rate=hr;
       a[i].index=i;h[i].index=i;;i++;
   }
   quick(a,0,no-1);quick(h,0,no-1);
   for(i=0;i<no;i++)printf("%d ",a[i]);printf("\n");
   for(i=0;i<no;i++)printf("%d ",h[i]);
   for(i=0;i<no;i++)
   {
      ar=search(a,i,no);hr=search(h,i,no);   
      if(ar<hr)k=ar;
      else if(ar>hr)k=ar;
      else k=ar;
      printf("%d\n",k);             
   }
   getch(); 
   return 0;    
}

