#include<stdio.h>
#define N 100005
char str[N];
int p[27];
long long n[N];
int main()
{
  int i,j,k,t,len;
  scanf("%d",&t);
  while(t--){            
  scanf("%s",str+1);
  len=strlen(str+1);
  for(i=0;i<27;i++)
  p[i]=0;
  n[0]=1;
  for(i=1;i<=len;i++)
  {
      n[i]=2*n[i-1]%3;
      if(p[str[i]-'A']>0)n[i]=(n[i]-n[p[str[i]-'A']-1])%3;
      p[str[i]-'A']=i;                  
  }
  printf("%lld\n",n[len]); 
} 
  getch();  
  return 0;    
}

