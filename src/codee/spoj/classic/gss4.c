#include<stdio.h>
#include<math.h>
#define N 100005
int arr[N];
struct segtree
{
  int  freqnt;
  int left_elm;
  int right_elm;
  int left_fre;
  int right_fre;       
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
     printf("sum:%d  ",tree->left_fre);           
     traverse(tree->right);           
  }     
     
}
void initialize(int b, int e,struct segtree **tree)
  {
      struct segtree *p,*q,*r;
      int sum;            
      if (b == e)
      {   
          (*tree)->left_fre=(*tree)->right_fre=1;
          (*tree)->left_elm=(*tree)->right_elm=arr[b];
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
           r->left_elm=p->left_elm;
           r->right_elm=q->right_elm;                                                            
           if((p->right_elm==q->left_elm)&&(p->left_elm==p->right_elm))
           {
              r->left_fre=(p->left_fre)+q->left_fre;
              r->right_fre=q->right_fre;
           }
           else if((p->right_elm==q->left_elm)&&(p->left_elm!=p->right_elm))
           {
              sum=(p->right_fre)+q->left_fre;
              if(sum>(p->left_fre))r->left_fre=sum;
              else
              r->left_fre=p->left_fre;
              r->right_fre=q->right_fre;     
           }
           else
           {
               r->left_fre=((p->left_fre)>(q->left_fre))?p->left_fre:q->left_fre;
               r->right_fre=q->right_fre;
           }
          }
          else
          {   
              (*tree)->left=p;
              (*tree)->right=q;          
              initialize(b, (b + e) / 2, &p);
              initialize((b + e) / 2 + 1, e, &q);
              r=(*tree);
              r->left_elm=p->left_elm;
              r->right_elm=q->right_elm;    
              if((p->right_elm==q->left_elm)&&(p->left_elm==p->right_elm))
              { //printf("if\n");
                r->left_fre=(p->left_fre)+q->left_fre;
                r->right_fre=q->right_fre;
              }
              else if((p->right_elm==q->left_elm)&&(p->left_elm!=p->right_elm))
             {  //printf("else if\n");
              sum=(p->right_fre)+q->left_fre;
              if(sum>(p->left_fre))r->left_fre=sum;
              else
              r->left_fre=p->left_fre;
              r->right_fre=q->right_fre;
             }
            else
            {  //printf("else\n");
               r->left_fre=((p->left_fre)>(q->left_fre))?p->left_fre:q->left_fre;
               r->right_fre=q->right_fre;
            }
          }   
          
      }
}
long long query(int b, int e, struct segtree *tree,int i, int j)
{                                  
      if (i > e || j < b)
      return 0;
      if (b >= i && e <= j)
      return tree->left_fre;
      return (query(b,(b + e) / 2,tree->left,i, j)>query((b + e) / 2 + 1, e,tree->right,i, j)?query(b,(b + e) / 2,tree->left,i, j):query((b + e) / 2 + 1, e,tree->right,i, j));
}
 
int main()
{
   int i,j,x,y,n,m,sum;
   struct segtree *tree;
   while(scanf("%d",&n)&&n!=0)
   {
      scanf("%d",&m);                        
      for(i=1;i<=n;i++)
      {
        scanf("%d",&arr[i]);                 
      }
      tree=NULL;
      initialize(1,n,&tree);//traverse(tree);
      while(m-->0)
      {         
        scanf("%d%d",&x,&y);            
        printf("%d\n",query(1,n,tree,x,y));  
      
      }                     
      //printf("\n");                  
   } 
   getch(); 
   return 0;    
}
