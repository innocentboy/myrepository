#include<stdio.h>
#include<conio.h>
#define N 7
#define MAXSUM -99999999
int main()
{
    int a[N],maxsum=MAXSUM,si,csi=0,ei,cei,cmaxsum=0,i,j;
    printf("enter the value of array..\n");
    for(i=0;i<N;i++)
       scanf("%d",&a[i]);
    for(i=0;i<N;i++)
    {
         cei=i;
         cmaxsum+=a[cei];
         if(cmaxsum>maxsum)
         {
              maxsum=cmaxsum;
              si=csi;
              ei=cei;                  
                           
         }                
                    
         if(cmaxsum<0)
         {
              cmaxsum=0;
              csi=cei+1;             
         }           
    }   
    printf("\nprint the max subarray and the sum...\n");
    for(i=si;i<=ei;i++)
    {
           printf("%d  ",a[i]);
                              
    }
    printf("\n sum:%d",maxsum);
    
    getch();
}
