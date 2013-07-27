#include<stdio.h>
#include<conio.h>
#define N 200
int a[N],n;
int h;
struct tree
{
   int info;
   struct tree *left;
   struct tree *right;
   struct tree *sibling;
};
struct stack
{
   int f;
   struct tree *p;
   struct stack *next;
};



/**
start of function declaration..
*/

void insert(struct tree **);
void height(struct tree *,int);
void inorder(struct tree *);
void insert_node(struct tree *,struct tree *,int);
void delete_node(struct tree **,int);
void stack_in_traverse(struct tree *);
void stack_pre_traverse(struct tree *);
void stack_post_traverse(struct tree *);
void push(struct stack **,struct tree *);
void morris_travers(struct tree *tree);
void create_linkBetween_sibling(struct tree *);
void level_taversal_asList(struct tree *);
struct tree *pop(struct stack **);
int check_balance(struct tree *tree);
struct tree* treeToList(struct tree *);
struct tree* append(struct tree*,struct tree*);
struct tree* join(struct tree*,struct tree*);
void print_dlist(struct tree *);
struct tree * make_tree_from_sortedArray(struct tree *,int l,int r);
int sum_tree(struct tree *);
int check_bst(struct tree *);
struct tree *lca_bst(struct tree *,int,int);
void make_mirror(struct tree *);
int isSubtree(struct tree *,struct tree *);
int maxPathSum(struct tree *);
int hasPathSum(struct tree *,int);

/**
start of the main function....
*/
int main(int argc, char *argv[])
{
      int s,i,j,key,mid;
      struct tree *root=NULL,*p,*q=NULL,*head;
      while(1)
      {
            printf("enter the value for the selection of menu items\n");
            printf("1.insertion of items in tree\n2.height of tree\n3.inorder\n\
            4.stack in Traverse\n5.stack pre Traverse\n6.stack post Traverse\n7.delete a node\n\
            8.morrise traversal\n9.check balancing.\n10.make tree from array.\n11. creating link between sibling\n\
            12.counting no of trees.\n13.convert tree to list\n14.sum tree\n15.check bst\n16.lca BST\n\
            17.change to mirror\n18. make subtree\n19.checking subtree\n20.maximum path sum\n21. Has Path sum\n22.exit\n");
            scanf("%d",&s);
            switch(s)
            {
            case 1:insert(&root);
                   break;
            case 2:height(root,0);
                   printf("\nheight of the tree is %d\n",h);
                   h=0;
                   break;
            case 3:inorder(root);
                   break;
            case 4:stack_in_traverse(root);
                   break;
            case 5:stack_pre_traverse(root);
                   break;
            case 6:stack_post_traverse(root);
                   break;
            case 7: printf("enter the value of key to be deleted...\n");
                    scanf("%d",&key);
                    delete_node(&root,key);
                    break;
            case 8: printf("\n this is morrise traversal\n");
                    morris_travers(root);
                    break;
            case 9: if(check_balance(root)!=-1)
                    {
                       printf("\n*** tree is balanced ***\n");
                    }
                    else
                    {

                       printf("\n*** tree is not balanced ***\n");
                    }
                    break;
            case 10: scanf("%d",&n);
                     for(i=0;i<n;i++) scanf("%d",&a[i]);
                   //  printf("\n******\n");
                   //  printf("%d\n",n);
                   //  for(i=0;i<n;i++) printf("%d",a[i]);
                     p=(struct tree *)malloc(sizeof(struct tree));
                     mid=(n-1)>>1;
                     p->info=a[mid];
                     p->left=NULL;
                     p->right=NULL;
                     root=p;
                     root->left=make_tree_from_sortedArray(root->left,0,mid-1);
                     root->right=make_tree_from_sortedArray(root->right,mid+1,n-1);
                     break;
            case  11:   root->sibling=NULL;
                        create_linkBetween_sibling(root);
                        level_taversal_asList(root);
                         break;
            case  12: scanf("%d",&i);
                      printf("\n no of trees possible:%d\n",countTrees(i));
                      break;
            case  13: head=treeToList(root);
                      print_dlist(head);
                      break;
            case  14: sum_tree(root);
                      inorder(root);
                      break;
            case  15:
                      if(check_bst(root)!=-1)printf("\n the given binary tree is BST\n");
                      else printf("\nthis is not BST\n");
                      break;
            case  16:   scanf("%d%d",&i,&j);
                       struct tree *p;p=lca_bst(root,i,j);
                       if(p!=NULL)  printf("\nLCA of the given nodes is:%d\n",p->info);
                       else
                       printf("\ninvalide query\n");
                       break;
            case  17: make_mirror(root);
                      break;
            case  18: insert(&q);
                      break;
            case  19: if(q==NULL||isSubtree(root,q))
                      printf("\ngiven tree is subtree of large tree\n");
                      else
                      printf("\nit is not the subtree of given tree\n");
                      break;
            case  20: printf("\nMaximum path sum:%d\n",maxPathSum(root));
                      break;
            case  21: if(scanf("%d",&i)&&hasPathSum(root,i))
                      printf("\ntree contains the path with given sum\n");
                      else
                      printf("\ntree does not contain the path sum.\n");
                      break;
            case  22:exit(0);
            }
      }
         getch();
}

