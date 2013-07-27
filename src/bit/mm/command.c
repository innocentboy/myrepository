#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define N 15
int main()
{
    FILE *fp,*fw;
    char *line,*line1;
    char *p,*g;
    char c;
    fp=fopen("C:\\Users\\Administrator\\Desktop\\abc.txt","r");
    fw=fopen("C:\\Users\\Administrator\\Desktop\\ab.txt","r");
    if(fp==NULL)
    {
                printf("file does not exits..");
                exit(1);            
    }
   
    {
           
            while(*p==*q&&(*p!='\0'&&*q!='\0'))
            {
                 p++;
                 q++;             
            }
                                                                    
                                                            
    }
    putc(c,fw);
    fclose(fw);
   // fclose(fp);
    getch();    
    
}
