#include<stdio.h>
#define N 1000009
#define max(i,j) (i>j)?i:j
int arr[N];
int M[4*N];
void initialize(int node, int b, int e)
{
      if (b == e)
      {
           M[node]=arr[b];
      }  
      else
      {
          initialize(node<<1,b,(b+e)>>1);
          initialize((node<<1)+1,((b+e)>>1)+1,e);
          M[node]=(M[node<<1]>M[(node<<1)+1])?M[node<<1]:M[(node<<1)+1];
      }    
}

int query(int node,int b,int e,int i,int j)
{
      int a,c;
      if (i > e || j < b)
      return -1;
      if (b >= i && e <= j)
      return M[node];
      a=query(node<<1, b, (b + e)>>1,i,j);c=query((node<<1)+ 1, ((b + e)>>1) + 1, e,i, j);
      return a>c?a:c;
}
int main()
{
    
    int i,j,k=0,t,n,x,y,m;
   // while(scanf("%d",&n)&&n!=0)
   // { 
       scanf("%d",&n);                                             
       for(i=1;i<=n;i++)
       scanf("%d",&arr[i]);
       initialize(1,1,n);
       scanf("%d",&k);
       for(i=1;i<=n-k+1;i++)   
         printf("%d ",query(1,1,n,i,i+k-1));        
       printf("\n");               
   // }
    getch();
    return 0;    
}


