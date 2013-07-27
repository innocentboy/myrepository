#include<stdio.h>
#define N 10000
int candy[N];
int main()
{
    int i,j,k,t,in,no_cdy,sum;
    float s=0;
   // scanf("%d",&t);
    while( scanf("%d",&no_cdy)&&no_cdy!=-1)
    {
       i=0;           
      // scanf("%d",&no_cdy);
       j=no_cdy;
       sum=0;         
       while(j-->0)
       { //printf("  %d",sum);
         scanf("%d",&k);          
         candy[i++]=k;            
         sum+=k;          
       }
       s=((float)sum)/no_cdy;j=no_cdy;k=0;
       //printf("\n%f %d ",s,(int)s);
       if(s==(int)s)
       {   i=0;
           while(j-->0)
           {   
             if(candy[i]<(int)s)
             {
               k+=((int)s-candy[i]);              
             }i++;             
           }       
           printf("%d\n",k);      
       }
       else
       printf("%d\n",-1);         
                
    }
    getch();
    return 0;    
}
