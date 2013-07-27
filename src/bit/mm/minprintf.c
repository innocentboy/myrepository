#include<stdio.h>
#include<conio.h>
#include<stdarg.h>
int minprintf(char *format,...);
int main()
{
    int a=10,b=5;
    float c=6;
    printf("no of printed characters: %d",minprintf("print the values os a,b and c :%d %d %f %s",a,b,c,"this is minin printf"));
    getch();
    
}

int minprintf(char * format,...)
{
    char *p,*s;
    int i=0,in;
    double fl;
    va_list ap;
    p=format; 
    va_start(ap,format);
    for(;*p;p++)
    {
                if(*p!='%')
                {
                       putchar(*p);
                       i++;
                       continue;               
                }            
                switch(*(++p))
                 {
                   case 'd': in=va_arg(ap,int);
                             printf("%d",in);
                             i++;
                             break;
                   case 'f': fl=va_arg(ap,double); 
                              printf("%f",fl);
                              i++;
                              break;
                   case 's':for(s=va_arg(ap,char *);*s;s++)
                             {
                               putchar(*s);
                               i++;
                             }
                 }                    
    }    
    va_end(ap);
    return i;
}          