/**
this function checks whether the given tree contains any pathSum with the given sum..
*/
int checkPathSum(struct tree *root,int sum)
{
  if(sum==0)
  return 1;
  else if(root==NULL&&sum!=0) return 0;
  else
  {
    return (checkPathSum(root->left,sum-root->info)||checkPathSum(root->right,sum-root->info));
   }
}

int hasPathSum(struct tree *root,int sum)
{

    if(root!=NULL)
    {
        if(checkPathSum(root,sum))
        return 1;
        return (hasPathSum(root->left,sum)||hasPathSum(root->right,sum));
    }

}



/**
this function gives the value of maximum sum among all the root to leaf paths of the tree.
*/
int maxPathSum(struct tree *root)
{
    int lsum=0,rsum=0,sum=0;
    if(root!=NULL)
    {
       lsum=maxPathSum(root->left);
       rsum=maxPathSum(root->right);
       sum+=(root->info)+((lsum>rsum)?lsum:rsum);
    }
    return sum;
}


/**
this function checks whether given tree is subtree of larger tree..
*/
int subtree(struct tree *p,struct tree *q)
{
    if(p==NULL&&q==NULL)
    return 1;
    else if(p!=NULL&&q!=NULL)
    {
      return ((p->info==q->info)&&subtree(p->left,q->left)&&subtree(p->right,q->right));
    }
    else
    return 0;

}

int isSubtree(struct tree *root,struct tree *p)
{
   if(root!=NULL)
   {
      if(subtree(root,p))
      return 1;
      else return (isSubtree(root->left,p)||isSubtree(root->right,p));
    }
}


/**
this method changes the given BST into it's mirror image.
*/
void make_mirror(struct tree *root)
{
   struct tree *p;
   if(root!=NULL)
   {
      make_mirror(root->left);
      make_mirror(root->right);
      p=root->left;
      root->left=root->right;
      root->right=p;
   }

}


/**
this function tells about the LCA of given Nodes.
*/

struct tree *lca_bst(struct tree *root,int p,int q)
{
    if(root!=NULL)
    {
      if(root->info>p&&root->info>q)
      return lca_bst(root->left,p,q);
      else if(root->info<p&&root->info<q)
      return lca_bst(root->right,p,q);
      else
      return root;
    }
    return NULL;
}



/**
this function check the given binary tree is BST or not
*/
int check_bst(struct tree *root)
{
    int booll=1,rbool,lbool;
    if(root!=NULL)
    {
      if(root->left!=NULL&&((root->info)<(root->left)->info))
      booll=-1;
      if(root->right!=NULL&&(root->info)>((root->right)->info))
      booll=-1;
      if(check_bst(root->left)==-1&&check_bst(root->right)==-1)
      booll=-1;
     }
    return booll;
}

/**
end of the function
*/

/**
strat of the sum tree function.....
*/

int sum_tree(struct tree *root)
{
   int sum=0;
   if(root!=NULL)
   {
       sum+=(root->info)+sum_tree(root->left)+sum_tree(root->right);
       root->info=sum;
    }
    return sum;

}


/**
these functions will convert tree into list;
start of the function..
*/

struct tree* treeToList(struct tree *root)
{
   struct tree *p,*q;
   if(root==NULL)
   return NULL;
   p=treeToList(root->left);
   q=treeToList(root->right);
   root->left=root;
   root->right=root;
   p=append(p,root);
  // if(p!=NULL) printf("%d ",p->info);
   return append(p,q);
}

