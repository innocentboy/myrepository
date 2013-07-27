#include<stdio.h>
int main()
{
   int i,j,k,t,x,y;
   scanf("%d",&t);
   while(t--)
   {
     scanf("%d %d",&x,&y);
     if(x>=y&&x%2==0&&y%2==0)printf("%d\n",x+y);
     else if(x>=y&&x%2!=0&&y%2!=0)printf("%d\n",(x+y)-1);
     else printf("No Number\n");          
   } 
   getch(); 
   return 0;    
}
