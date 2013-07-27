#include<stdio.h>
#include<conio.h>
#define N 5
int main()
{
    int i,j,k,t=0,s=0,x=0;
    for(i=1;i<=N;i++)
    {
         for(k=1;k<=N-i;k++)
         {
            printf(" ");
            t++;
         } 
         s=65; 
         for(j=1;j<=2*i-1;)
         {
                           if(t<N)
                           {
                                printf("%c",s);
                                s=s+1;
                                t++;
                                j++;        
                           }
                           
                           else if(x==0)
                                {
                                   s=s-1;
                                   x=1;        
                                }
                              else{ 
                                s=s-1;
                                printf("%c",s);
                                j++;
                               }
         }      
           printf("\n");           
           t=0;
           x=0;          
    }    
    
    getch();
    
}
