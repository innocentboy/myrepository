#include<stdio.h>
#include<math.h>
int main()
{
  int a1,a2,a3,d;
  float r=1,t=1;
  while(scanf("%d%d%d",&a1,&a2,&a3)&&(a1!=0||a2!=0||a3!=0))
  {
      d=(a2-a1);
      if(d==a3-a2)
      {
        printf("AP %d\n",a3+d);                  
      }
      else
      {
          t=(a3*(((float)a2)/a1));
          printf("GP %0.f\n",t);    
      }           
   }  
  getch();
  return 0;    
}
