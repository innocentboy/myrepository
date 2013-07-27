#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 9999999
int n,time;
struct node
{
    char info[20];
    int count;
    struct node *next;
    struct edge *edge;       
};
struct edge
{ 
    struct node *node;
    struct edge *next;       
};
struct max_prt
{
    struct node *node;
    struct max_prt *next;           
};
void node_insert(struct node **);
void edge_insert(struct node **);
void display(struct node *);
void delete_node(struct node **);
void schedule(struct node *);
void topo_sort(struct node *);
struct node *extract(struct max_prt **start);
void insert(struct max_prt **start,struct node *pp);
int main()
{
  struct node *graph=NULL,*graph1=NULL; 
  struct edge *edge=NULL;
  int c;
  printf("enter the value of operation to be performed...\n");
  while(1)
  {
       printf("\nenter the value for menu selection..\n");
       printf("1.node insertion\n2.edge insertion\n3.display\n4.schedule\n5.Topological sorting.\n6.exit\n");   
       scanf("%d",&c);
       switch(c)
       {
          case 1:node_insert(&graph);
                 break;
          case 2:edge_insert(&graph);
                 break;
          case 3:display(graph);
                 break;
          case 4:schedule(graph);
                 break;
          case 5:topo_sort(graph);
                 break;                                                   
          case 6:exit(0);
       }
  }    
  getch();    
}
void node_insert(struct node **i)
{
     struct node *p,*q,*prev;
     q=*i;
     char info[20];
     printf("\n enter the info field of the node...\n");
     scanf("%s",info);
     n++;
     p=(struct node *)malloc(sizeof(struct node));
     strcpy(p->info,info);
     p->count=0;
     p->next=NULL;
     p->edge=NULL;
     if(q==NULL)
     {
        *i=p; 
        return;          
     }
     while(q!=NULL)
     {
         prev=q;
         q=q->next;          
     }
     prev->next=p;
}
void edge_insert(struct node **i)
{
      struct edge *p,*q,*prev;
      struct node *src_node,*dest_node,*t;
      char src[20],dest[20];
      printf("\nenter the value of nodes between which we have to insert the edge...\n");
      scanf("%s%s",src,dest);
      fflush(stdin);  
      t=*i;
      while(t!=NULL)
      {
          
          if(strcmp(t->info,src)==0)
             src_node=t;
          if(strcmp(t->info,dest)==0)                 
             dest_node=t;    
          t=t->next;    
      }
      printf("\nSource:%s  Destination:%s",src_node->info,dest_node->info);
      if(src_node==NULL||dest_node==NULL)
      {
         printf("\n problem..");                                
         return;                                   
      }
      p=(struct edge *)malloc(sizeof( struct edge));
      p->node=dest_node;
      p->next=NULL;
      dest_node->count++;
      if(src_node->edge==NULL)
         src_node->edge=p;
      else
      {
         q=src_node->edge; 
         while(q!=NULL)
         {
            prev=q;              
            q=q->next;           
         }    
         prev->next=p;
      }   
}
void display(struct node *t)
{
     struct node *p,*q;
     struct edge *ep,*eq;
     q=t;
     printf("\nno. of nodes present in the garph..:%d\n",n);
     printf("printf the value of info fields of the nodes of graph..\n");
     while(q!=NULL)
     {
                   printf("%s:%d ",q->info,q->count);
                   q=q->next;
     }
     printf("\nprint the edges of the graph with the information between which nodes that edge exits\n");
     q=t;
     while(q!=NULL)
     {
                   eq=q->edge;
                   while(eq!=NULL)
                   {
                      printf("\n edge exits between the node %s and %s:",q->info,(eq->node)->info);               
                      eq=eq->next;            
                   }
                   q=q->next;
     }
}
void schedule(struct node *nd)
{
     struct max_prt *out=NULL,*next_out=NULL,*r;
     struct node *p,*q;
     struct edge *ep,*eq;
     q=nd;
     while(q!=NULL)
     {
         if(q->count==0)
           insert(&out,q);
         q=q->next;                
     }
     while(out!=NULL)
     {
        time++;  
        r=out;         
        while(r!=NULL)
       {
             p=extract(&r);           
             printf("Time:%d  Schedule:%s\n",time,p->info);             
             ep=p->edge;
             while(ep!=NULL)
             {
                 (ep->node)->count--;
                 if((ep->node)->count==0)
                 {
                    insert(&next_out,(ep->node));                        
                 }               
                 eq=ep;
                 ep=ep->next;
                 //free(eq);
             }
             n=n-1;
             printf("\n%d  ",n);
             //free(p);       
       }
             out=next_out;
             next_out=NULL;
     }  
     if(n!=0) 
     {
       printf("\nerror!!! the graph contains a cycle..\n");
     }  
     else
     {
        //*nd=NULL;
        printf("\ngraph is dag.. in nature...\n");    
     }  
}
void topo_sort(struct node *nd)
{
     struct max_prt *out=NULL,*next_out=NULL,*r;
     struct node *p,*q;
     struct edge *ep,*eq;
     int c=1;
     q=nd;
     while(q!=NULL)
     {
         if(q->count==0)
           insert(&out,q);
         q=q->next;                
     }
     while(out!=NULL)
     {
       // time++;  
        r=out;         
        while(r!=NULL)
       {
             p=extract(&r);           
             printf("Time:%d  Schedule:%s\n",time,p->info);             
             ep=p->edge;
             while(ep!=NULL)
             {
                 (ep->node)->count--;
                 if((ep->node)->count==0)
                 {
                    insert(&next_out,(ep->node));                        
                 }               
                 eq=ep;
                 ep=ep->next;
                // free(eq);
             }
             c++;
             if(c>2)
             {
                time++;
                c=1;
             }    
             n=n-1;
             printf("\n%d  ",n);
            // free(p);       
       }
             out=next_out;
             next_out=NULL;
     }  
     if(n!=0) 
     {
       printf("\nerror!!! the graph contains a cycle..\n");
     }  
     else
     {
        //*nd=NULL;
        printf("\ngraph is dag.. in nature...\n");    
     }      
}
struct node *extract(struct max_prt **start)
{
     struct max_prt *p;
     p=*start;
     *start=((*start)->next);
     return p->node;
}
void insert(struct max_prt **start,struct node *pp)
{
     int i;  
     struct max_prt *p,*q=(*start),*r=NULL;
     p=(struct max_prt *)malloc(sizeof(struct max_prt));
     p->node=pp; 
     p->next=q;
     *start=p;
}

