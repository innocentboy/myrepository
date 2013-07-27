#include<stdio.h>
#include<conio.h>
int h;
struct tree
{
   int info;
   struct tree *left;
   struct tree *right;       
};
struct stack
{
   struct tree *p;
   struct stack *next;     
};
void insert(struct tree **);
void height(struct tree *,int);
void inorder(struct tree *);
void insert_node(struct tree *,struct tree *,int);
void delete_node(struct tree **,int);
void stack_traverse(struct tree *);
void push(struct stack **,struct tree *);
struct tree *pop(struct stack **);
int main(int argc, char *argv[])
{
      int s,i,j,key;
      struct tree *root=NULL;
      while(1)
      {
            printf("enter the value for the selection of menu items\n"); 
            printf("1.insertion of items in tree\n2.height of tree\n3.inorder\n4.Linear Traverse\n5.delete a node\n6.exit\n");
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
            case 4:stack_traverse(root);
                   break;           
            case 5: printf("enter the value of key to be deleted...\n");
                    scanf("%d",&key);
                    delete_node(&root,key);
                    break;
            case 6:exit(0);       
            }              
      }            
         getch();
}
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
                       
     }
     if(key<=q->info)
                insert_node(q->left,q,key);
       
     else
                insert_node(q->right,q,key);            
}
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
void stack_traverse(struct tree *t)
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
