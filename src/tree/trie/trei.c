#include<stdio.h>
#include<conio.h>
int h;
struct trie
{
   int info;
   char *rec_info;
   struct trie *next[10];     
};
void insert(struct trie **);
void height(struct trie *,int);
void find(struct trie *);
void delete_key(struct trie **);
struct trie *make_trie();
int empty(struct trie *);
int main(int argc, char *argv[])
{
      int s,i,j,key;
      struct trie *root=NULL;
      while(1)
      {
            printf("enter the value for the selection of menu items\n"); 
            printf("1.insertion of items in tree\n2.height of tree\n3.Find key.\n4.delete key\n5.exit\n");
            scanf("%d",&s);
            switch(s)
            {
            case 1:insert(&root);      
                   break;
            case 2:height(root,0);
                   printf("\nheight of the tree is %d\n",h);
                   h=0;
                   break;
            case 3:find(root); 
                   break;  
            case 4:delete_key(&root);
                   break;           
            case 5:exit(0);       
            }              
      }            
         getch();
}
int empty(struct trie *t)
{
     int i,f=1;
     for(i=0;i<10;i++)
     {
        if(t->next[i]!=NULL)
        {
           f=0;
           break;                    
        }                 
     }
     return f;    
    
}
void delete_key(struct trie **t)
{
       struct trie *p,*q,*r;
       char s[10],*str;
       int k=1;
       printf("\nenter the value of key to be deleted..\n");
       scanf("%s",s);
       str=s;
       q=*t;
       while(q->next[*str-48]!=NULL&&(*str!='\0'))
       {
            if((q->next[*str-48])->rec_info=="null"&&k)
            {
              r=q;                   
              k=0;    
            }     
            if((q->next[*str-48])->rec_info=="info")
            {
              r=q;
              k=1;
            }                                  
            p=q;                                      
            q=q->next[*str-48];
            str++;                                           
       }
       if(*str!='\0')
       {
            printf("\nkey is not present in the tree..");
            return;              
       }
       else
       {
          if(q->rec_info=="null")
          {
            printf("\nkey is not present in tree.");
            return;                       
          } 
          if(empty(q))
          {
                 p->next[q->info-48]=NULL;
                 free(q);     
          }
          else
          {
             q->rec_info="null";    
          }    
       }
}
void insert(struct trie **t)
{
        struct trie *p,*q,*r;
        char s[10],*str;
        printf("\nenter the value of key to be inserted in trie..\n");
        scanf("%s",s);
        str=s;
        q=*t;
        if(q==NULL)
        {
                   
           p=make_trie();
           *t=p;
           q=*t;   
        }
    //    printf("%u",q);
        while(q->next[*str-48]!=NULL&&(*str!='\0'))
        {
            q=q->next[*str-48];
            str++;                                        
        }
        if(*str=='\0')
        {
            if(q->rec_info=="info")
            {
               printf("\nkey is present already in the trie.\n");                
               return;
            }
            q->rec_info="info";
        }
        else
        {
             while(*str!='\0')
             {
                r=make_trie();
                r->info=*str;                 
                q->next[*str-48]=r;
                q=r;
                str++; 
                printf("\ninserted.");             
             }    
             q->rec_info="info";
        }
             
     
}
struct trie *make_trie()
{
   struct trie *p;
   int i;
   p=(struct trie *)malloc(sizeof(struct trie));
   for(i=0;i<10;i++)
   {
      p->next[i]=NULL;                 
   }
   p->rec_info="null";
   return p;       
}
void find(struct trie *t)
{
     struct trie *q;
     char s[10],*str;
     printf("\nenter the value of key to be searched.\n");
     scanf("%s",s);
     str=s;
     q=t;
     while(q->next[*str-48]!=NULL&&*str!='\0')
     {
            q=q->next[*str-48];
            str++;
     }
     if(*str=='\0')
     {
         if(q->rec_info=="null") 
         {
            printf("\nkey is not present in the trie\n");
            return;                 
         }
         printf("\nkey is present in the tree..\n");
         return;             
     }
     printf("\nkey is not present in the tree..\n");
}
void height(struct trie *t,int h1)
{
     if(t!=NULL)
     {
        int i;
        if(h1>h)
        {
          h=h1;       
        }
        for(i=0;i<10;i++)
        {
             if(t->next[i]!=NULL)            
             printf("%c  ",(t->next[i])->info);            
             height(t->next[i],h1+1);                 
        }
     }  
}
