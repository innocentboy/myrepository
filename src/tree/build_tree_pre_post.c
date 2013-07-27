#include<stdio.h>
#include<conio.h>
#include<math.h>
#define N 8
#define MAX 99999
int k,height,l=MAX;
struct tree
{
   int info;
   struct tree *left;
   struct tree *right;       
};
char pre[N];
char post[N];
int search(char);
void build(struct tree *,int,int,int,int);
void preorder(struct tree *);
void inorder(struct tree *,int);
void postorder(struct tree *);
struct tree *make_node()
{
       struct tree *p;
       p=(struct tree *)malloc(sizeof(struct tree));
       return p;       
}

int main()
{
      struct tree  *tree=NULL,*p;
      int i,s;
      printf("*****enter the value of preorder and postorder value for the btree..**********\n");
      scanf("%s%s",pre,post);
    //  printf("\n%s\n%s\n",in,pre);
      p=make_node();
      p->info=pre[k];
      p->left=NULL;
      p->right=NULL;
      s=search(pre[k]);
      k++;
      tree=p;
      if(s!=0)
      build(tree,0,s-1,0,1);  
      printf("\n preorder traversal... ");
      preorder(tree);
      printf("\n inorder traversal...  ");
      inorder(tree,0);
      printf("\n postorder traversal...");
      postorder(tree);  
      printf("\n*********** print the lower and upper level of tree. ");
      printf("\nlower:%d\nUpper:%d",l,height); 
      getch();
}
int search(char c)
{
    int i,k;
    for(i=0;i<N;i++)
    {
        if(post[i]==c) 
        {
            k=i;
            break;             
        }               
    }
    return k;
}
void build(struct tree *p,int i,int j,int c,int h)
{
     struct tree *q;
     int s;
      if(i>=0&&j<N&&k<N)
      {           
            q=make_node();
            q->info=pre[k];
            q->left=NULL;
            q->right=NULL;        
            if(c==0){
                      (p)->left=q;
                    //   printf("\naddress:%u and address child:%u  value of %c: and level:%d",p,q,q->info,h); 
            }       
            else{
                   // printf("\naddress:%u and address child:%u  else.. value of %c::%d",p,q,q->info,h); 
                    (p)->right=q;
            }        
            s=search(pre[k]);
            k++;
               if(s!=i)        
               build(q,i,s-1,0,h+1);
               if(s!=j)
               build(p,s+1,j,1,h+1);  
        }
}
void inorder(struct tree *p,int h)
{
    if(p!=NULL)
    {
        if(p->left==NULL&&p->right==NULL)
        {
             if(h<l)
               l=h;
             if(h>height)
               height=h;                                    
        }       
        inorder(p->left,h+1);
        printf("%c  ",p->info);           
        inorder(p->right,h+1);       
    }     
     
}
void preorder(struct tree *p)
{
    if(p!=NULL)
    {
        printf("%c  ",p->info);         
        preorder(p->left);           
        preorder(p->right);
    }     
}
void postorder(struct tree *p)
{
    if(p!=NULL)
    {
                 
        postorder(p->left);           
        postorder(p->right);
        printf("%c  ",p->info);
    }     
}

