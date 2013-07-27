#include<stdio.h>
#include<conio.h>
int main()
{
   char s[]="",t[]="";
   int i=0,j=0,l=0;
   char *ss,*tt;
   ss=s;
   tt=t;
   printf("enter the value of string \n");
   scanf("%s",s);
   while(1)
   {
        tt=t;
        while(*tt!='\0')
        {
              if(*tt==*ss)
              i=1;  
              tt++;       
        }
        if(i==0)
        {
           *tt=*ss;
           tt++;
           *tt='\0';        
        }          
        else
            break;
        ss++;    
   }
   l=strlen(t);
   while(*ss!='\0')
   {
        if(*ss==t[j%l])
        {
            j++;
            ss++;               
        }        
        else
           break;        
                   
   }
   if((j%l)==0&&*ss=='\0')
      printf("\n string is true");
   else
      printf("\n string is false");
   getch();    
}