struct tree* append(struct tree *p,struct tree *q)
{
   struct tree *pLast,*qLast;
   if(p==NULL) return q;
   else if(q==NULL)return p;
   pLast=p->left;
   qLast=q->left;
   join(pLast,q);
   join(qLast,p);
   return p;
}

struct tree* join(struct tree *p,struct tree *q)
{
    struct tree *node;
    p->right=q;
    q->left=p;
}


void print_dlist(struct tree *root)
{
    struct tree *p=root;

    do{
       printf("%d ",p->info);
       p=p->right;
    }while(p!=root);
}


/**
end of the function..
*/


/**
It counts all the binary trees that are possible.
*/
int countTrees(int numKeys) {
  if (numKeys <=1) {
    return(1);
  }
  else {
    // there will be one value at the root, with whatever remains
    // on the left and right each forming their own subtrees.
    // Iterate through all the values that could be the root...
    int sum = 0;
    int left, right, root;
    for (root=1; root<=numKeys; root++) {
      left = countTrees(root - 1);
      right = countTrees(numKeys - root);
      // number of possible trees with this root == left*right
      sum += left*right;
    }
    return(sum);
  }
}

/*

*/

void insert(struct tree **t)
{
     int key;
     struct tree *p,*q=NULL,*r;
     printf("\nenter the value to be inserted in the tree..\n");
     scanf("%d",&key);

     if(*t==NULL)
     {
        p=(struct tree *)malloc(sizeof(struct tree));
        p->info=key;
        p->left=NULL;
        p->right=NULL;
        //q=*t;
        *t=p;
        return;
     }
     else
        insert_node(*t,q,key);

}
void insert_node(struct tree *q,struct tree *p,int key)
{
     struct tree *cret;
     if(q==NULL)
     {
        cret=(struct tree *)malloc(sizeof(struct tree));
        cret->info=key;
        cret->left=NULL;
        cret->right=NULL;
           if(key<=(p)->info)
                (p)->left=cret;
           else
                (p)->right=cret;
         return;

     }

     if(key<=q->info)

                insert_node(q->left,q,key);
     else
                insert_node(q->right,q,key);
}

/**
  this function creates the linking between the sibling.
  start of function
*/
void create_linkBetween_sibling(struct tree *root)
{
   if(root!=NULL)
   {
     // root->left->sibling=root->right;
      if(root->left!=NULL)
      {
          if(root->right!=NULL)
          root->left->sibling=root->right;
          else if(root->sibling!=NULL&&root->sibling->left!=NULL)
          root->left->sibling=root->sibling->left;
          else if(root->sibling!=NULL)
          root->left->sibling=root->sibling->right;
          else
          root->left->sibling=NULL;
      }
      if(root->right!=NULL)
      {
         if(root->sibling!=NULL&&(root->sibling)->left!=NULL)
          root->right->sibling=root->sibling->left;
          else if(root->sibling!=NULL)
          root->right->sibling=root->sibling->right;
          else
          root->right->sibling=NULL;
      }
      create_linkBetween_sibling(root->left);
      create_linkBetween_sibling(root->right);
   }
}
/*
  end of function
*/


/**
this function traverse the tree level wise as linked lists.
start of function
*/
void level_taversal_asList(struct tree *root)
{
    struct tree *p,*q;
    int level=0;
    printf("\n**** printing acordig to level\n");
    while(root!=NULL)
    {
        printf("\n***** atlevel:%d *****\n",level);
        p=root;
        while(p!=NULL)
        {
          printf("%d ",p->info);
          p=p->sibling;
        }
        level++;
        root=root->left;
    }
}

/*
end of function.
*/


/**
  function to check tree is balanced or not.
  start.
*/

int check_balance(struct tree *root)
{
    int l=0,r=0,ans=0;
    if(root!=NULL)
    {
       l=check_balance(root->left);
       r=check_balance(root->right);
       if(l==-1||r==-1)
       return -1;
       if(abs(l-r)<2)
       return (l>r?l:r)+1;
       else
       return -1;
    }
    else
    return 0;

}
/*
    end.
*/


