#include<stdio.h>
#include<conio.h>
#include<math.h>
#define N 20
int k;
struct tree
{
   int info;
   struct tree *left;
   struct tree *right;
};
char in[N]="eicfjbgdkhla";
char pre[N]="abceifjdghkl";
int search(char);
void build(struct tree *,int,int,int,int);
void preorder(struct tree *);
void inorder(struct tree *);
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
      printf("*****enter the value of inorder and postorder value for the btree..**********\n");
    //  scanf("%s%s",in,pre);
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
      if(s!=N-1)
      build(tree,s+1,N-1,1,1);
      printf("\n preorder traversal... ");
      preorder(tree);
      printf("\n inorder traversal...  ");
      inorder(tree);
      printf("\n postorder traversal...");
      postorder(tree);
      getch();
}
int search(char c)
{
    int i,k;
    for(i=0;i<N;i++)
    {
        if(in[i]==c)
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
            if(c==0)
            {
                      (p)->left=q;
                      //   printf("\naddress:%u and address child:%u  value of %c: andlevel:%d",p,q,q->info,h);

            }
            else
            {
                    //printf("\naddress:%u and address child:%u  else.. value of%c:andlevel:%d",p,q,q->info,h);
                    (p)->right=q;
            }
            s=search(pre[k]);
            k++;
               if(s!=i)
               build(q,i,s-1,0,h+1);
               if(s!=j)
               build(q,s+1,j,1,h+1);
       }
}
void inorder(struct tree *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%c  ",p->info);
        inorder(p->right);
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
