#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,k=0,x=0;
    char s[]="abcadabcadabcadabcad";
    for(i=1;i<strlen(s);i++)
    {
           if(s[k]==s[i])
           {
                k++;
                if(x==0)
                {
                   j=i;
                   x=1;        
                }
                continue;              
           }             
           else
            {
                 if(k>0)
                   i--;        
                 x=0;
                 k=0;
                 j=0;
                    
            }           
      }
      if(k>0&&(strlen(s)%(j)==0))
          printf("\nstring is true");
      else
          printf("\n string is false..");        
      getch();
}
