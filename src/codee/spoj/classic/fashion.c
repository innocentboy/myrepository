#include<stdio.h>
#define N 1000
int m[N];
int w[N];
int partition(int a[],int p,int r)
{
    int x=a[r],i,j,temp;
    i=p-1;
    j=p;
    for(j=p;j<r;j++)
    {
       if(a[j]<x)
       {
          i=i+1;
          temp=a[i];
          a[i]=a[j];
          a[j]=temp;          
       }                
    }
    a[r]=a[i+1];
    a[i+1]=x;
    return i+1;    
}
void quick(int a[],int p,int r)
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
   int i=0,j,k,t,ar,hr,rate,sum=0,no;
   scanf("%d",&t);no=t;
   while(t-->0)
   {
       scanf("%d",&no);k=no;i=0;
       while(no-->0)
       { 
          scanf("%d",&rate);
          m[i++]=rate;      
       }i=0;no=k;
       while(no-->0)
       { 
          scanf("%d",&rate);
          w[i++]=rate;      
       }
    quick(m,0,k-1);quick(w,0,k-1);   
    sum=0;
    for(i=0;i<k;i++)
    {
      sum+=m[i]*w[i];
    }printf("%d\n",sum);
  
  } 
   getch(); 
   return 0;    
}


