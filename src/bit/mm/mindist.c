#include<stdio.h>
#define N 15
int main()
{
          int a[N],b[N/2],i,j,n,c,d,e,t;
          printf("enter the value of no of elements in array..");
          scanf("%d",&n);
          printf("enetr the value of arrayu elements.."); 
          for(i=0;i<n;i++)   
          scanf("%d",&a[i]);
          printf("enetr the value between which the distance hava to find...");
          scanf("%d %d",&d,&e);
          j=0;
          for(i=0;i<n;i++)
          {
                   if(a[i]==d)
                   c=0;
                   if(a[i]==e)
                   {
                              b[j]=c-1;      
                              j++;       
                   }    
                   c++;                   
          }
          t=b[0];
          for(i=1;i<j;i++)
          {
                          if(t>b[i])
                          {
                                    t=b[i];          
                          }
                          
                          
          }
          printf("minimum, distance between the numbers is : %d",t);
          getch(0);
    
    
}

