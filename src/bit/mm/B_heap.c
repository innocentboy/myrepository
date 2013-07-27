#include<stdio.h>
#include<alloc.h>
#include<stdlib.h>
typedef struct bheap
{
       int key;
       int degree;
       struct bheap* prnt;
       struct bheap* child;
       struct bheap* sibling;       
}b_heap;
void b_link(b_heap *,b_heap *);
b_heap* b_heap_insert(b_heap *,b_heap *);
b_heap* b_heap_union(b_heap *,b_heap *);
b_heap* b_heap_min(b_heap *);
b_heap* b_heap_merge(b_heap *,b_heap *);
void  b_heap_traverse(b_heap *);
int main()
{
    b_heap *H=NULL,*x,*min;
    int n,i;
    printf("\nenter the no of elements to be inserted in heap..\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    { 
         x=(b_heap *)malloc(sizeof(b_heap));
         printf("\n enter the value of key..  ");
         scanf("%d",&x->key);
         H=b_heap_insert(H,x);
         printf("\n traversal of heap is...   ");
         b_heap_traverse(H); 
         printf("\n");
                     
    }
    //printf("find the minimum key...\n");
    min=b_heap_min(H);
    printf("\n minimum key value is: %d",min->key);
    getch();
    
}
b_heap* b_heap_union(b_heap *H1,b_heap *H2)
{
     b_heap *H=NULL,*x,*x_prev,*x_next;
     
      H=b_heap_merge(H1,H2);
       
     if(H==NULL)
     {
               return H;
     }     
     x_prev=NULL;
     x=H;
     x_next=x->sibling;
     while(x_next!=NULL)
     {
                 if((x->degree!=x_next->degree)||(x_next->sibling!=NULL&&(x->degree==x_next->sibling->degree)))
                 {
                        x_prev=x;
                        x=x_next;                                                                                
                                                                                                 
                 }    
                 else if(x->key<=x_next->key)
                      {
                         x->sibling=x_next->sibling;
                         b_link(x_next,x);                       
                      }                
                      else 
                           {
                                       if(x_prev==NULL)
                                       {
                                            H=x_next;
                                       }
                                       else
                                       {
                                            x_prev->sibling=x_next;
                                      
                                      }      
                                      b_link(x,x_next);
                                      x=x_next;
                           }
        x_next=x->sibling;
     }
     return H;
}

void b_link(b_heap *y,b_heap *z)
{
                   y->prnt=z;
                   y->sibling=z->child;
                   z->child=y;
                   z->degree=z->degree+1;     
}

b_heap* b_heap_merge(b_heap *H1,b_heap *H2)
{
     b_heap *H=NULL,*x;
     int k=0;
    
     while(H1!=NULL&&H2!=NULL)
     {
           if(H1->degree<=H2->degree)
           {
                  if(k==0)
                  {
                        H=H1;
                        x=H;
                        H1=H1->sibling; 
                       
                        k++;  
                  }
                  else
                  {
                       x->sibling=H1;
                       x=H1;
                       H1=H1->sibling;  
                       
                  }
                                            
           }
           else
           {
                    if(k==0)
                  {
                       H=H2;
                       x=H;
                       H2=H2->sibling;  
                      
                       k++;
                  }
                  else
                  {
                       x->sibling=H2;
                       x=H2;
                       H2=H2->sibling;
                        
                  }
               
               
           }
         
     }
     while(H1!=NULL)
     {
                  if(k==0)
                  {
                       H=H1;
                       x=H;
                       H1=H1->sibling; 
                      
                       k++;  
                  }
                  else
                  {
                      x->sibling=H1;
                      x=H1;
                      H1=H1->sibling;    
                  }
     }
     while(H2!=NULL)
     {
                  if(k==0)
                  {
                       H=H2;
                       x=H;
                       H2=H2->sibling; 
                       k++;  
                  }
                  else
                  {
                      x->sibling=H2;
                      x=H2;
                      H2=H2->sibling;    
                  }
     }  
      
     return H;   
}

b_heap* b_heap_min(b_heap *H)
{
                    b_heap *y,*x;
                    int min=2000000000;
                    x=H;
                    while(x!=NULL)
                    {
                          if(x->key<min)
                          {
                               min=x->key;
                               y=x;              
                          }       
                          x=x->sibling;       
                                  
                    }
                    return y;     
     
}

b_heap* b_heap_insert(b_heap *H,b_heap *x)
{
                     b_heap *h=NULL;
                     x->prnt=NULL;     
                     x->child=NULL;
                     x->sibling=NULL;
                     x->degree=0;
                     h=x;
                     
                     H=b_heap_union(H,h);
                     
                   
                     return H;
}

void b_heap_traverse(b_heap *x)
{
                     if(x!=NULL)
                     {
                           printf("%d  ",x->key);
                          
                           b_heap_traverse( x->child);
                           b_heap_traverse(x->sibling);              
                     }
                    
     
}
