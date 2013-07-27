#include<stdio.h>
int gcd(int a,int b)
{
   int i,j,k;
   if(a<b)
   {
     a^=b^=a^=b;       
   } 
   if(a%b!=0) return gcd(b,a%b);   
   else return b; 
}
int main()
{
   int a,b,c,at,bt,cnt1=0,cnt2=0,t,gd=0;    
   scanf("%d",&t);
   while(t-->0)
   {
      at=0;bt=0;cnt1=0;cnt2=0;         
      scanf("%d%d%d",&a,&b,&c);
      if(a==c||b==c)
      {
         printf("1\n"); 
         continue;             
      }
      gd=gcd(a,b);
      if(c%gd!=0||(c>a&&c>b))
      {
        printf("-1\n"); 
        continue;           
      }
   while(1)
   {
      if(at==0)
      {
         at=a;         
         cnt1+=1;      
      }
      else if(bt==b)
      {
        bt=0;
        cnt1+=1;     
      }    
      else
      {
        if(b-bt>=at)
        {
           bt=bt+at;cnt1+=1;at=0;            
           if(bt==c)
           {
              break;         
           }         
        }
        else
        {
          at=at-(b-bt);
          bt=b;cnt1+=1;     
          if(at==c)
          {
            break;         
                   
          }  
        }    
      } 
  } 
  a^=b^=a^=b;
  at=0;bt=0;
  while(1)
   {
      if(at==0)
      {
         at=a;         
         cnt2+=1;      
      }
      else if(bt==b)
      {
        bt=0;
        cnt2+=1;     
      }    
      else
      {
        if(b-bt>=at)
        {
           bt=bt+at;cnt2+=1;at=0;            
           if(bt==c)
           {
              break;         
           }         
        }
        else
        {
          at=at-(b-bt);
          bt=b;cnt2+=1;     
          if(at==c)
          {
            break;         
                   
          }  
        }    
      }
  } 
  if(cnt1<=cnt2)
  printf("%d\n",cnt1);
  else
  printf("%d\n",cnt2);        
} 
    getch();
    return 0;
}
