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
void initialize(int b, int e,struct segtree **tree)
  {
      struct segtree *p,*q,*r;
      int sum;            
      if (b == e)
      {   
          (*tree)->sum=arr[b];
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
           initialize(b, (b + e) / 2, &p);
           initialize((b + e) / 2 + 1, e, &q);
           r->sum=p->sum+(q->sum);
          }
          else
          {           
              initialize(b, (b + e) / 2, &p);
              initialize((b + e) / 2 + 1, e, &q);
              (*tree)->left=p;
              (*tree)->right=q;
              (*tree)->sum=p->sum+(q->sum);
          }   
          
      }
}
long long query(int b, int e, struct segtree *tree,int i, int j)
{                                  
      if (i > e || j < b)
      return 0;
      if (b >= i && e <= j)
      return tree->sum;
      return (query(b,(b + e) / 2,tree->left,i, j)+query((b + e) / 2 + 1, e,tree->right,i, j));
}
long long modify(int b, int e, struct segtree *tree,int i, int j)
{
     if(i>e||j<b)
       return tree->sum;            
     if(b==e)
     {
       tree->sum=(int)sqrt(tree->sum);        
       return tree->sum;
     }
     tree->sum=modify(b,(b + e) / 2,tree->left,i, j)+modify((b + e) / 2 + 1, e,tree->right,i, j);
     return (tree->sum);
     
}
 
int main()
{
   int i,j,x,y,n,m,sum,k=0;
   struct segtree *tree;
   while(scanf("%d",&n)&&n!=-1)
   {                       
      for(i=1;i<=n;i++)
      {
        scanf("%d",&arr[i]);                 
      }
      tree=NULL;
      initialize(1,n,&tree);//traverse(tree);
       scanf("%d",&m); 
      printf("Case %d:\n",++k);
      while(m-->0)
      {         
        scanf("%d%d%d",&j,&x,&y);
        if(j==0)
        {modify(1,n,tree,x,y);
        printf("modify\n");
        }
        else            
        printf("%lld\n",query(1,n,tree,x,y));  
      
      }                     
      //printf("\n");                  
   } 
   getch(); 
   return 0;    
}
