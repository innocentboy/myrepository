#include<stdio.h>
#define INF -999999
#define N 100005
int arr[N];
struct segtree
{
  int fre;     
  int left_elm;
  int right_elm;
  int left_fre;
  int right_fre;
}M[400099];
void initialize(int node, int b, int e)
{
      if (b == e)
      {
           M[node].fre=M[node].left_fre=M[node].right_fre=1;
           M[node].left_elm=M[node].right_elm=arr[b];
      }  
      else
       {
          initialize(2*node,b,(b+e)/2);
          initialize(2*node+1,(b+e)/2+1,e);
          M[node].left_elm=M[2*node].left_elm;
          M[node].right_elm=M[2*node+1].right_elm; 
          M[node].left_fre=M[2*node].left_fre;
          M[node].right_fre=M[2*node+1].right_fre; 
          M[node].fre=0;
          if((M[2*node].right_elm!=M[2*node+1].left_elm))
          {
             M[node].fre=(M[2*node].fre>M[2*node+1].fre)?(M[2*node].fre):(M[2*node+1].fre);
          }
           else 
           {
               if((M[2*node].left_elm==M[2*node].right_elm))
                {
                 M[node].left_fre=((M[2*node].right_fre)+M[2*node+1].left_fre);
                }
                if((M[2*node+1].left_elm==M[2*node+1].right_elm))
                {
                  M[node].right_fre=((M[2*node].right_fre)+M[2*node+1].left_fre);   
                }    
               M[node].fre=(M[2*node].right_fre)+M[2*node+1].left_fre;
               if(M[2*node].fre>M[node].fre)M[node].fre=M[2*node].fre;
               if(M[2*node+1].fre>M[node].fre)M[node].fre=M[2*node+1].fre; 
           }   
        }    
}
struct segtree combine(struct segtree a,struct segtree b)
{
       struct segtree c;
       if(a.left_fre==INF)return b;
       else if(b.left_fre==INF)return a;
       else
       {
           c.fre=0;
           c.left_elm=a.left_elm;
           c.right_elm=b.right_elm;  
           c.left_fre=a.left_fre;
           c.right_fre=b.right_fre;  
           if((a.right_elm!=b.left_elm))
             c.fre=((a.fre)>(b.fre))?a.fre:b.fre;
           else
           {
                if((a.left_elm==a.right_elm))
                {
                 c.left_fre=((a.right_fre)+b.left_fre);
                 
                }
                if((b.left_elm==b.right_elm))
                {
                  c.right_fre=((a.right_fre)+b.left_fre);   
                } 
             c.fre=a.right_fre+b.left_fre;
             if(a.fre>c.fre)c.fre=a.fre;
             if(b.fre>c.fre)c.fre=b.fre; 
              
           }  
           return c;
       }
}
struct segtree query(int node,int b,int e,int i,int j)
{
      struct segtree c; 
      if (i > e || j < b)
      {
          c.left_fre=INF; 
          return c;
      }
      if (b >= i && e <= j)
          return M[node];
      return combine(query(node<<1, b, (b + e)>>1,i,j),query((node<<1)+ 1, ((b + e)>>1) + 1, e,i, j));
}
int main()
{
    
    int i,j,k=0,t,n,x,y,m;
    while(scanf("%d",&n)&&n!=0)
    {
       scanf("%d",&m);                        
       for(i=1;i<=n;i++)
       scanf("%d",&arr[i]);
       initialize(1,1,n);
       while(m--)
       {
         scanf("%d%d",&x,&y);          
         printf("%d\n",query(1,1,n,x,y).fre);        
       }             
    }
    getch();
    return 0;    
}


