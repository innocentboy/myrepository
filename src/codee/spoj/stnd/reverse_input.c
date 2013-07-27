#include<stdio.h>
#define N 1000000
char in[N];
char str[1024];
int main()
{
   int i,j,k,t,no,length;
  // FILE *fp=fopen("stdout","a");
   scanf("%d",&no);
   scanf("%s",in);
   length=strlen(in)-1;
   while(length>=0)
   {
      i=0;
      while(in[length]!=' ')
      str[i++]=in[length--];
      str[i++]=' ';
      str[i]='\0';
      k=no;
      while(k-->0)
     {
        fwrite(str,strlen(str),1,stdout);            
     }                
                    
   }    
   getch(); 
   return 0;    
}
