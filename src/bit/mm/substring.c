#include<stdio.h>
#include<conio.h>
int main()
{
   char s[]="",sub[]="\0";
   char *ss,*t;
   int i=0,j=0,l=0;
   ss=s;
  // t=sub;
   printf("***enter the value of string**\n");
   gets(s);
   while(*ss!='\0')
   {
         t=sub;
         j=0;
         while(*t!='\0')
         {
             if(*ss==*t)
             {
                j=1;
                break;          
             }
             t++;               
         }       
         if(j==0)
         {
            *t=*ss;
            t++;
            *t='\0';        
         }
         ss++;
                  
   }    
   printf("\n .....print the value of substring.... \n");
   printf("%s",sub);
   getch();
}
