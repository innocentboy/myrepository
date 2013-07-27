#include<stdio.h>
#include<conio.h>
int main()
{
      char s[100],t[100];
      char *ss,*tt;
      int k=0,i=-1;
      tt=t;
      ss=s;
      printf("enter the value of string\n");
      scanf("%s",ss);    
      while(*ss!='\0')
      {
             if(k==0)
             {
                 t[++i]=*ss;
                 //i++;
                 ss++;
                 k=1;           
             }        
             else
             {
                //printf("\n %s",s);
                if(t[i]==*ss)
                {
                     i--;
                     ss++;            
                }   
                 else
                 {
                    t[++i]=*ss;
                    //i++;
                    ss++;
                        
                 }
             } 
      } 
     // printf("\n%s",ss);
      t[++i]='\0';
      printf("\nthe value of string:%s",t);
      getch();
}
