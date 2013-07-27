#include<stdio.h>
#define N 22
int a[27];
char str1[N],str2[N];
int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    while(t--)
    {
      k=0;        
      scanf("%s%s",str1,str2);
      for(i=0;i<27;i++)a[i]=0;
      for(i=0;i<strlen(str1);i++)
      a[str1[i]-'a']++;
      for(i=0;i<strlen(str2);i++)
      a[str2[i]-'a']--;k=1;
      for(i=0;i<27&&k;i++)
      {
        if(a[i]!=0){k=0;}                 
      } 
      if(k)printf("YES\n");
      else printf("NO\n");       
    }
    getch();
    return 0;
}
