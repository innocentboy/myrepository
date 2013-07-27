#include<stdio.h>
#define INF -99999999
#define N 100005
int arr[N];
struct segtree
{
  int sum;
  int tol;     
  int left_sum;
  int right_sum;
}M[4*N];
int max(int a,int b)
{
  return (a>b?a:b);    
}
struct segtree combine(struct segtree a,struct segtree b)
{
       struct segtree c;
       if(a.sum==INF)return b;
       else if(b.sum==INF)return a;
       else
       {
           c.sum=0; 
           c.sum=max(max(a.sum,b.sum),a.right_sum+b.left_sum);
           c.tol=a.tol+b.tol;
           c.left_sum=max(a.left_sum,a.tol+b.left_sum);
           c.right_sum=max(b.right_sum,a.right_sum+b.tol);
           return c;
       }
}

void initialize(int node, int b, int e)
{
      if (b == e)
      {
           M[node].sum=M[node].right_sum=M[node].left_sum=M[node].tol=arr[b];
      }  
      else
       {
          initialize(node<<1,b,(b+e)>>1);
          initialize((node<<1)+1,((b+e)>>1)+1,e);
          M[node]=combine(M[node<<1],M[(node<<1)+1]);
        }    
}

struct segtree query(int node,int b,int e,int i,int j)
{
      struct segtree c; 
      if (i > e || j < b)
      {
          c.sum=INF; 
          return c;
      }
      if (b >= i && e <= j)
      return M[node];
      return combine(query(node<<1, b, (b + e)>>1,i,j),query((node<<1)+ 1, ((b + e)>>1) + 1, e,i, j));
}

struct segtree modify(int node,int b,int e,int i,int j)
{
      struct segtree c,x,y; 
      if (i > e||i< b)
      {
          return M[node];
      }
      if (b==i&&e==i)
      {
        M[node].sum=M[node].right_sum=M[node].left_sum=M[node].tol=j;    
        return M[node];
      }
      x=modify(node<<1, b, (b + e)>>1,i,j);y=modify((node<<1)+ 1, ((b + e)>>1) + 1, e,i, j);
      M[node]=combine(x,y);
      return M[node];
}

int main()
{
    
       int i,j,k=0,t,n,x,y,m;   
       scanf("%d",&n);                    
       for(i=1;i<=n;i++)
       scanf("%d",&arr[i]);
       initialize(1,1,n);
       scanf("%d",&m);  
       while(m--)
       {
         scanf("%d%d%d",&i,&x,&y);
         if(i==1)          
         printf("%d\n",query(1,1,n,x,y).sum);
         else
         modify(1,1,n,x,y);        
       }             
       getch();
       return 0;    
}



