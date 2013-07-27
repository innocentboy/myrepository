/*
  Name: Binomial Heap
  Author: Karthik Sharma CSE 3rd mmmec gkp
  Description: It is program of making Binomial Heap.
  			   finding Minimum key.
  			   display the B. Heap.

*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
struct node{
       struct node * parent;
       struct node * child;
       struct node * sibling;
       int key;
       int degree;
       
       };
typedef struct node Node;
Node * insert(Node*,int);
Node *binomial_h_u(Node *,Node *);
void binomial_l(Node *,Node *);
Node * binomial_m(Node *,Node *);
void traverse(Node*);
void traverse_t(Node*);
int  Binomial_min(Node *);
void Binomial_n_tree();
int count=0;
int total_node=0;
int p =0;

int main()
{
    int value,ch,i;
    Node *head=NULL;
    int min=0;
       
       
       printf("-----BINOMIAL HEAP-----\n");
       while(1){
       printf("\n\n1. INSERT ELEMENTS...");
       printf("\n2. FIND MINIMUM KEY...");
       printf("\n3. DISPLAY BINOMIAL HEAP")
       printf("\n4. QUIT");
	   printf("\n Enter your choice... ");
	   scanf("%d",&ch);

	   switch(ch){
	   		  case 1:
			     printf("Enter No. of elements ..");
			     scanf("%d",&i);
			    do{
     				 printf("\nEnter elements..");
      				 scanf("%d",&value);
     				 head= insert(head,value);
     				 total_node =++count;
	 			 p=0;
	 			printf("\n BINOMIAL HEAP.....");
     				 traverse(head);
      			      }while(--i);
      				 break;
  			 case 2:
			 	  if((min=Binomial_min(head))==9000)
					printf("\n Heap is empty");
			                   else
			 	  	  printf(" \nMINIMUM KEY. IS : [ %d ]",min);
				 	  break;
		 	  case 3:
			  	   total_node =count;
	 			   p=0;
		 	    	   printf("\n BINOMIAL HEAP.....");
		  	    	   if(head==NULL)
					printf("\n Heap is empty");
			  	   traverse(head);
				   break;
			   case 4: 
				 return(0);
			 default :
				 printf("\n   wrong choice..");
	 	  }
	   }
    
 }
    

Node * insert(Node *H,int value)
{
     Node *h1=(Node*)malloc(sizeof(Node));
     if(h1==NULL){
                 printf("NOT Enough space");
                 exit(0);
                 }
     h1->parent=NULL;
     h1->child=NULL;
     h1->sibling=NULL;
     h1->key=value;
     h1->degree=0;
     int i=h1->key;
     H=binomial_h_u(H,h1);
     return H;
     }
Node * binomial_h_u(Node * h1,Node * h2)
{
     Node * H=NULL;
     H=binomial_m(h1,h2);
      if(H==NULL)
     {
                return H;
                }
     Node * p_x=NULL;
     Node * x=H;
     Node * n_x=x->sibling;
     while(n_x!=NULL)
     {
                     if(x->degree!=n_x->degree||(n_x->sibling!=NULL&&n_x->sibling->degree==x->degree)){
                            p_x=x;
                            x=n_x;
                    }
                     else{
                          if(x->key<=n_x->key)
                          {
		          x->sibling=n_x->sibling;
                                              binomial_l(n_x,x);                                             
                          }
                           else
                          {
                                  if(p_x==NULL)
                                        H=n_x;
                                  else
                                 {
                                        p_x->sibling=n_x;
                                 }
                                binomial_l(x,n_x);
                                 x=n_x;
                          }
                          }
                          n_x=x->sibling;
                                                                                                      
                     }
	  return H;
    }
     
void binomial_l(Node * y,Node * z)
     {
          y->parent=z;
          y->sibling=z->child;
          z->child=y;
          z->degree+=1;
          }
Node *binomial_m(Node * h1,Node * h2)
     {
          Node *h=NULL;
          Node *x;
          while(h1!=NULL&&h2!=NULL)
          {
               if(h1->degree<=h2->degree)
               {                 if(h==NULL){  
                                   h=h1;
                                   x=h;
                                   h1=h1->sibling;
                                   }
                                   else
                                   {   
                                       x->sibling=h1;
                                       h1=h1->sibling;
                                       x=x->sibling;
                                       }
                                   
                                   }
                else{
                      if(h==NULL){  
                                   h=h2;
                                   x=h;
                                   h2=h2->sibling;
                                   }
                                   else
                                   {   
                                       x->sibling=h2;
                                       h2=h2->sibling;
                                       x=x->sibling;
                                       }
                                   
                     }                    
               }
               while(h1!=NULL)
               {
	  if(h==NULL){  
	                                   h=h1;
                  	                 x=h;
	                                   h1=h1->sibling;
                                   }
	          else{
                  	    x->sibling=h1;
	                      h1=h1->sibling;
                  	     x=x->sibling;       
		   }
      }
               while(h2!=NULL)
               {
	if(h==NULL){  
                                   h=h2;
                                   x=h;
                                   h2=h2->sibling;
                                   }
              else{
                       x->sibling=h2;
                       h2=h2->sibling;
                       x=x->sibling;       
	   }
	  }
                       return h;
   }                      
   
     void traverse(Node * r){
         if(r!=NULL){
	  	if(r->parent==NULL){
			  Binomial_n_tree();
			   }		  			  
                  	        printf("%d ",r->key);
	                         traverse(r->child);
	                         traverse(r->sibling);
                         }    
						       
	   }
   void Binomial_n_tree(){
   		int a=0;
   		while((a=(int)total_node%2)==0)
		 {		
			 total_node/=2;
			  p++;
		 }
		printf("\n B[ %d ] : ",(int)pow(2,p++)); 
		total_node/=2;  		
		   }

int Binomial_min(Node * H)
{
    int min=9000;
    Node * min_prev=NULL;
	while(H!=NULL)
	{
	  if(min>H->key)
	min=H->key;
	H=H->sibling;
	   }
    return min; 
}
