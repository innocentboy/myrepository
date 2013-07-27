#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 9999999
int n,*distance,*traverse;
struct node
{
    int info;
    struct node *next;
    struct edge *edge;       
};
struct edge
{
    int weight;   
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
void delete_edge(struct node *);
void delete_node(struct node **);
void min_src_dest(struct node *);
void min_spanning(struct node *);
struct node *extract(struct max_prt **start);
void insert(struct max_prt **start,int weight,struct node *pp);
int main()
{
  struct node *graph=NULL; 
  struct edge *edge=NULL;
  int c;
  printf("enter the value of operation to be performed...\n");
  while(1)
  {
       printf("\nenter the value for menu selection..\n");
       printf("1.node insertion\n2.edge insertion\n3.display\n4.delete edge\n5.delete node\n6.minimum source to destination.\n7.minimum spanning tree...\n8.exit\n");   
       scanf("%d",&c);
       switch(c)
       {
          case 1:node_insert(&graph);
                 break;
          case 2:edge_insert(&graph);
                 break;
          case 3:display(graph);
                 break;
          case 4:delete_edge(graph);
                 break; 
          case 5:delete_node(&graph);
                 break; 
          case 6:min_src_dest(graph);
                 break;
          case 7:min_spanning(graph);
                 break;                                     
          case 8:exit(0);
       }
  }    
  getch();    
}
void node_insert(struct node **i)
{
     struct node *p,*q,*prev;
     q=*i;
     int info;
     printf("\n enter the info field of the node...\n");
     scanf("%d",&info);
     n++;
     p=(struct node *)malloc(sizeof(struct node));
     p->info=info;
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
      int src,dest,weight;
      printf("\nenter the value of nodes between which we have to insert the edge...\n");
      scanf("%d%d",&src,&dest); 
      fflush(stdin);
      printf("\n enter the weight of edge..");
      scanf("%d",&weight);
      t=*i;
      while(t!=NULL)
      {
                   
          if(t->info==src)
             src_node=t;
          if(t->info==dest)                 
             dest_node=t;    
          t=t->next;    
      }
      if(src_node==NULL||dest_node==NULL)
      {
         printf("\n problem..");                                
         return;                                   
      }
      p=(struct edge *)malloc(sizeof( struct edge));
      p->weight=weight;
      p->node=dest_node;
      p->next=NULL;
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
     printf("printf the value of info fields of the nodes of graph..\n");
     while(q!=NULL)
     {
                   printf("%d ",q->info);
                   q=q->next;
     }
     printf("\nprint the edges of the graph with the information between which nodes that edge exits\n");
     q=t;
     while(q!=NULL)
     {
                   eq=q->edge;
                   while(eq!=NULL)
                   {
                      printf("\n edge exits between the node %d and %d and it's weight is:%d",q->info,(eq->node)->info,eq->weight);               
                      eq=eq->next;            
                   }
                   q=q->next;
     }
}
void delete_edge(struct node *de)
{
      struct edge *p,*q,*prev;
      struct node *src_node,*dest_node,*t;
      int src,dest,k=1;
      printf("\nenter the value of nodes between which we have to delete the edge...\n");
      scanf("%d%d",&src,&dest); 
      t=de;
      while(t!=NULL)
      {
                   
          if(t->info==src)
             src_node=t;
          if(t->info==dest)                 
             dest_node=t;    
          t=t->next;    
      }
       if(src_node==NULL||dest_node==NULL)
      {
         printf("\n problem..");                                
         return;                                   
      }
      q=src_node->edge;
      
      while((q->node)!=dest_node)
      {
          prev=q;
          q=q->next;                       
      }
      if(q==src_node->edge)
      {
          src_node->edge=q->next;
          return;                     
      }
      prev->next=q->next;
     
}
void delete_node(struct node **dn)
{
     
}
void min_spanning(struct node *g)
{
     
}
void min_src_dest(struct node *g)
{
        struct node *p,*q;
        struct edge *x,*y;
        struct max_prt *start=NULL,*r;
        int min_distance,i=n,weight; 
        distance=(int *)calloc(n,sizeof(int));
        traverse=(int *)calloc(n,sizeof(int));
        while(i>0)
        {
             if(i==1)
             {
                *(distance+(i-1))=0;
             } 
             else    
                *(distance+(i-1))=MAX;
                *(traverse+(i-1))=0;
             i--;          
        }
        if(g==NULL)
        {
            printf("\n sorry there is no graph...");
            return;           
        }
        r=( struct max_prt *)malloc(sizeof(struct max_prt));
        r->node=g;
        r->next=NULL;
        start=r;
        while(start!=NULL)
        {
              p=extract(&start); 
              x=p->edge;
             *(traverse+(p->info))=1;
              while(x!=NULL)
              {     
                 if(*(distance+p->info)+(x->weight)<*(distance+(x->node)->info))
                 {
                     weight=*(distance+p->info)+(x->weight);
                     *(distance+(x->node)->info)=weight;                                                           
                     insert(&start,weight,x->node);                                                               
                 } 
                   
            /*     if(!(*(traverse+(x->node)->info))&&(x->weight)<*(distance+(x->node)->info))
                 {
                     weight=x->weight;
                     *(distance+(x->node)->info)=weight;                                                           
                     insert(&start,weight,x->node);                                                               
                 }  */
                 x=x->next;             
                            
              }  
        } 
        printf("\n print the minimum distance between source and other nodes....");
        i=n;
        while(i>0)
        {
           printf("\ndistance for node%d :%d",(i-1),*(distance+(i-1)));
           i--;          
                  
        }     
}
struct node *extract(struct max_prt **start)
{
     struct max_prt *p;
     p=*start;
     *start=((*start)->next);
     return p->node;
}
void insert(struct max_prt **start,int weight,struct node *pp)
{
     int i;  
     struct max_prt *p,*q=(*start),*r=NULL;
     p=(struct max_prt *)malloc(sizeof(struct max_prt));
     p->node=pp; 
     p->next=NULL;
     if(q==NULL)
     {
         *start=p;           
          return;       
     }
     while((q)!=NULL&&weight>*(distance+(q->node)->info))
     {
         r=q;                                                      
         q=q->next;                                     
     } 
     if(q!=NULL)
     {
            if(r==NULL)
            {
               p->next=q;
               *start=p;          
            }  
            else
            {  
               p->next=r->next;
               r->next=p;
            }       
     }
     else
     {
           r->next=p;
     } 
}
