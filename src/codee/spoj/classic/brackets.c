#include<stdio.h>
#define N 30009
char arr[N];
int M[4*N];
int f=1;
void initialize(int node, int b, int e)
{
      if (b == e)
      {
           if(arr[b]=='(') 
           M[node]=-1;
           else
           M[node]=1;
      }  
      else
      {
          initialize(node<<1,b,(b+e)>>1);
          initialize((node<<1)+1,((b+e)>>1)+1,e);
          M[node]=M[node<<1]+M[(node<<1)+1];
          if(M[node<<1]>M[(node<<1)+1])f=0;
      }    
}

int query(int node,int b,int e,int i,int j)
{
      int a,c;
      if (i > e || j < b)
      return 0;
      if (b >= i && e <= j)
      return M[node];
      return query(node<<1, b, (b + e)>>1,i,j)+query((node<<1)+ 1, ((b + e)>>1) + 1, e,i, j);
}

int modify(int node,int b,int e,int i)
{
      int x,y;
      if (i > e||i< b)
      {
          return M[node];
      }
      if (b==i&&e==i)
      {
        if(M[node]==-1)M[node]=1;
        else M[node]=-1;
        return M[node];
      }
      x=modify(node<<1, b, (b + e)>>1,i);y=modify((node<<1)+ 1, ((b + e)>>1) + 1, e,i);
      M[node]=x+y;
      if(x>y)f=0;
      return M[node];
}
int main()
{
    
    int i,j,k=0,t=10,n,m=1;
    while(t--)
   { 
       scanf("%d",&n);                                             
       scanf("%s",arr+1);
      // for(i=1;i<=n;i++)arr[i]=getche();
       initialize(1,1,n);
       scanf("%d",&k);
       printf("Test %d:\n",m++); 
       while(k--)
       {  
                 
          scanf("%d",&j);
          if(j==0)
          {
             if(M[1]==0&&f)     
             printf("YES\n");
             else
             printf("NO\n");
          }
          else
          {
            f=1;  
            modify(1,1,n,j);    
          }
       }                        
   }
    getch();
    return 0;    
}


