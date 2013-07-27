#include<stdio.h>
#include<conio.h>
union u
{
   char c[24];
   int i;
   float f;      
};
struct stack
{
   int c;
   union u value;
   struct stack *next;       
};
void push(struct stack **);
struct stack *pop(struct stack **);
void display(struct stack *);
int main()
{
     struct stack *s=NULL,*p;
     int choice;
     while(1)
      {
            printf("enter the value for the selection of menu items\n"); 
            printf("1.push\n2.pop\n3.display\n4.exit\n");
       //     printf("\n %d",sizeof(struct stack));
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:push(&s);      
                   break;
            case 2:p=pop(&s);
                   if(p!=NULL){
                      switch(p->c)
                      {
                         case 1:printf("\n%s ",p->value.c);
                                break;
                         case 2:printf("\n%d ",p->value.i);
                                break;
                         case 3:printf("\n%f ",p->value.f);
                                break;                          
                      }          
                             
                   }
                   break;
            case 3:display(s);
                   break;       
            case 4:exit(0);
            }              
       }            
         getch();
}
void push(struct stack **i)
{
      int c,value;
      struct stack *p;
      p=(struct stack *)malloc(sizeof(struct stack));
      printf("\nenter the choice you want to insert in the stack...\n");
      printf("1.char\n2.integer\n3.float\n");
      scanf("%d",&c);
      p->c=c;
      switch(c)
      {
        case 1:printf("\n enter the char value");
              // gets((p->value.c));
               scanf("%s",p->value.c);
               break;         
        case 2:printf("\n enter the int value\n");
               scanf("%d",&(p->value).i);
               break;         
        case 3:printf("\n enter the float value\n");
               scanf("%f",&(p->value).f);
               break;         
      }   
      p->next=*i;
      *i=p; 
      fflush(stdin);
}
struct stack* pop(struct stack **s)
{
       
       struct stack *p;
       if(*s==NULL)
       return NULL;
       p=*s;
       *s=(*s)->next;
       return p;
}
void display(struct stack *t)
{
   printf("\n");
   while(t!=NULL)
   {
      switch((t)->c)
      {
        case 1:
               puts((t)->value.c);
               break;         
        case 2:
               printf("  %d",(t)->value.i);
               break;         
        case 3:
               printf("  %f",(t)->value.f);
               break;         
      }      
      t=(t)->next;
   }     
     
}

