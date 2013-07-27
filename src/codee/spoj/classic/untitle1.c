#include<stdio.h>
#include<math.h>
#define N 100005
int arr[N];
struct segtree
{
  long long sum;       
  struct segtree *left;      
  struct segtree *right;
};
struct segtree *makenode()
{
  struct segtree *p;
  p=(struct segtree *)malloc(sizeof(struct segtree));
  p->left=NULL;
  p->right=NULL;
  return p;       
}
void traverse(struct segtree *tree)
{
  if(tree!=NULL)
  {
     traverse(tree->left);
     printf("sum:%lld  ",tree->sum);           
     traverse(tree->right);           
  }     
     
}
void initialize(int node, int b, int e,struct segtree **tree, int A[])
  {
      struct segtree *p,*q,*r;            
      if (b == e)
      {   
          (*tree)->sum=A[b];
      }
      else
       {  //printf("else\n");
         p=makenode();
         q=makenode();
          if(*tree==NULL)
          {
           r=makenode();              
           *tree=r;
           r->left=p;
           r->right=q;
           initialize(2 * node, b, (b + e) / 2, &p, A);
           initialize(2 * node + 1, (b + e) / 2 + 1, e, &q, A); 
           (*tree)->sum=p->sum+q->sum;
          }
          else
          {   
              (*tree)->left=p;
              (*tree)->right=q;          
              initialize(2 * node, b, (b + e) / 2, &p, A);
              initialize(2 * node + 1, (b + e) / 2 + 1, e, &q, A);
             (*tree)->sum=p->sum+q->sum;
          }   
          
      }
}
long long query(int b, int e, struct segtree *tree,int i, int j)
{                                 
      if (i > e || j < b)
          return 0;
      if (b >= i && e <= j)
          return tree->sum;
      return (query(b, (b + e) / 2,tree->left,i, j)+query((b + e) / 2 + 1, e,tree->right,i, j));
}
long long modify(int b, int e, struct segtree *tree,int i, int j,int k)
{
      if (i > e || j < b)
      return tree->sum;
      if (b==e)
      {
         tree->sum+=k; 
         return tree->sum;     
      }
      tree->sum=modify(b, (b + e) / 2,tree->left,i,j,k)+modify((b + e) / 2 + 1, e,tree->right,i,j,k);
      return tree->sum;
}
 
int main()
{
   int i,j,x,y,t,n,m,k=0;
   long long sum;
   struct segtree *tree;
  // while(scanf("%d",&n)&&n!=-1)
   //{
      scanf("%d",&n);                           
      for(i=1;i<=n;i++)
      {
        scanf("%d",&arr[i]);                 
      }
      tree=NULL;
      initialize(1,1,n,&tree,arr);traverse(tree);
      scanf("%d",&m);
     // printf("Case #%d:\n",++k);
      while(m-->0)
      {
        //sum=0;          
        scanf("%d%d%d",&j,&x,&y);            
        if(j==0)
        {
           scanf("%d",&k);      
           modify(1,n,tree,x,y,k);
        }   
        else
        {
          sum=0;  
          sum=query(1,n,tree,x,y);
          printf("%lld\n",sum);  
        }         
      }                     
      //printf("\n");                  
   //} 
   getch(); 
   return 0;    
}

