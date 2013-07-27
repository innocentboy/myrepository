#include<stdio.h>
#include<conio.h>
#define N 4
int main()
{
       int i,j,k,t=0,s=0,x=0;
       for(i=0;i<N;i++)
       {
             s=65;
             for(j=0;j<N-i;j++)
             {
                  printf("%c",s);
                  s++;
                  t++;                   
             } 
             for(k=1;k<=2*i-1;k++)  
             {
                 printf(" ");
                 t++;
                                    
             } 
             if(i==0)
             {
                s--;        
             }
             if(x==0)
             {
                x=1;
                s--;        
             }  
             for(k=t;k<2*N-1;k++)
             {
                       printf("%c",s);
                       s--;              
             }           
                       printf("\n");
                        
                        t=0;
                        x=0;
       }    
    
    getch();
}
