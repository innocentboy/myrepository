#include<stdio.h>
#define N 100004
#define NUMNODES 2*N-1
#define BLANK -1
struct nodetype
{
   int info;      
   int lcount;
   int used;    
}node[NUMNODES];
int find(int k)
{
   int p,r;
   r=k;
   p=0;
   while(node[p].info==-1)
   {
      if(r<=node[p].lcount)
      p=p*2+1;
      else
      {
          
          r-=node[p].lcount;
          p=p*2+2;
      }                       
   }    
  return p;  
}
void delet(int p)
{
  int b,f,q;     
  if(p==0)
  node[p].used=0;
  else
  {
    f=(p-1)/2;
    if(p%2!=0)
    {
      b=2*f+2;          
      --node[f].lcount;       
    }   
    else
    b=2*f+1;
    if(node[b].info!=-1)
    {
      node[f].info=node[b].info;
      node[b].used=0;                    
    } 
    node[p].used=0;
    q=f;
    while(q!=0)
    {
      f=(q-1)/2;
      if(q%2!=0)
      {
          --node[f].lcount;
          b=2*f+2;         
      }
      else
      b=2*f+1;           
      if(!node[b].used&&node[q].info!=-1)
      {
         node[f].info=node[q].info;
         node[q].used=0;                                   
      }         
      q=f;
    }
  } 
}
void buildtree(int n)
{
     
  int d,f,i,p,power,size,j,k;
  d=0;     
   power=1;
   while(power<n)
   {
     ++d;
     power=power*2;
   }
   size=2*n-1;
   j=1;
   for(i=power-1;i<size;i++)
   {
      node[i].info=j++; 
      node[i].used=1;                       
   }  
   for(i=n-1,k=j;i<power-1;i++)
   {
       node[i].info=k++; 
       node[i].used=1;                       
   }
   for(i=0;i<n-1;i++)
   {
     node[i].used=1;
     node[i].lcount=0;
     node[i].info=-1;                  
   }
   for(i=n-1;i<size;i++)
   {
       p=i;
       while(p!=0)
       {
          f=(p-1)/2;
          if(p%2!=0)
          {
            ++node[f].lcount;          
          } 
          p=f;          
       }                     
   }
}
int follower(int size,int m,int *pk)
{
  int j,d;    
  *pk=((*pk+m-2)%size)+1;
  return find(*pk);  
}
int main()
{
  int i,j,k,n,t,p,size,m;
  scanf("%d",&t);
  while(t-->0)
  {
    scanf("%d",&n);          
    buildtree(n);
    k=1;m=0;
    for(size=n;size>1;size--)
    {
      p=follower(size,++m,&k);
      delet(p);                         
    }
    printf("%d\n",node[0].info);          
  }
  getch();
  return 0;    
}
