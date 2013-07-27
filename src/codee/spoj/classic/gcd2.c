#include<stdio.h>
int gcd(int a, int b)
{
    if(a<b)a^=b^=a^=b;
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
char buf[250];
int main()
{
   int i,j,k=0,length,t,a;
   scanf("%d",&t);
   while(t-->0)
   { k=0;
     scanf("%d%s",&a,buf);
     if(a==0)
     {
        printf("%s\n",buf);
        continue;        
     }            
     for(i=0;i<strlen(buf);i++)
     {
        k=(k*10+(buf[i]-'0'))%a;                          
     }  //printf("%d  ",k);        
     printf("%d\n",gcd(a,k));          
   } 
   getch(); 
   return 0;    
}
