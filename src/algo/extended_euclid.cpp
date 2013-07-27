#include<stdio.h>
#include<conio.h>
int gcd(int a,int b,int &x,int &y)
{
  if(a==0)
  {
    x=0;y=1;
    return b;        
  }
  int x1,y1,d;
  d=gcd(b%a,a,x1,y1); 
  x = y1 - (b / a) * x1;
  y = x1;   
  return d;  
}
int main(){
    
  int a,b,x=0,y=0,z;
  scanf("%d%d",&a,&b);
  z=gcd(a,b,x,y); 
  printf("\nx:%d y:%d gcd:%d",x,y,z); 
  getch();  
  return 0;     
}
