#include<stdio.h>
#include<conio.h>
#define N 5
void subset(char *,char *,int);
int main()
{
   char in[N]="abcd";
   char s[N]="";
   int i=0;
   i=strlen(in);
   printf("%s",in);
   printf("\n %d",i-1);
   subset(s,in,0);    
   getch(); 
}

void subset(char *s,char *in,int i)
{
     if(strlen(in)!=i)
  {
     char *ss=s;
     char sss[N];
     strcpy(sss,s);
     if(i!=(strlen(in)-1))
     subset(sss,in,i+1);
     while(*ss!='\0')
       ss++;
     *(ss)=*(in+i);   
     ss++;
     *(ss)='\0';
     strcpy(sss,s);
     if(i!=(strlen(in)-1))
     subset(sss,in,i+1);
    
}  
    printf("\n%s",s);
  //printf("\n");     
     
}
