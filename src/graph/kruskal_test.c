#include<stdio.h>
#include<conio.h>
#include<time.h>
#define N 9
#define MAX 9999999
int father[N];
typedef struct forest_node_t {
    void* value;
    struct forest_node_t* parent;
    int rank;
} forest_node;
int graph[N][N]={
      0,9,0,4,2,0,0,0,0,
      9,0,10,0,8,0,0,0,0,
      0,10,0,0,7,5,0,0,0,
      4,0,0,0,3,0,18,0,0,
      2,8,7,3,0,6,11,12,15,
      0,0,5,0,6,0,0,0,16,
      0,0,0,18,11,0,0,14,0,
      0,0,0,0,12,0,14,0,20,
      0,0,0,0,15,16,0,20,0  
      };
/*int graph[N][N]={
    0,4,8,0,0,0,0,0,0,
    4,0,11,0,8,0,0,0,0,
    8,11,0,7,0,1,0,0,0,
    0,0,7,0,2,6,0,0,0,
    0,8,0,2,0,0,7,4,0,
    0,0,1,6,0,0,0,2,0,
    0,0,0,0,7,0,0,14,9,
    0,0,0,0,4,2,14,0,10,
    0,0,0,0,0,0,9,10,0,
    };*/
/*int graph[N][N]={
        0,10,5,0,0,
        0,0,2,0,1,
        0,3,0,2,9,
        7,0,0,0,6,
        0,0,0,4,0 };  */
/*int graph[N][N]={
        0,2,3,0,
        2,0,2,4,
        3,2,0,3,
        0,3,4,0         
                 }; */
struct list
{
   int source;
   int dest;     
   int weight;
   struct list *next;    
}; 
int empty();
struct list * extract(struct list **);
void min_spanning(int g[][N]);
void sort(int g[][],struct list **);
void union_set(int,int);
forest_node* MakeSet(void* value);
void Union(forest_node* node1, forest_node* node2);
forest_node* Find(forest_node* node);
int main()
{
    int i,j,k;
    clock_t t1,t2;
    printf("print the minimum spanning tree for the given graph.....\n");
    printf("\n***********************\n");
    printf("\n*******************\n");
    printf("\n*********************\n");
    printf("print the nodes between which these edges exits...\n");
     for(i=0;i<N;i++)
      father[i]=i;
    t1=clock();  
    min_spanning(graph);   
    t2=clock();     
    printf("\nno of ticks:%d  and  time:%f",(t2-t1),(float)(t2-t1)/CLK_TCK); 
    getch();    
}
void min_spanning(int g[][N]) 
{
     struct list *start=NULL,*p,*q;
     forest_node* node;
     int i,j;
     printf("\nsort the edges according to the weight of the edges..");
     sort(g,&start);
     q=start;
  /*   printf("\ndisplay the sorted edges..");
     while(q!=NULL)
     {
         printf("\npath exits between %d and %d : and it's weight:%d",q->source,q->dest,q->weight);
         q=q->next;         
     }  
     printf("\n*************\n");
     q=start; */
     for(i=0;i<N;i++)
        node=MakeSet(i);
     for(i=0;i<N;i++)
        traverse[i]=0;
     while(q!=NULL)
     {
           int n1,n2;        
           p=extract(&q);
           n1=p->source;
           n2=p->dest;
           if()
           {
                 printf("\npath exits between %d and %d : and it's weight:%d",p->source,p->dest,p->weight);
                 union_set(n1,n2);
           }               
     }   
     
}
forest_node* MakeSet(void* value) {
    forest_node* node = malloc(sizeof(forest_node));
    node->value = value;
    node->parent = NULL;
    node->rank = 0;
    return node;
}

void Union(forest_node* node1, forest_node* node2) {
    if (node1->rank > node2->rank) {
        node2->parent = node1;
    } else if (node2->rank > node1->rank) {
        node1->parent = node2;
    } else { /* they are equal */
        node2->parent = node1;
        node1->rank++;
    }
}

forest_node* Find(forest_node* node) {
    forest_node* temp;
    /* Find the root */
    forest_node* root = node;
    while (root->parent != NULL) {
        root = root->parent;
    }
    /* Update the parent pointers */
    while (node->parent != NULL) {
        temp = node->parent;
        node->parent = root;
        node = temp;
    }
    return root;
}

struct list * extract(struct list **s)
{
       struct list *p;
       p=*s;
       *s=(*s)->next;
       return p;
} 
void sort(int g[][N],struct list **s)
{
     int i,j,k;
     struct list *p,*q=*s,*r;
               for(i=0;i<N;i++)
               {
                  traverse[i]=1;             
                  for(j=0;j<N;j++)
                  {
                      if(traverse[j]!=1&&g[i][j])
                      {
                           p=(struct list *)malloc(sizeof(struct list));
                           p->source=i;
                           p->dest=j;
                           p->weight=g[i][j];
                           p->next=NULL;
                           q=*s;  
                           r=NULL;   
                           if(q==NULL)
                           {
                              *s=p;  
                               
                           }
                           else
                           { 
                               while(q!=NULL&&g[i][j]>(q->weight))
                               {
                                   r=q;
                                   q=q->next;                                  
                               }
                               if(q!=NULL)
                               {
                                  if(r==NULL)
                                  {
                                      p->next=q;
                                      *s=p;           
                                  }        
                                  else
                                  {
                                      p->next=r->next;
                                      r->next=p;    
                                  }   
                               }
                               else
                                  r->next=p;
                                  
                           }              
                      }                
                                  
                  }                
               }
}      
int empty()
{
     int i,f=1;
     for(i=0;i<N;i++)
     {
        if(traverse[i]==0)
        {
           f=0;
           break;                  
        }        
     }
     return f;    
    
}
                
