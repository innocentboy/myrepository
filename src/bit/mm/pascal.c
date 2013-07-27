#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#define N 5 
int main()
{
    int i,j,k,s;
    int *a,*b;
    printf("1 \n");
    printf("1 2 1 \n");
   // a=(int *)alloc(3*sizeof(int));
    s=3;
    for(i=2;i<N;i++)
      {
                    printf("1 ");
                  //  b=(int *)alloc((i+2)*sizeof(int));
                    *b=1;
                    b++;
                    for(k=0;k<s-1;k++)
                    {
                              printf("%d ",(*(a+k))+(*(a+k+1)));
                              *b=(*(a+k))+(*(a+k+1));
                              b++;                          
                    }              
                    s=2+i;
                    printf("1");
                    (*b)=1;
                    b++;
                    free(a);
                    b=a;                     
                    
      }    
    
    
}
