#include<stdio.h>
#include<string.h>
#include<conio.h>
#define N 1000009
char str[N];
int prefix[N];
int main()
{
    
  int i,j=1,k,n,t,len;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&len);        
    scanf("%s",str+1);         
    //len=strlen(str+1);
    prefix[1]=0;k=0;
    for(i=2;i<=len;i++)
    {
      while(k>0&&str[k+1]!=str[i])k=prefix[k];
      if(str[k+1]==str[i])++k;
      prefix[i]=k;                   
    }
    printf("Test Case #%d\n",j++);
    for(i=2;i<=len;i++)
    {
        k=i-prefix[i];
        if(k!=0&&i%k==0)printf("%d %d\n",i,i/k);
        prefix[i]=0;               
    }         
  }  
  getch();  
  return 0;    
}
