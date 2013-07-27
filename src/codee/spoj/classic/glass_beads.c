#include<stdio.h>
#define N 10000
char necles[N];
int main()
{
  int i,j,k,in,t,min,length,min1,current;
  scanf("%d",&t);
  while(t-->0)
  {
     scanf("%s",necles);
     min=0;
     length=strlen(necles);
     for(i=1;i<length;i++)
     {
        if(necles[i]>necles[min]) continue;                  
        if(necles[i]<necles[min])
        {
           min=i;
        }
        else if(necles[i]==necles[min])
        {
            k=length;
            min1=min;
            current=i;
            while(k-->=0)
            {
               if(necles[current]==necles[min1])
               {  
                 current=(current+1)%length;
                 min1=(min1+1)%length;                               
                 continue;
               
               }           
               if(necles[current]<necles[min1])
               {
                  min=i;
                  break;                               
               }
               else break;
               //k--;             
            }i=current;        
        }                          
                                  
     }            
         printf("%d\n",min+1);           
   }  
  getch();  
  return 0;    
}