/**
 this function make the balanced tree from  the sorted array.
   start of function.
*/
struct tree * make_tree_from_sortedArray(struct tree *root,int start,int end)
{
   struct tree *p,*q;
   int i,j,mid;
    if(start>end) return NULL;
   mid=(start+end)>>1;
   printf("%d %d %d\n",start,end,mid);
   if(root==NULL){
   p=(struct tree *)malloc(sizeof(struct tree));
   p->left=NULL;
   p->right=NULL;
   }
   p->info=a[mid];
   p->left=make_tree_from_sortedArray(p->left,start,mid-1);
   p->right=make_tree_from_sortedArray(p->right,mid+1,end);
   return p;
}

/*
  end of function.
*/


/**
  start of morrise traversal..
*/

void morris_travers(struct tree *root)
{
   struct tree *current,*pre;
   current=root;
   while(current!=NULL)
   {
      if(current->left==NULL)
      {
         printf("%d ",current->info);
         current=current->right;
      }
      else
      {
        pre=current->left;
        while(pre->right!=NULL&&pre->right!=current)
        pre=pre->right;
        if(pre->right==NULL){
        pre->right=current;
        current=current->left;
        }
        else
        {
           pre->right=NULL;
           printf("%d ",current->info);
           current=current->right;
        }
     }
    }
}

/*
  end of morrise traversal...
*/

void inorder(struct tree *t)
{
     if(t!=NULL)
     {
          inorder(t->left);
          printf("%d ",t->info);
          inorder(t->right);

     }

}
void height(struct tree *d,int c)
{
     if(d!=NULL)
     {
         if(h<c)
            h=c;
         height(d->left,c+1);
         height(d->right,c+1);
     }

}
void delete_node(struct tree **t,int key)
{
     struct tree *p,*q,*f,*r,*s,*tt;
     if(*t==NULL)
     {
         printf("tree is empty\n");
         return;
     }
     p=NULL;
     q=*t;
     while(q!=NULL&&q->info!=key)
     {
         p=q;
         if(key<=q->info)
             q=q->left;
         else
             q=q->right;
     }
     if(q==NULL)
     {
          printf("\n the key is not present in the tree...\n");
          return;
     }
     else
        if(q->left==NULL)
           r=q->right;
        else if(q->right==NULL)
           r=q->left;
        else
        {
          f=q->right;
           s=f->left;
           while(s!=NULL)
           {
              tt=f;
              f=s;
              s=s->left;
           }
           if(f==q->right)
           {
               q->right=f->right;
               q->info=f->info;
               r=q;
           }
           else
           {
               tt->left=f->right;
               q->info=f->info;
               r=q;
           }

        }
      if(p==NULL)
      {
           *t=r;
      }
      else if(q==p->left)
                p->left=r;
           else
                p->right=r;

}
void stack_in_traverse(struct tree *t)
{
     struct tree *p,*q;
     struct stack *s=NULL;
     q=t;
     do
     {
         while(q!=NULL)
         {
             push(&s,q);
             q=q->left;
         }
         if(s!=NULL)
         {
            p=pop(&s);
            printf("%d ",p->info);
            q=p->right;
         }
     }while(q!=NULL||s!=NULL);

}


void stack_pre_traverse(struct tree *t)
{
     struct tree *p,*q;
     struct stack *s=NULL;
     q=t;
     do
     {
         while(q!=NULL)
         {
             push(&s,q);
             printf("%d ",q->info);
             q=q->left;
         }
         if(s!=NULL)
         {
            p=pop(&s);
            q=p->right;
         }
     }while(q!=NULL||s!=NULL);

}
void stack_post_traverse(struct tree *t)
{
     int f;
     struct tree *p,*q;
     struct stack *s=NULL;
     q=t;
     do
     {
         while(q!=NULL)
         {
             push(&s,q);
             s->f=0;
             q=q->left;
         }
         if(s!=NULL)
         {
            f=s->f;
            p=pop(&s);
            if(p->right==NULL||f==1)
                printf("%d ",p->info);
            else
            {
                    push(&s,p);
                    s->f=1;
            }
            if(f==0)
            q=p->right;
         }
     }while(q!=NULL||s!=NULL);

}
void push(struct stack **i,struct tree *t)
{
     struct stack *p,*q;
     p=(struct stack *)malloc(sizeof(struct stack));
     p->p=t;
     p->next=*i;
     *i=p;
}
struct tree *pop(struct stack **s)
{
       struct tree *p;
       if(*s==NULL)
       return NULL;
       p=(*s)->p;
       *s=(*s)->next;
       return p;

}
