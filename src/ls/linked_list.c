#include<stdio.h>
#include<conio.h>
struct list
{
   int info;
   struct list *next;
};
typedef struct list Node;
struct list1
{
   int info;
   struct list *next;
};


/**
start of the function declarations...
*/
void insert(struct list **);
void sorted_insert(struct list **);
void display(struct list *);
void reverse(struct list **);
struct list* k_reverse(struct list *,int);
void reverse_recursion(struct list *,struct list **);
void concatenate(struct list *,struct list1 *);
int add_simple(struct list *,struct list1 *);
int add_tipical(struct list *,struct list1 *);
int add_typical_single_list(struct list *head,struct list *p,int c);
void splitList(struct list *,struct list **,struct list**);
Node *mergeList(Node *list1,Node *list2);

/**
start of the main function..
*/
int main(int argc, char *argv[])
{
      int c,i,j;
      struct list *head=NULL,*p=NULL,*q;
      struct list1 *head1=NULL,*r,*s;
      struct list *evenList=NULL,*oddList=NULL;
      while(1)
      {
            printf("enter the value for the selection of menu items\n");
            printf("1.insertion of items in list\n2.insertion of items in list1\n\
            3.concatenation of list\n4.display of list\n5.display of list1\n6.reverse\n\
            7.recrsive_reverse\n8.k_reverse\n9.sorted oreder\n10.sorted insert for list 1..\n\
            11.add simple\n12.add typical\n13.split list in odd even\n14.create a different list\n15.merge sorted lists\n\
            16.exit.\n");
            scanf("%d",&c);
            switch(c)
            {
            case 1:insert(&head);
                   break;
            case 2:insert(&head1);
                   break;
            case 3:concatenate(head,head1);
                   break;
            case 4:display(head);
                   break;
            case 5:display(head1);
                   break;
            case 6:reverse(&head);
                   break;
            case 7:reverse_recursion(head,&head);
                   break;
            case 8:scanf("%d",&i);
                   head=k_reverse(head,i);
                   break;
            case 9:sorted_insert(&head);
                   break;
            case 10:sorted_insert(&head1);
                    break;
            case 11:add_simple(head,head1);
                    break;
            case 12:p=head;r=head1;
                    while(p!=NULL&&r!=NULL)
                    {
                      q=p;p=p->next;
                      s=r;r=r->next;
                    }p=head;q=q->next;
                    while(q!=NULL)
                    {
                       p=p->next;q=q->next;
                    }
                    int carry=add_tipical(p,head1);
                    carry=add_typical_single_list(head,p,carry);
                    if(carry)
                    {
                      p=(struct list *)malloc(sizeof(struct list));
                      p->info=carry;
                      p->next=head;
                      head=p;
                    }
                    break;
            case 13:splitList(head,&evenList,&oddList);printf("\neven list:");
                    display(evenList);printf("\nodd Lis:");
                    display(oddList);printf("\ns");
                    break;
            case 14:sorted_insert(&p);
                    break;
            case 15: printf("\nprint the sorted merged list\n");
                     display(mergeList(head,p));
                     break;
            case 16:exit(0);
            }
      }
         getch();
}

/**

*/
Node *mergeList(Node *list1,Node *list2)
{
   Node *p,*q,*r=NULL;
   Node *mergedList=NULL;
   p=(Node *)malloc(sizeof(Node));
   mergedList=p;
   p->next=NULL;
   while(list1!=NULL&&list2!=NULL)
   {
       q=(Node *)malloc(sizeof(Node));
       if(list1->info<list2->info)
       {
          p->info=list1->info;
          list1=list1->next;
          p->next=q;
          r=p;
          p=q;
        }
        else
        {
            p->info=list2->info;
          list2=list2->next;
          p->next=q;
          r=p;
          p=q;
        }
    }
    while(list1!=NULL)
    {
      p->info=list1->info;
      q=(Node *)malloc(sizeof(Node));
      p->next=q;
      r=p;
      p=q;
      list1=list1->next;
    }
    while(list1!=NULL)
    {
      p->info=list2->info;
      q=(Node *)malloc(sizeof(Node));
      p->next=q;
      r=p;
      p=q;
      list2=list2->next;
    }
    p->next=NULL;
    r->next=NULL;
    return mergedList;
}



/**
this function splits the list into list and and even without changing their order.. in the original list..
*/
void splitList(struct list *list,struct list **evenlist,struct list **oddlist)
{
    struct list *p,*r;
   // p=list;
    while(list!=NULL)
    {
      if(((list->info)&1)&&*oddlist==NULL)
      {
           *oddlist=list; r=list;
      }
      else if(!((list->info)&1)&&*evenlist==NULL)
      {
           *evenlist=list;  p=list;
      }
      else if((list->info)&1)
      {
          r->next=list;
          r=list;
      }
      else
      {    p->next=list;
          p=list;
      }
      list=list->next;
    }
    r->next=NULL;
    p->next=NULL;
}

