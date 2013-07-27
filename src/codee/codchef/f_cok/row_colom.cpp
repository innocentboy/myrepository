#include<cstdio>
#define N 314159
int r[N],c[N];
char s[20];

int main()
{

  int i,j,k,n,q,x;
  scanf("%d%d",&n,&q);
   for(i=0;i<n;i++)
  r[i]=c[i]=0;
  while(q--)
  {
      int b,x;
     scanf("%s%d%d",s,&b,&x);
     if(s[0]=='R')
     {
        // printf("%d%d\n",b,x);

         r[b-1]+=x;
         c[b-1]+=x;
     }
     else
     {
        // printf("zjnlkf\n");
         c[b-1]+=x;
         r[b-1]+=x;
      }
     /* if(s[0]=='R')
      r[b-1]+=x;
      else
      c[b-1]+=x;*/
   }
   int max1=-1;
   for(i=0;i<n;i++)
   {
       if(r[i]>max1)
       max1=r[i];
       if(c[i]>max1)
       max1=c[i];
    }
    printf("%d\n",max1);
  return 0;
}
