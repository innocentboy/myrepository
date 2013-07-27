#include<stdio.h>
#include<conio.h>
#define N 4
int main()
{
    int i,j,k,t=0;
    for(i=1;i<=N;i++)
    {
                     for(k=1;k<=N-i;k++)
                     {
                          printf("- ");
                                             
                     }
                     for(j=1;j<=2*i-1;j++)
                     {
                                  if(j<=i)
                                    printf("%d ",++t);
                                  else
                                     printf("%d ",--t);
                                                            
                     }
                                     printf("\n");
                                     t=0; 
    }    
    getch();
}
