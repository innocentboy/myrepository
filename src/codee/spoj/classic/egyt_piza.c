#include<stdio.h>
char c[3];
int main()
{
   int i,j,k=0,t=0,n1=0,n2=0,n3=0;
   float in,f1=0,f2=0;
   scanf("%d",&t);
   //printf("%d  %d\n",t,ceil(1.1));
   while(t-->0)
   {
      scanf("%s",c);
      in=((float)(c[0]-'0'))/(c[2]-'0');         
      //scanf("%f",&in);    
      if(in==.25)n1++;  
      else if(in==.5)n2++;
      else n3++;//printf("t:%d",t);
   }//printf("n1:%d n2:%d n3:%d\n",n1,n2,n3);
   t=0;
   t+=n3;
   if(n1>n3)
   {
     if(n2%2==0)
     {     k=0;  
          j=n1-n3;
          do
          {
            k++;
            j=j/4;         
          }while(j%4!=0);
          t+=k;
     }       
     else if((n1-n3)>2)
     {   k=0;
         j=((n1-n3-2));
       //  f2=((n1-n3));
         do
          {
            k++;
            j=j/4;         
          }while(j%4!=0);
          t+=k;
    
     }   
     else f1=0;           
   }
   t+=(int)((n2+1)/2);
   printf("%d\n",t+1);
   getch(); 
   return 0;    
}
