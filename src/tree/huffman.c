#include<stdio.h>
#include<conio.h>
#include<string.h>
#define N 26
#define MAX 100
#define MAX_ENCODE 100000 
int n,en;
int encode[MAX_ENCODE];
int frequency[N];
char alpha[N];
struct code
{
   int codde[MAX];
   int top;     
}codd[N];
struct tree
{
  int frequency;
  char alpha;
  struct tree *father;
  struct tree *left;
  struct tree *right;       
};
struct tree *leaf_pointer[N];
struct pqueu
{
   struct tree *tree;
   struct pqueu *next;        
};
void insert_pqueu(struct pqueu **,struct tree **,char,int);
struct pqueu *extract(struct pqueu **);
void insert_tree(struct tree **,struct pqueu *,struct pqueu *);
struct tree *make_tree();
struct pqueu *make_pqueu();
void inorder(struct tree *);
struct pqueu *extract(struct pqueu **);
void binary_code(struct tree *);
void compress();
void decode(struct tree *);
int main()
{
     int i,j,input;
     char  s[2],c,*str,*ss;
     struct tree *root=NULL,*tp;
     struct pqueu *head=NULL,*qp,*qq,*qr;
     printf("****** programm for implrmentation of the huffman algorithm. *****\n");
     printf("\nenter the value for no of alphabet present in the code..\n");
     scanf("%d",&n);
     printf("\nenter the value of alphabet and frequency pair for that alphabet..\n");
     for(i=0;i<n;i++)
     {     
            printf("\nenter value:\n");         
            c=getche(); 
            j=c;
            scanf("%d",&input);
            frequency[j-65]=input;
            alpha[j-65]=c;
      //      ss=s;
            insert_pqueu(&head,&root,c,input);
            leaf_pointer[j-65]=root;
            root=NULL;
            fflush(stdin);       
     }  
     qr=head;
     while(head->next!=NULL)
     {            
            qp=extract(&head);
            qq=extract(&head);
            insert_tree(&root,qp,qq);
            insert_pqueu(&head,&root,root->alpha,root->frequency);
     }
    // printf("\n print the value of tree");
    // inorder(root);
     printf("\ncreate the encode for each alpha\n");
     binary_code(root);
     printf("\nprintf the binary code for each alpha value..\n");
     for(i=0;i<N;i++)
     {
        if(frequency[i]!=0)
        {                      
          printf("\ncode for alpha:%c is binarycode:",alpha[i]);             
          for(j=(codd[i]).top;j<MAX;j++)             
          printf("%d",(codd[i]).codde[j]); 
        }                 
     } 
     compress();
     printf("\n decode the value of compressed file..\n");
     decode(root);
     getch();    
}
void decode(struct tree *root)
{
     struct tree *p,*q;
     int i,j;
     q=root;
     for(i=0;i<=en;i++)
     {
            if(q->left==NULL&&q->right==NULL)
            {
               printf("%c",q->alpha);
               if(i<en)
               i--;
               q=root;                                 
            }
            else if(encode[i]==0)
            {
               q=q->left;     
            }
            else
            {
               q=q->right;      
            }               
     }
}
void compress()
{
     char str[MAX],*s,c;
     int i,j;
     printf("\nenter the value of message to be encoded(compress)\n");
     scanf("%s",str);
     s=str;
     while(*s!='\0')
     {
         j=*s;           
         for(i=codd[j-65].top;i<MAX;i++)
         {
             printf("%d:%d:%d ",j,codd[j-65].codde[i],en);
             encode[en]=codd[j-65].codde[i];
             en++;                                    
         } 
         s++;             
     }     
     printf("\nmessage:%s",str);
     printf("\nprintf the value of compressed message: %d\n",en);
     for(i=0;i<en;i++)
       printf("%d",encode[i]);
}
void binary_code(struct tree *root)
{
     struct tree *p,*q;
     int i,j;
     for(i=0;i<N;i++)
     {
         if(frequency[i]!=0)
         {                            
          (codd[i]).top=MAX-1;
          p=leaf_pointer[i];
          while(p!=root)
          {
                q=p->father;
                if(p==q->left)
                {
                   (codd[i]).codde[(codd[i]).top]=0;              
                }
                else
                {
                   (codd[i]).codde[(codd[i]).top]=1;     
                }
               (codd[i]).top--;
                p=q;             
          }
          (codd[i]).top++;           
         }
     }  
}
struct pqueu *extract(struct pqueu **head)
{
       struct pqueu *qp;
       qp=*head;
       *head=qp->next;
       return qp;
}
void inorder(struct tree *t)
{
     if(t!=NULL)
     {
       //  char *str;       
         inorder(t->left);
      //   str=t->alpha;
         printf("\n alpha:%c and frequency:%d",t->alpha,t->frequency);           
         inorder(t->right);       
     }
}
void insert_tree(struct tree **t,struct pqueu *qp,struct pqueu *qq)
{
     struct tree *tp;
     char *str;
     tp=(struct tree *)malloc(sizeof(struct tree));
     tp->frequency=(qp->tree)->frequency+(qq->tree)->frequency;
   //  strcpy((tp)->alpha,(qp->tree)->alpha);
     (tp)->alpha=(qq->tree)->alpha;
     tp->left=qp->tree;
     tp->right=qq->tree;
     (qp->tree)->father=tp;
     (qq->tree)->father=tp;
     *t=tp;
}
struct pqueu *make_pqueu()
{
       struct pqueu *p;
       p=(struct pqueu *)malloc(sizeof(struct pqueu));
       return p;
}
struct tree *make_tree()
{
       struct tree *p;
       p=(struct tree *)malloc(sizeof(struct tree));
       return p;
}
void insert_pqueu(struct pqueu **head,struct tree **root,char c,int d)
{
     struct pqueu *qp,*qq,*qr;
     struct tree *t;
     char *str;
     qp=make_pqueu();
     if(*root==NULL)
     {  
         t=make_tree();
         t->frequency=d;       
         (t->alpha=c);
         t->left=NULL;
         t->right=NULL;
         qp->tree=t;
         *root=t;
     }
     else
         qp->tree=*root;   
         qp->next=NULL;
     qq=*head;
     if(qq==NULL)
     {
        *head=qp;
        return;           
     }
     else
     {
         qr=NULL;
         while(qq!=NULL&&d>(qq->tree)->frequency)
         {
              qr=qq;
              qq=qq->next;          
         }
         if(qr==NULL)
         {
            qp->next=*head;         
            *head=qp;
            return;            
         } 
         else if(qq==NULL)
         {
           qr->next=qp;     
         }   
         else
         {
             qp->next=qr->next;
             qr->next=qp;    
         }
     }
}