/**
this function adds the two lists.. in simple formate.
EX:  3->5->4->1  +  3->2->1 =6->7->5->1
*/
int add_simple(struct list *head,struct list1 *head1)
{
    struct list *p,*q;
    struct list1 *r,*s;
    p=head;r=head1;
    int i,carry=0;
    while(p!=NULL&&r!=NULL)
    {
       p->info=(p->info)+(r->info)+carry;
       if(p->info>9)
       {
          p->info=p->info%10;
          carry=1;
        }
        else
        carry=0;
        p=p->next;r=r->next;
    }
    if(r==NULL)
    {
       while(p!=NULL){
       p->info=(p->info)+carry;
       if(p->info>9)
       {
          p->info=p->info%10;
          carry=1;
        }
        else
        carry=0;
        q=p;
        p=p->next;
       }
       if(carry)
       {
          p=(struct list *)malloc(sizeof(struct list));
          p->info=carry;
          p->next=NULL;
          q->next=p;
        }
    }

}
/**
this function adds the two lists.. in little lipical formate formate.
EX:  1->4->5->3  +  1->2->3 =1->5->7->6
*/
/*
this is auxilary function used by the add_typical.
*/
int add_typical_single_list(struct list *head,struct list *p,int c)
{
    //struct list *p;
    int carry=0;
    if(head!=p)
    {
       carry=add_typical_single_list(head->next,p,c);
       head->info=(head->info)+carry;
       if(head->info>9)
       {
          head->info=(head->info)%10;
          carry=1;
        }
        else
        carry=0;
    }
    else
    carry=c;
    return carry;
}

int add_tipical(struct list *head,struct list1 *head1)
{
   struct list *p,*q;
   struct list1 *r,*s;
   int carry=0;
   if(head!=NULL){
   carry=add_tipical(head->next,head1->next);
   head->info=(head->info)+(head1->info)+carry;
   if(head->info>9)
   {
     head->info=head->info%10;
     carry=1;
    }
   }
   return carry;
}


/**
this function insert the values in the list in sorted order.
*/
void sorted_insert(struct list **head)
{
   int i,j;
   struct list *p,*q,*r;
   p=*head;
   r=(struct list *)malloc(sizeof(struct list));
   printf("enter the value to be inserted\n");
   scanf("%d",&i);
   r->info=i;
   r->next=NULL;
   if(p==NULL)
   {
      *head=r;
    }
   else {

        q=NULL;
        while(p!=NULL&&i>(p->info))
        {
          q=p;
          p=p->next;
        }
        if(p==NULL)
        q->next=r;
        else if(q==NULL)
        {
          r->next=p;
          *head=r;
        }
        else
        {
           q->next=r;
           r->next=p;
        }

    }
}



/**
this function reverse the list in the size of K.
*/
struct list* k_reverse(struct list *head,int k)
{
   int i=k;
   if(head!=NULL){
   struct list *prev=NULL,*next,*current=head;
   while(k>0&&current!=NULL)
   {
      next=current->next;
      current->next=prev;
      prev=current;
      current=next;
      k--;
    }
    head->next=k_reverse(current,i);
    return prev;
   }
   else
   return NULL;
}


/**
this function reverse the list recursively..
start of function.
*/
void reverse_recursion(struct list *start,struct list **head)
{
    struct list *p,*q,*r;
    p=start;
    if(p->next!=NULL)
    {
     //  printf("  %d \n",p->info);
       q=p->next;
     //  printf(" %d\n ",q->info);
       reverse_recursion(q,head);
       q->next=p;
      // p->next=NULL;

    }
    else if(p->next==NULL)
    {  //printf("\n kadkahdkad %d \n",p->info);
        (*head)->next=NULL;
        *head=p;
    }

}

/*
end of function.
*/

void insert(struct list **t)
{
      struct list *p,*q,*r;
      int i;
      printf("enter the value to inserted..\n");
      scanf("%d",&i);
      p=(struct list *)malloc(sizeof(struct list));
      p->info=i;
      p->next=NULL;
      r=*t;
      if(r==NULL)
          (*t)=p;
      else
         {
              while((r)!=NULL)
              {
                  q=(r);
                  r=r->next;
              }
              q->next=p;

         }


}

void display(struct list *t)
{
     struct list *d;
     printf("\nvalues of lists ...");
     if(t==NULL)
     {
       printf("\nthere are no items in the list..");
       return;
     }
     while(t!=NULL)
     {
        printf("%d  ",t->info);
        t=t->next;
     }
}
void reverse(struct list **r)
{
      struct list *p,*q,*s;
      if(*r==NULL)
      {
        printf("\n there is no  items in the list..");
      }
      else
      {

        q=(*r)->next;
        p=(*r);
        p->next=NULL;
        while(q!=NULL)
        {
           s=q;
           q=q->next;
           s->next=p;
           p=s;

        }
        //  t->next=NULL;
          *r=p;
      }
}
void concatenate(struct list *l,struct list1 *l1)
{
      struct list *q;
      q=l;
      while(q->next!=NULL)
      {
        q=q->next;
      }
      q->next=(struct list *)l1;
}
