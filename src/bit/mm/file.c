#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    char * buf;
    buf=strtok("my name ,sanjay pandey"," ");
   // printf(buf);
   while(buf)
   {
       printf("%s",buf);
       buf=strtok(buf," ");
                 
   }
    getch();
    
}
