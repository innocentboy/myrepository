/*
calculating the diameter of tree..
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define REP(i,n)   for(i=0;i<n;i++)
#define EVER          while(1)
#define true 1
#define false 0
#define  dbgi(x)  printf(#x" = %d\n",x);
#define  dbgll(x) printf(#x" = %ll\n",x);
#define gi(i)         scanf("%d",&i);
#define gll(i)        scanf("%lld",&i);
#define gd(i)         scanf("%f",&i);
#define gui(i)        scanf("%u",&i);
#define gull(i)       scanf("%ull",&i);
#define gs(s)         scanf("%s",s);
#define ps(s) printf("%s\n",s);
#define pi(i) printf("%d\n",i);
#define pll(i) printf("%ll\n",i);
#define pd(i)  printf("%f\n",i);
#define gdi(m,n) scanf("%d%d",&m,&n);
#define sl(s)  strlen(s)
#define mcl(buff) memset(buff,0,sizeof(buff));
#define mst(buff,val) memset(buff,val,sizeof(buff));
 
#define N 50010
 
typedef int I;
typedef long long int LL;
 
 
 
//typedef int qelmtyp;
struct Q
{   I items[N+1];
    int front,end;
};
typedef struct Q *Queue ;
 
int empty(Queue q)
{
    return (q->end==q->front)? 1:0;
}
void insert(Queue q,I elm)
{
    if(q->end==N)
      q->end=1;
    else
       (q->end)++;
    if(q->end==q->front){
       printf("q overflow");
       exit(1);
    }
    q->items[q->end]=elm;
}
 
I pop(Queue q)
{
    if(empty(q))
    {
       printf("q underflow");
       exit(1);
    }
    if(q->front==N)
     q->front=1;
    else
    q->front++;
   return q->items[q->front];
}
 
struct node
{   int i,d;
    struct node *next;
};
struct node *adj[N+1];
char visit[N+1];
I dist[N+1],n;
void push_back(int i,int j,int d)
{
    if(adj[i]==NULL)
    {
        adj[i]=(struct node *)malloc(sizeof(struct node));
        adj[i]->next=NULL;
        adj[i]->i=j;
        adj[i]->d=d;
    }
    else
    {
        struct node* tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->next=adj[i];
        tmp->i=j;
        tmp->d=d;
        adj[i]=tmp;
    }
}
 
int access(int i,int j)
{
    struct node* current;
 
    if(adj[i]==NULL)
      return 0;
    current=adj[i];
    while(current->next != NULL)
    {
        if(current->i==j)
         break;
        current=current->next;
    }
 
    return (current->i==j)? 1:0;
 
}
 
 
 
I bfs(I start)
{
    Queue q;
    q=(struct Q*)malloc(sizeof(struct Q ));
    q->front=q->end=n;
 
    I tmp,i;
    struct node* current;
    memset(dist,0,sizeof(int)*(n+1));
    memset(visit,0,sizeof(char)*(n+1));
 
    insert(q,start);
    visit[start]=1;
    while(!empty(q))
    {
        tmp=pop(q);
        //size=adjsize[tmp];
        for(current=adj[tmp];current != NULL;current=current->next)
          if(visit[current->i]==0)
          {
              dist[current->i]=dist[tmp]+current->d;
              visit[current->i]=1;
              insert(q,current->i);
          }
 
    }
    int max=1;
    FOR(i,2,n)
      if(dist[i]>dist[max])
       max=i;
 
  return max;
 
}
int main()
{
   I p,q,i,root,res,ans,l,t;
   //adj=(char**)malloc(sizeof(char)*(N+1)*(N+1));
    gi(t)
     while(t--){
       scanf("%d",&n);
       REP(i,n+1)
         adj[i]=NULL;
       FOR(i,1,n-1)
        {
            scanf("%d%d%d",&p,&q,&l);
            push_back(p,q,l);
            push_back(q,p,l);
            //dist[p]=dist[q]=l;
        }
 
        root=1;
        ans=bfs(root);
        res=bfs(ans);
        pi(dist[res])
 }
   return 0;
}
